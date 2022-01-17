export module p3.testing.main;

/*
	I know, providing a main in a library repository is not the best idea.
	I'll probably remove this and provide it as an example or put it into en external testing_test project. 
*/

import p3.testing.run;

export int main(int argc, char** argv)
{
	p3::testing::run();
}