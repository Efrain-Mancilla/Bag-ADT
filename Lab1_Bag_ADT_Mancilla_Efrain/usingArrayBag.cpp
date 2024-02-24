#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

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
		std::cout << "Enter an option" << std::endl;
		std::cout << "1) Display the bag\n" <<
		"2) Add a value to the bag\n" <<
		"3) Remove a value from the bag\n" <<
		"4) Sort the bag\n" <<
		"5) Search for a value in the bag\n" <<
		"-1) Exit" << std::endl;
		std::cin >> menu_option;

		switch (menu_option)
		{
		case 1:
			// case 1 - Display the bag
			bag.display_bag();
			break;
		case 2:
			// case 2 - Add a value to the bag
			int new_value;
			// do while loop only allows a non-negative number to be added
			do {
				std::cout << "Enter a non-negative number to add to the bag" << std::endl;
				cin >> new_value;
			} while (new_value < 0);
			std::cout << "Adding to bag... ";
			bag.add(new_value);
			std::cout << new_value << " added to the bag!\n" << std::endl;
			break;
		case 3:
			// case 3 - Remove a value from the bag
			std::cout << "Enter a value to remove from the bag" << std::endl;
			int value_to_remove;
			cin >> value_to_remove;
			std::cout << "Removing " << value_to_remove << ", if present, from the bag...";
			bag.remove(value_to_remove);
			std::cout << " removed from bag!\n" << std::endl;
			break;
		case 4:
			// case 4 - Sorting the bag
			std::cout << "Beginning to sort the bag... ";
			bag.bubble_sort();
			std::cout << "bag all sorted\n" << std::endl;
			break;
		case 5:
			// case 5 - Searching the bag
			if (bag.is_sorted()){
				int search_choice; // sentinel for searching
				//  do while loop for searching
				do {
					std::cout << "Would you like to use iterative or recursive binary search?\n";
					std::cout << "1) Iterative\n" << "2) Recursive\n" << "-1) Exit" << std::endl;
					std::cin >> search_choice;
					// local variables
					int search_value;
					int iterative_result, recursive_result;
					if (search_choice == 1 || search_choice == 2){
						std::cout << "Please enter a value to search for: ";
						std::cin >> search_value;
						std::cout << std::endl;
					}
					// switch for binary search
					switch (search_choice)
					{
					case 1:
						iterative_result = bag.iterative_bin_search(search_value, 0, bag.getCurrentSize());
						if (iterative_result != -1){
							std::cout << search_value << " is found at bag index: " << iterative_result << std::endl;
						} else 
							std::cout << search_value << " is not in the bag" << std::endl;
						break;
					case 2:
						recursive_result = bag.recursive_bin_search(search_value, 0, bag.getCurrentSize());
						if (recursive_result != -1){
							std::cout << search_value << " is found at bag index: " << recursive_result << std::endl;
						} else 
							std::cout << search_value << " is not in the bag" << std::endl;
						break;
					default:
						break;
					}
				} while (search_choice != -1);
			}
			else {
				std::cout << "The bag is not sorted. Sort the bag before searching\n" << std::endl;
			}
			break;
		default:
			break;
		}
	} while (menu_option != -1);
	
   return 0;
   
}  // end main