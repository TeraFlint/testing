export module p3.testing.unit_test;

import p3.testing.core;

/*
	single tests to check hand-written cases.

	struct foo : unit_test<foo> {...};
*/


namespace p3
{
	namespace testing
	{
		export
		template <typename crtp_type, bool enabled = true>
		struct unit_test
		{
			virtual void run_test() const = 0;
		};
	}
}