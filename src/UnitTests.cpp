#include "UnitTests.h"
#include "Grid.h"
#include "Utils.h"
#include <assert.h>
#include "GfxWrapper.h"


bool UnitTest_Print()
{
	Grid *gPtr = GetSimple();
	GfxWrapper wrapper = GfxWrapper();
	wrapper.Render(gPtr, 0, Simple);

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

bool UnitTest_sfml(int argc, char *argv[])
{
	GfxWrapper wrapper = GfxWrapper();
	wrapper.TestRenderGfx();

	return true;
}