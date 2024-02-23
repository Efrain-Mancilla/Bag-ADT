#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;
	
	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	// Add the initial values to the bag
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(initialValues[i]);
	}  // end for

	int menu_option;
	std::cout << "Welcome to the bag ADT!" << std::endl;
	do {
		// menu for client code
		std::cout << "Please enter an option" << std::endl;
		std::cout << "1) Display the bag\n" <<
		"2) Add a value to the bag\n" <<
		"3) Remove a value from the bag\n" <<
		"4) Sort the bag\n" <<
		"5) Search for a value in the bag\n" <<
		"-1) Exit\n" << std::endl;
		std::cin >> menu_option;


	} while (menu_option != -1);
	

	// sorts the bag
	bag.bubble_sort();

	bag.display_bag();

	// testing iterative and recursive binary search
	int iterative_target = 99;
	int recursive_target = 399;
	bag.iterative_bin_search(iterative_target, 0, bag.getCurrentSize());
	bag.recursive_bin_search(recursive_target, 0, bag.getCurrentSize());
	
	// Call a funciton that exercises
	// some of the bag methods
	bagTester(bag);
	

   return 0;
   
}  // end main

/****************************************************************
* Function:   bagTester
* Inputs:     the array bag
* Outputs:    none
* Purpose:    This function exercises some of the bag methods
****************************************************************/

void bagTester(ArrayBag<int>& bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();
   
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end bagTester



