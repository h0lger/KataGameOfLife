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
	gPtr->GetCells()[4][5].SetAlive();
	gPtr->GetCells()[5][4].SetAlive();
	gPtr->GetCells()[5][5].SetAlive();
	return gPtr;
}
