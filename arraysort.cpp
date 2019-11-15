//
//  a3_2.cpp
//  a3_2
//
//  Created by Andrew Tran on 10/09/19.
//  CS 2B, Dave Harden.
//  Copyright © 2019 Andrew Tran. All rights reserved.
//

#include <iostream>
using namespace std;

/*

 This program records high-score data for a fictitious game.
 The program will ask the user to enter the number of scores,
 create two dynamic arrays sized accordingly,
 ask the user to enter the indicated number of names and scores,
 and then print the names and scores sorted by score in descending order.
 Internal operations will sort the inputted data by score in descending order.
 No effort is made to prevent the client from initially entering a negative
 value for the size of each dynamic array.

 */

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
int indexOfLargest(const int list[], int startingIndex, int size);


int main() {
    int size;

    cout << "How many scores will you enter?: ";
    cin >> size;

    string* names = new string[size];
    int* scores = new int[size];

    initializeArrays(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);
}





// This void function initializes two dynamic arrays (names and scores)
// with user-inputted values.

void initializeArrays(string names[], int scores[], int size) {
    string name;
    int score;

    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << (i + 1) << ": ";
        cin >> name;
        names[i] = name;
        cout << "Enter the score for score #" << (i + 1) << ": ";
        cin >> score;
        scores[i] = score;
    }
}





// This void function sorts both dynamic arrays (names and scores)
// in descending order by score.
// This function utilizes a helper function to locate the largest score
// during each loop iteration.

void sortData(string names[], int scores[], int size) {
    for (int i = 0; i < size - 1; i++) {
        swap(names[i], names[indexOfLargest(scores, i, size)]);
        swap(scores[i], scores[indexOfLargest(scores, i, size)]);
    }
}





// This void function displays the final list of names and scores.
// Each name is listed, followed by a colon and their respective score.

void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}





// This int helper function returns the index of the largest number from a
// constant list of integer values.

int indexOfLargest(const int list[], int startingIndex, int size) {
    int targetIndex = startingIndex;
    for (int i = startingIndex + 1; i < size; i++) {
        if (list[i] > list[targetIndex]) {
            targetIndex = i;
        }
    }
    return targetIndex;
}
