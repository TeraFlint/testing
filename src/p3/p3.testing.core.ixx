export module p3.testing.core;

import <stdexcept>;
import <vector>;
import <memory>;
import <map>;

/*
	Exceptions and other stuff all the submodules require
*/

namespace p3::testing
{
#pragma region exceptions and type aliases

	export
	class assertion_fail : public std::exception
	{
		using std::exception::exception;
	};

	export
	class incomplete_test : public std::exception
	{
		using std::exception::exception;
	};

	export
	using split_key_type = std::vector<std::string>;

	export
	using combined_key_type = std::string;

#pragma endregion
#pragma region core mechanism

	export
	struct any_test
	{
		constexpr virtual void run_test() const = 0;
	};

	export
	using test_ptr = std::unique_ptr<any_test>;

	export
	struct any_factory
	{
		constexpr virtual test_ptr create() const = 0;
	};

	export
	using factory_ptr = std::unique_ptr<any_factory>;

	template <typename test_type>
	struct factory : any_factory
	{
		const combined_key_type name;
		const split_key_type hierarchy;

		constexpr factory(combined_key_type &&name)
			: name{ name }, hierarchy{/* hierarchy::split_scope(name) */}
		{
		}

		constexpr test_ptr create() const override
		{
			return std::make_unique<test_type>();
		}
	};

	export
	std::map<split_key_type, factory_ptr> &factory_collector()
	{
		// this map is supposed to be accessed before the actual main() program runs.
		// depending on the evaluation time, the map won't be initialized, yet.
		// by enforcing the initialization point with a function call we can guarantee the validity of the container whenever it's getting used.
		static std::map<split_key_type, factory_ptr> collector = {};
		return collector;
	}

	template <typename test_type>
	struct factory_inserter
	{
		constexpr factory_inserter()
		{
			// const auto name = shortened_typename<test_type>();
			// const auto hierarchy = hierarchy::split_scope(name);

			// todo: fancy printing

			// factory_collector()[hierarchy] = std::make_unique<factory<test_type>>(name);
		}
	};

	export
	template <typename active_test_type, bool enabled = true>
	struct basic_test : any_test
	{
	private:
		// this is the hack. by adding a static factory_inserter to a test case, we can use the following line to invoke the registration of a test.
		static inline factory_inserter<active_test_type> s_inserter{};
	};

	export
	template <typename inactive_test_type>
	struct basic_test<inactive_test_type, false>
	{
		// passing false allows us to also deactivate a test with pure c++ means.
		// no need to wrap it into a preprocessor block
	};

#pragma endregion
}