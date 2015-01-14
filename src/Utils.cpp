#include "Utils.h"
#include <unistd.h>
#include "GfxWrapper.h"

static unsigned short GetGenerations()
{
	unsigned short n = 0;	
	//Simple validation
	while (n < 2 || n > 500)
	{		
		cout << "\nEnter number of generations (2-500):";
		cin >> n;
	}
	return n;
}

//Run main menu
void Menu()
{
	char inpC = 'a'; //dummy init
	char exitChar[1];
	exitChar[0] = 'x';
	unsigned short n = 0; //number of generations
	Grid *gPtr = NULL;
	GfxWrapper wrapper = GfxWrapper();

	while (inpC != exitChar[0])
	{
		cout << "-= Game of Life =-\n\n";
		cout << "Choose the start position of the cells for you game:\n";
		cout << "1. Simple (simple render)\n";
		cout << "2. Blinker (simple render)\n";
		cout << "3. Glider (simple render)\n";
		cout << "4. Simple (texture render)\n";
		cout << "5. Blinker (texture render)\n";
		cout << "6. Glider (texture render)\n";
		cout << "x. Exit\n";
		cin >> inpC;
		ClearTerminal();

		switch (inpC)
		{
		case '1':
			cout << "Running simple start position...\n\n";			
			gPtr = GetSimple();
			n = GetGenerations();
			wrapper.Render(gPtr, n, Simple);
			break;
		case '4':
			cout << "Running simple start position...\n\n";			
			gPtr = GetSimple();
			n = GetGenerations();
			wrapper.Render(gPtr, n, Texture);
			break;
		case '2':
			cout << "Running blinker start position...\n\n";			
			gPtr = GetBlinker();
			n = GetGenerations();
			wrapper.Render(gPtr, n, Simple);
			break;
		case '5':
			cout << "Running blinker start position...\n\n";			
			gPtr = GetBlinker();
			n = GetGenerations();
			wrapper.Render(gPtr, n, Texture);
			break;
		case '3':
			cout << "Running glider start position...\n\n";			
			gPtr = GetGlider();
			n = GetGenerations();
			wrapper.Render(gPtr, n, 20, Simple);
			break;
		case '6':
			cout << "Running glider start position...\n\n";			
			gPtr = GetGlider();
			n = GetGenerations();
			wrapper.Render(gPtr, n, 20, Texture);
			break;
		case 'x':
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice\n\n";
			break;
		}		
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

void ClearTerminal()
{
	//Fix for clearing terminal (work's pretty well)
	cout << "\033[2J\033[1;1H";
}


