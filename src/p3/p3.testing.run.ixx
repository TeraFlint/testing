module;
#include <iostream>

export module p3.testing.run;

import p3.testing.core; // factory_collector()
import p3.testing.unit_test;
import p3.testing.property_test;
import p3.testing.performance_test;

/*
	test execution, evaluation, result saving
*/

namespace p3::testing
{
	export
	template <typename map_type>
	constexpr void run(map_type &&factory_pointer_map) noexcept
	{
		std::cout << "p3::testing::run(map)" << std::endl;

		for (const auto &[hierarchy, factory] : factory_pointer_map)
		{
			// todo
		}
	}

	export
	auto run() noexcept
	{
		return run(factory_collector());
	}
}