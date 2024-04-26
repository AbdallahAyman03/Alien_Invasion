// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"data_structure/Game.h"
using namespace std;
int main()
{
	ifstream file;
	string fileName;
	bool ModeSilent;
	char mode='h';
	int number;
	do
	{
		cout << "Which mode you want?\n";
		cout << "A) Silent\nB) Interactive\n";
		cin >> mode;
	} while ( tolower(mode) != 'a' && tolower(mode) != 'b' );
	if (tolower( mode)== 'b')
	{
		ModeSilent = false;
	}
	else
	{
		ModeSilent = true;
	}
	do
	{
		cout << "Enter the nummber of rounds greater than or equal 40"<<endl;
		cin >> number;
	} while (number < 40);
	//generate is true
	while (true)
	{
		cout << "Enter the file name: ";
		cin >> fileName;
		cout << endl;
		file.open(fileName+".txt");
		if (!file.is_open())
		{
			cout << "Enter the name again please :"<<endl;
		}
		else
		{
			break;
		}
	}
	file.close();
	Game g1(fileName,ModeSilent);
	for (int i = 0; i < 50; i++)
		g1.simulate();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
