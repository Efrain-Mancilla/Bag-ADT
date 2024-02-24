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

	std::string menu_option;
	int menu_choice;
	std::cout << "Welcome to the bag ADT!" << std::endl;
	do {
		// Empty string where client will input integers to add to the bag
		std::string user_input;
		bool menu_option_valid, is_number, valid_value;
		
		do {
			// Do while loop menu for client code that only allows numbered entries
			std::cout << "Enter an option" << std::endl;
			std::cout << "1) Display the bag\n" <<
			"2) Add a value to the bag\n" <<
			"3) Remove a value from the bag\n" <<
			"4) Sort the bag\n" <<
			"5) Search for a value in the bag\n" <<
			"0) Exit" << std::endl;
			std::getline(std::cin, menu_option);
			menu_option_valid = bag.is_number(menu_option);
		} while (!menu_option_valid);
		
		menu_choice = stoi(menu_option);

		switch (menu_choice) {
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
				std::getline(std::cin, user_input);
				// is_number verifies an integer was entered and not a string
				is_number = bag.is_number(user_input);
				if (is_number) {
					new_value = stoi(user_input);
					// second verification that a positive integer was added and not a negative
					if (new_value >= 0) {
						valid_value = true;
					}
				} else valid_value = false;
			} while (valid_value != true);
			std::cout << "Adding to bag... ";
			bag.add(new_value);
			std::cout << new_value << " added to the bag!\n" << std::endl;
			break;

		case 3:
			// case 3 - Remove a value from the bag
			int value_to_remove;
			do {
				std::cout << "Enter a value to remove from the bag" << std::endl;
				std::getline(std::cin, user_input);
				// is_number verifies an integer was entered and not a string
				is_number = bag.is_number(user_input);
				if (is_number) {
					value_to_remove = stoi(user_input);
					// second verification that a positive integer was added and not a negative
					if (value_to_remove >= 0) {
						valid_value = true;
					}
				} else valid_value = false;
			} while (!valid_value);
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
				int type_of_search;
				//  do while loop for searching
				do {
					// do while loop for validating a correct choice, no strings allowed
					do {
						std::cout << "Would you like to use iterative or recursive binary search?\n";
						std::cout << "1) Iterative\n" << "2) Recursive\n" << "0) Exit" << std::endl;
						std::getline(std::cin, user_input);
						is_number = bag.is_number(user_input);
						if (is_number) {
							type_of_search = stoi(user_input);
							// second verification that a positive integer was inputed and not a negative
							if (type_of_search >= 0) {
								valid_value = true;
							}
						} else valid_value = false;
					} while (!valid_value);

					// local variables for iterative and recursive search that hold the search value
					int search_value;
					int search_result;
					if (type_of_search == 1 || type_of_search == 2){
						do {
							std::cout << "Please enter a value to search for: ";
							std::getline(std::cin, user_input);
							is_number = bag.is_number(user_input);
							if (is_number) {
								search_value = stoi(user_input);
								// second verification that an integer is searched for
								if (search_value >= 0) {
									valid_value = true;
								}
							} else valid_value = false;
						} while (!valid_value);
					}
					// switch for binary search
					switch (type_of_search)
					{
					case 1:
						search_result = bag.iterative_bin_search(search_value, 0, bag.getCurrentSize());
						if (search_result != -1){
							std::cout << search_value << " is found at bag index: " << search_result << std::endl;
						} else 
							std::cout << search_value << " is not in the bag" << std::endl;
						break;
					case 2:
						search_result = bag.recursive_bin_search(search_value, 0, bag.getCurrentSize());
						if (search_result != -1){
							std::cout << search_value << " is found at bag index: " << search_result << std::endl;
						} else 
							std::cout << search_value << " is not in the bag" << std::endl;
						break;
					}
				} while (type_of_search != 0);
			}
			else {
				std::cout << "The bag is not sorted. Sort the bag before searching\n" << std::endl;
			}
			break;
		}
	} while (menu_choice != 0);
	std::cout << "Thank you for using the bag! Have a great day." << std::endl;
	
   return 0;
   
}  // end main