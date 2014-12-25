#include <iostream>
#include "Grid.h"
#include "UnitTests.h"
using namespace std;

void Menu()
{
	char inpC = 'a'; //dummy init
	char exitChar[1];
	exitChar[0] = 'x';

	while (inpC != exitChar[0])
	{
		cout << "-= Game of Life =-\n\n";
		cout << "Choose the start position of the cells for you game:\n";
		cout << "1. Simple\n";
		cout << "2. Blinker\n";
		cout << "3. Glider\n";
		cout << "x. Exit\n";
		cin >> inpC;
		system("CLS"); //clear screen

		switch (inpC)
		{
		case '1':
			cout << "Running simple start position..\n\n";
			break;
		case '2':
			cout << "Running blinker start position..\n\n";
				break;
		case '3':
			cout << "Running glider start position..\n\n";
				break;
		default:
			break;
		}

		cout << "Finished.\n\n";
	}
}

int main()
{
	//First run the unit tests (it's so fast)
	UnitTest_NextGen_Blinker();
	UnitTest_NextGen_Glider();

	Menu();
	return 0;
}



