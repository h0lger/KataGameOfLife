#include "Utils.h"
#include <unistd.h>

static unsigned short GetGenerations()
{
	unsigned short n = 0;	
	//Simple validation
	while (n < 2 || n > 100)
	{		
		cout << "\nEnter number of generations (2-100):";
		cin >> n;
	}
	return n;
}

//Iterate generations
void IterateGens(Grid *gPtr, unsigned short n)
{
	//Iterate for n generations
	for (size_t i = 0; i < n; i++)
	{
		cout << "\033[2J\033[1;1H"; //clear screen
		cout << *gPtr;
		cout << "\n[" << (i + 1) << " / " << n << " generation]";
		usleep(ANIMATION_SPEED);
		//_sleep(ANIMATION_SPEED); //sleep to create animation effect
		gPtr->NextGeneration();
	}

	cout << "\nFinished.\n";
}

//Run main menu
void Menu()
{
	char inpC = 'a'; //dummy init
	char exitChar[1];
	exitChar[0] = 'x';
	unsigned short n = 0; //number of generations
	Grid *gPtr = NULL;

	while (inpC != exitChar[0])
	{
		cout << "-= Game of Life =-\n\n";
		cout << "Choose the start position of the cells for you game:\n";
		cout << "1. Simple\n";
		cout << "2. Blinker\n";
		cout << "3. Glider\n";
		cout << "x. Exit\n";
		cin >> inpC;
		cout << "\033[2J\033[1;1H"; //clear screen

		switch (inpC)
		{
		case '1':
			cout << "Running simple start position...\n\n";			
			gPtr = GetSimple();
			n = GetGenerations();
			IterateGens(gPtr, n);
			break;
		case '2':
			cout << "Running blinker start position...\n\n";			
			gPtr = GetBlinker();
			n = GetGenerations();
			IterateGens(gPtr, n);
			break;
		case '3':
			cout << "Running glider start position...\n\n";			
			gPtr = GetGlider();
			n = GetGenerations();
			IterateGens(gPtr, n);
			break;
		default:
			cout << "Invalid choice\n\n";
			break;
		}		
		//delete gPtr;
	}
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


