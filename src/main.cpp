#include "Utils.h"
#include "UnitTests.h"

int main()
{
	//First run the unit tests (it's so fast)
	UnitTest_NextGen_Blinker();
	UnitTest_NextGen_Glider();

	Menu(); //show main menu	

	return 0;
}