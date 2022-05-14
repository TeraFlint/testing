export module p3.testing.performance_test;

import p3.testing.core;

/*
	test class for profiling procedures.
	will repeat the task a lot and measure the execution time.

	struct foo : performance_test<foo> {...};
*/

namespace p3::testing
{
	export
	template <typename crtp_type, bool enabled = true>
	struct performance_test : basic_test<crtp_type, enabled>
	{
		virtual void run_test() const = 0;
	};
}