// 25.11.24-Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;


//Binarnoe Derevo
//+O(log n )
//-O(log n )
//print(O(n))
//Search = O(log n )

//1 or 2 Node List
//+O(1 = const)
//-O(1 = const)
//Search = O(n = lineynaya)

// Arrays
//+O(n = lineynaya)
//-O(n = lineynaya)
//po indexy zvernenya - O(1 = const)

int power(int num,int step) {
	if (step == 1) {
		return num;
	}
	return num * power(num,step - 1);
}

int main()
{
		Tree tree;
		tree.insert(5);
		tree.insert(3);
		tree.insert(7);
		tree.insert(2);
		tree.insert(4);
		tree.insert(6);
		tree.insert(8);
		tree.Print();
		int ket;
		cout << "Enter key - ";
		cin >> ket;
		if (tree.find(ket) ==true) {
			cout << "true";
		}
		else {
			cout << "false";
		}

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
