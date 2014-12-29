#include "Utils.h"
#include "UnitTests.h"

int main(int argc, char *argv[])
{
	//First run the unit tests (it's so fast)
	UnitTest_NextGen_Blinker();
	UnitTest_NextGen_Glider();

	Menu(); //show main menu
	
	//UnitTest_Print();
	

	return 0;
}