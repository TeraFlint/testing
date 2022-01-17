module;
#include <iostream>

export module p3.testing.run;

export import p3.testing.unit_test;
export import p3.testing.property_test;
export import p3.testing.performance_test;

/*
	test execution, evaluation, result saving
*/

namespace p3
{
	namespace testing
	{
		export
		void run() noexcept
		{
			std::cout << "p3::testing::run()" << std::endl;
			// todo
		}
	}
}