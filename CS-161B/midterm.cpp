#include <iostream>

using namespace std;

//Name:   enqueue()
//Desc:   Function to add integers to the rear of the array.
//input:  the queue array, reference to int size, and int val
//output: none
//return: 0 if it successfully runs, 1 if there is an overflow failure
int enqueue(int queue[], int &size, int val);

//Name:   dequeue()
//Desc:   Function to remove integers from the front till the matched variable, val.
//input:  the queue array, reference to int size, and int val as reference
//output: none
//return: 0 if val is not found, 1 if queue array is empty, 0 if it runs successfully
int dequeue(int queue[], int &size, int &val);

//Name:   printQueue()
//Desc:   Function to print all the indices of the queue array.
//input:  the queue array and size as int
//output: Prints the indices of queue
//return: void
void printQueue(int queue[], int size);

//Name:   readInt()
//Desc:   Function to validate the user integer input
//input:  prompt as string and a reference to num as int
//output: None
//return: void
void readInt(int &num, string prompt = "");

const int MAX = 3; // maximum size of queue

int main() {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue


    char userInput; // User action input
    int userInteger; // User integer input
    int actionResult; // Stores the result of enqueue or dequeue

    cout << "Welcome to the FIFO Queue Program!\n" << endl;

    cout << "Enter option: ";
    cin >> userInput;

    while(userInput != 'q'){

      switch(userInput){
        case '+':
          // Validate and store a valid integer
          readInt(userInteger, "Integer");

          // call enqueue and store the result
          actionResult = enqueue(queue, size, userInteger);

          // Prints Error if actionResult = 1;
          if (actionResult == 1){
            cout << "Error: Queue Overflow" << endl;
          }

          printQueue(queue, size);
          break;

        case '-':

          // Validate and store a valid integer
          readInt(userInteger, "Integer");

          // call dequeue and store the result
          actionResult = dequeue(queue, size, userInteger);

          // Handle the result
          if (actionResult == 1){
            cout << "Queue Empty." << endl;
          }
          else if (actionResult == 2){
            cout << userInteger << " is not in the queue." << endl;
          }


          printQueue(queue, size);
          break;

        case 'p':
          printQueue(queue, size);
          break;

        default:
          cout << "Invalid option." << endl;

      }

      cout << "\nEnter option: ";
      cin >> userInput;
    }

    cout << "\nGoodbye!" << endl;

    return 0;
}

int enqueue(int queue[], int &size, int val){

// Execute the code if it does not overflow (size+1 is not greater than MAX)
  if(size < MAX){

    // Set index size equal to val
    queue[size] = val;
    ++size; // increment the size

    return 0; // 0 indicates success!
  }
  else {
    // Print error message
    return 1; // 1 indicates failure!
  }

}

int dequeue(int queue[], int &size, int &val){

  int tempQueue[MAX]; // Saves values not to be deleted
  int tempQueueSize = 0;
  int valOccurence = 0; // Number of times val was found

  // Validate that queue is not empty.
  if (size > 0){

    // Loop through the array and find val.
    for (int i = 0; i < size; ++i){
      // If there is a match on the first occurence of val, run the loop
      if (queue[i] == val && valOccurence == 0){

        for (int j = size-1; j > i; --j){

          // Save the number into the tempQueue and increment the size
          tempQueue[tempQueueSize] = queue[j];
          ++tempQueueSize;
        }
        // Incremend the occurence that Val was found in
        ++valOccurence;
      }
    }

    // Run if the value was not found in the array
    if (valOccurence == 0){
      return 2;
    }
    else{
      for(int i = 0; i < tempQueueSize; i++){
        queue[i] = tempQueue[i];
      }
      // Set the size equal to the size of the amount of variables saved.
      size = tempQueueSize;
    }

  }
  else {
    return 1;
  }

  return 0;
}

// Call this function to print the queue
void printQueue(int queue[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << queue[i];

        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}

// Read and validate the integer number
void readInt(int& num, string prompt){
   int tempVar = 0;

   // Print the prompt if it is not empty
   if (prompt != ""){
       cout << prompt << ": ";
   }

   // Store the user input in a temporary variable
   cin >> tempVar;
   // Handle invalid inputs
   while (cin.fail()){
       cin.clear();
       cin.ignore(100,'\n');
       cout << "invalid input, please try again." << endl;
       cin >> tempVar;
   }

   cin.ignore(100,'\n');
   num = tempVar;
}
