#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

// *** Add new method code to the ADT implementation file
template <class ItemType>
void ArrayBag<ItemType>::bubble_sort() {
   // local variables for bubble sort
   int index, test;
   bool swapped;
   // for loop that checks to see if anything is swapped, if unchanged then array is sorted
   for (index = 0; index < itemCount - 1; index++) {
      swapped = false;
      // for loop that tests index values and swaps if former value is larger than latter value
      for (test = 0; test < itemCount - index - 1; test++) {
         if (items[test] > items[test + 1]) {
            // swaps the values if the former value is larger than the latter value
            ItemType temp_hold = items[test];
            items[test] = items[test + 1];
            items[test + 1] = temp_hold;
            swapped = true;
         }
      }
      // if the loop circles through without swapping then it is sorted
      if (!swapped) {
         sorted = true;
         break;
      }      
   }
}

template <class ItemType>
bool ArrayBag<ItemType>::is_sorted() const {
   return sorted; // returns sorted boolean value
}

template <class ItemType>
int ArrayBag<ItemType>::iterative_bin_search(ItemType target, int left_bound, int right_bound){
   while (left_bound < right_bound){
      int middle = (left_bound + (right_bound - 1)) / 2; // middle that is compared for target value

      if (items[middle] == target) { // base case if target item is found in middle index
         return middle; // result is changed to matched target
      }

      // updates left bound in case middle test case is less than target value
      else if (items[middle] < target) {
         left_bound = middle + 1; // left bound gets updated to be the middle index plus 1
      }

      // updates right bound in case middles test case is greater than target value
      else {
         right_bound = middle - 1; // right bound gets updated to be the middle index minus 1
      }
   }
   return -1; // returns iterative result -1 if not found
}

template <class ItemType>
int ArrayBag<ItemType>::recursive_bin_search(ItemType target, int left_bound, int right_bound) {
   // catch case so it's not an infinite loop
   if (left_bound < right_bound) {
      int middle = (left_bound + (right_bound - 1)) / 2;

      // tests if middle index value is equal to target value, returns if so
      if (items[middle] == target){
         return middle;
      }

      // tests if middle value is smaller than the value, changes left bound if so and makes
      // a recursive call
      else if (items[middle] < target) {
         return recursive_bin_search(target, (middle + 1), right_bound);
      }

      // else makes a recursive call and changes the right bound 
      else {
         return recursive_bin_search(target, left_bound, (middle - 1));
      }
   }
   // if target is not found, returns a -1
   return -1;
}

template <class ItemType>
void ArrayBag<ItemType>::display_bag() const {
   // calls and creates a vector for bag
   std::vector<ItemType> bag_to_display = toVector();
   
   std::cout << "Bag contents are: ";
   for (int index = 0; index < bag_to_display.size(); index++){
      std::cout << bag_to_display[index] << ' ';
   }
   std::cout << std::endl;
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template <class ItemType>
bool ArrayBag<ItemType>::is_number(std::string user_input){
   bool is_number = true;
   for (int index = 0; index < user_input.length(); index++) {
      if (!isdigit(user_input[index])) {
         is_number = false;
         break;
      }
   }
   return is_number;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
      sorted = false;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
      sorted = false;
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

