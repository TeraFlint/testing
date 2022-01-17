export module p3.testing.performance_test;

/*
	test class for profiling procedures.
	will repeat the task a lot and measure the execution time.

	struct foo : performance_test<foo> {...};
*/

namespace p3
{
	namespace testing
	{
		export
		template <typename crtp_type, bool enabled = true>
		struct performance_test
		{
			virtual void run_test() const = 0;
		};
	}
}