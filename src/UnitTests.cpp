#include "UnitTests.h"
#include "Grid.h"

bool UnitTest_1()
{
	Grid *gPtr = new Grid();
	cout << (Grid)*gPtr;
	return true;
}