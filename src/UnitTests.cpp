#include "UnitTests.h"
#include "Grid.h"
#include <assert.h>

bool UnitTest_Print()
{
	Grid *gPtr = GetStartGrid();
	cout << *gPtr;	

	delete gPtr;
	return true;
}

bool UnitTest_NextGen()
{
	Grid *gPtr = GetStartGrid();	

	for (size_t i = 0; i < 5; i++)
	{
		cout << *gPtr;
		_sleep(500);
		gPtr->NextGeneration();
		system("CLS");		
	}

	return true;
}

Grid *GetStartGrid()
{
	Grid *gPtr = new Grid();
	//TODO: Make random
	gPtr->GetCells()[1][4].SetAlive();
	gPtr->GetCells()[2][3].SetAlive();
	gPtr->GetCells()[2][4].SetAlive();
	return gPtr;
}
