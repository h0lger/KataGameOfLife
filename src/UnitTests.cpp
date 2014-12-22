#include "UnitTests.h"
#include "Grid.h"
#include <assert.h>

bool UnitTest_Print()
{
	Grid *gPtr = GetSimple();
	cout << *gPtr;	

	delete gPtr;
	return true;
}

bool UnitTest_NextGen()
{
	Grid *gPtr = GetGlider();
	
	assert(gPtr->GetCells()[0][1].IsAlive() == true);
	assert(gPtr->GetCells()[1][2].IsAlive() == true);
	assert(gPtr->GetCells()[2][0].IsAlive() == true);
	assert(gPtr->GetCells()[2][1].IsAlive() == true);
	assert(gPtr->GetCells()[2][2].IsAlive() == true);	

	for (size_t i = 0; i < 4; i++)
	{		
		gPtr->NextGeneration();
		switch (i)
		{
		case 0 :
			/*
				....
				*.*.
				.**.
				.*..
			*/

			assert(gPtr->GetCells()[1][0].IsAlive() == true);
			assert(gPtr->GetCells()[1][2].IsAlive() == true);
			assert(gPtr->GetCells()[2][1].IsAlive() == true);
			assert(gPtr->GetCells()[2][2].IsAlive() == true);
			assert(gPtr->GetCells()[3][1].IsAlive() == true);

			break;
		case 1:
			/*
				....
				..*.
				*.*.
				.**.
			*/

			assert(gPtr->GetCells()[1][2].IsAlive() == true);
			assert(gPtr->GetCells()[2][0].IsAlive() == true);
			assert(gPtr->GetCells()[2][2].IsAlive() == true);
			assert(gPtr->GetCells()[3][1].IsAlive() == true);
			assert(gPtr->GetCells()[3][2].IsAlive() == true);
			break;
		case 2:
			/*
				....
				.*..
				..**
				.**.
			*/

			assert(gPtr->GetCells()[1][1].IsAlive() == true);
			assert(gPtr->GetCells()[2][2].IsAlive() == true);
			assert(gPtr->GetCells()[2][3].IsAlive() == true);
			assert(gPtr->GetCells()[3][1].IsAlive() == true);
			assert(gPtr->GetCells()[3][2].IsAlive() == true);
			break;
		case 3:
			/*
				....
				..*.
				...*
				.***
			*/

			assert(gPtr->GetCells()[1][2].IsAlive() == true);
			assert(gPtr->GetCells()[2][3].IsAlive() == true);
			assert(gPtr->GetCells()[3][1].IsAlive() == true);
			assert(gPtr->GetCells()[3][2].IsAlive() == true);
			assert(gPtr->GetCells()[3][3].IsAlive() == true);
			break;


		default:
			break;
		}		
	}

	return true;
}

Grid *GetGlider()
{
	/*
	 .*..
	 ..*.
	 ***.
	 ....
	*/
	Grid *gPtr = new Grid();
	
	gPtr->GetCells()[0][1].SetAlive();
	gPtr->GetCells()[1][2].SetAlive();
	gPtr->GetCells()[2][0].SetAlive();
	gPtr->GetCells()[2][1].SetAlive();
	gPtr->GetCells()[2][2].SetAlive();
	
	return gPtr;
}

Grid *GetSimple()
{
	/*
	.*..
	..*.
	***.
	....
	*/
	Grid *gPtr = new Grid();	
	gPtr->GetCells()[1][4].SetAlive();
	gPtr->GetCells()[2][3].SetAlive();
	gPtr->GetCells()[2][4].SetAlive();
	
	return gPtr;
}
