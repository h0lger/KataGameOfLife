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

bool UnitTest_NextGen_Glider()
{
	Grid *gPtr = GetGlider();
	
	//Validate start pos
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

	delete gPtr;

	return true;
}

bool UnitTest_NextGen_Blinker()
{
	Grid *gPtr = GetBlinker();

	//Validate start pos
	assert(gPtr->GetCells()[0][1].IsAlive() == true);
	assert(gPtr->GetCells()[1][1].IsAlive() == true);
	assert(gPtr->GetCells()[2][1].IsAlive() == true);

	for (size_t i = 0; i < 2; i++)
	{
		gPtr->NextGeneration();
		switch (i)
		{
		case 0:
			/*
				....
				***.
				....
				....
			*/
			assert(gPtr->GetCells()[1][0].IsAlive() == true);
			assert(gPtr->GetCells()[1][1].IsAlive() == true);
			assert(gPtr->GetCells()[1][2].IsAlive() == true);
			break;
		case 1:
			/*
				.*..
				.*..
				.*..
				....
			*/
			assert(gPtr->GetCells()[0][1].IsAlive() == true);
			assert(gPtr->GetCells()[1][1].IsAlive() == true);
			assert(gPtr->GetCells()[2][1].IsAlive() == true);
			break;

		default:
			break;
		}

	}

	delete gPtr;

	return true;	
}

//Get glider start pos
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

//Get blinker start pos
Grid *GetBlinker()
{
	/*
		.*..
		.*..
		.*..
		....
	*/

	Grid *gPtr = new Grid();
	gPtr->GetCells()[0][1].SetAlive();
	gPtr->GetCells()[1][1].SetAlive();
	gPtr->GetCells()[2][1].SetAlive();

	return gPtr;
}

//Get simple cell start pos
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
