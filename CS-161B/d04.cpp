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

void shiftRight(int count, int nums[], int pos){
  int j = 0;
  for (int i = count; i > pos; i--){
    int tempVar = nums[j];
    nums[j] = nums[count-1];
    j++;
    nums[j+1] = tempVar;
  }
}

int main(){
  int numIntegers, targetIndex, nums[20] = {2,4,6,8,10,12};

  numIntegers = 6;
  targetIndex = 4;

  shiftRight(numIntegers, nums, targetIndex);

  for (int i = 0; i < numIntegers; i++){
    cout << nums[i];
  }

  return 0;
}
