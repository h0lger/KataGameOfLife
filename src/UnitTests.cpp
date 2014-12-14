#include "UnitTests.h"
#include "Grid.h"
#include <assert.h>

bool UnitTest_Print()
{
	Grid *gPtr = new Grid();
	cout << *gPtr;
	_sleep(1000);
	gPtr->NextGeneration();
	system("CLS");
	cout << *gPtr;

	return true;
}
