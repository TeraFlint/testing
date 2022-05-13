module;
#include <tuple>

export module p3.testing.property_test;

import p3.testing.core;

/*
	automated testing of behavior with randomized inputs.

	struct foo : testing<foo, true, std::vector<int>> {...};
	^ defines a test which will receive an int vector as input data.
*/

namespace p3::testing
{
	export
	template <typename crtp_type, bool enabled = true, typename ...par_types>
	struct property_test
	{
		virtual void run_test(const par_types &...par) = 0;
		virtual std::tuple<par_types...> generate_parameters() = 0;
	};
}