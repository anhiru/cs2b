//
//  a6_3.cpp
//  a6_3
//
//  Created by Andrew Tran on 10/30/19.
//  CS 2B, Dave Harden.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
using namespace std;

/*

 This program tests the recursive function: selection_sort.

 The program will test this method using an array of integers that will be
 initialized without user input.

 The values in the test array will be printed to the console before and after
 the function call.

 */

int indexOfSmallest(const int list, int startingIndex, int size);
void selection_sort(int list[], int startingIndex, int size);


int main() {
    int testArray[] = {2, 0, 8, 9, 2, 6, 7};
    int size = sizeof(testArray) / sizeof(testArray[0]);  // compute array size

    cout << "Before selection sort:" << endl;
    for (int i = 0; i < size; i++) {
        cout << testArray[i] << " ";
    }

    cout << endl << endl;
    selection_sort(testArray, 0, size);

    cout << "After selection sort:" << endl;
    for (int j = 0; j < size; j++) {
        cout << testArray[j] << " ";
    }

    cout << endl << endl;
}





// This int helper function returns the index of the smallest number from a
// constant list of integer values.

int indexOfSmallest(const int list[], int startingIndex, int size) {
    int targetIndex = startingIndex;

    for (int i = startingIndex + 1; i < size; i++) {
        if (list[i] < list[targetIndex]) {
            targetIndex = i;
        }
    }

    return targetIndex;
}





// This void recursive function takes in an array of integers, an integer
// representing the starting index, and an integer representing the size of
// the array.
// The function will sort the array of integers into ascending order.

void selection_sort(int list[], int startingIndex, int size) {
    if (startingIndex != size) {
        int smallest = indexOfSmallest(list, startingIndex, size);

        if (startingIndex != smallest) {
            int temp = list[startingIndex];
            list[startingIndex] = list[smallest];
            list[smallest] = temp;
        }

        return selection_sort(list, startingIndex + 1, size);
    }
}

/*

 Before selection sort:
 2 0 8 9 2 6 7

 After selection sort:
 0 2 2 6 7 8 9

 */
