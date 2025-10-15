/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #4
# Date:             October 9, 2025
# Description:
# Input:
# Output:
# Sources:          None
#******************************************************************************/
#include <iostream>
using namespace std;

//Name:   copyLeft()
//Desc:   Function to copy all indices from the left of the target index
//input:  the count as int, nums array as constant, the target index as int,
// temporary array, size of the temporary array as int
//output: an array containing values left of the target index
//return: void
void copyLeft(int count,int const nums[],int pos,
  int tempNums[],int& tempNumsCount){

  for (int i = 0; i < pos; ++i){
    tempNums[i] = nums[i];
    ++tempNumsCount;
  }
}

//Name:   shiftRight()
//Desc:   Function to move all indices from the target index to count-1
//        to the start of the array. Then appends values from the temp array.
//input:  the count as int, nums array , the target index as int,
// temporary array as const, size of the temporary array as int
//output: values shifted from the target index to the right. With wrapping.
//return: void
void shiftRight(int count,int nums[],int pos,
  int const tempNums[],int tempNumsCount){

  int j = 0; // starting index of the array to move items into

  // moves numberes from pos to the end into the start of the array
  for (int i = pos; i < count; ++i){
    nums[j] = nums[i];
    ++j;
  }

  // copies numbers from the temp array to the end of the array
  for(int i = 0; i < tempNumsCount; ++i){
    nums[j] = tempNums[i];
    ++j;
  }
}

int main(){
  int numIntegers, targetIndex, nums[20], tempNums[20]
  , tempNumsCount = 0;


  // Prompt user for the amount of numbers to add
  cin >> numIntegers;

  // Add numbers to the array
  for (int i = 0; i < numIntegers; ++i){
   cin >> nums[i];
  }
  // Prompt user for the amount of numbers to add
  cin >> targetIndex;

  copyLeft(numIntegers, nums, targetIndex, tempNums, tempNumsCount);
  shiftRight(numIntegers, nums, targetIndex, tempNums, tempNumsCount);

  // Output the end result
  for (int i = 0; i < numIntegers; i++){
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
