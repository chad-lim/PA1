#include <iostream>
#include <string>
#include "pa1.h"
//#define MAX 15

using namespace std;
int main(){
    // Takes in the size of the magic square
    cout << "Enter the size of a magic square: ";
    int size;
    cin >> size;
    cout << endl;
    int arr[MAX][MAX];

    // Makes the square
    makeSquare(arr, size);

    // Prints the first magic square
    cout << "Magic Square #1 is:\n";
    printData(arr, size);

    // Prints the second magic square
    flipSquare(arr, size);
    cout << "Magic Square #2 is:\n";
    printData(arr,size);

    // Prints the third magic square
    foldSquare(arr, size);
    cout << "Magic Square #3 is:\n";
    printData(arr, size);
    return 0;
}


// Takes the sum of each row
int sumRow(int arr[MAX][MAX], int size){
    int sum = 0;
    cout << "Checking the sums of every row:      ";
    for (int i = 0; i < size; ++i){
        // Resets the sum to 0 for every row
        sum = 0;
        for (int j = 0; j < size; ++j){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}

// Takes the sum of each column
int sumColumns(int arr[MAX][MAX], int size){
    int sum = 0;
    cout << "Checking the sums of every column:   ";
    for (int j = 0; j < size; ++j){
        // Resets the sum to 0 for each column
        sum = 0;
        for (int i = 0; i < size; ++i){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}

// Takes the left to right diagonal and then right to left diagonal
int sumDiagonal(int arr[MAX][MAX], int size){
    cout << "Checking the sums of every diagonal: ";

    // Finds the sum of values from the top left to the bottom right corner
    int sumLR = 0;
    for (int i = 0; i < size; ++i){
        sumLR += arr[i][i];
    }
    // Prints the sum
    cout << sumLR << " ";

    // Finds the sum of values from the top right to the bottom left corner
    int sumRL = 0;
    for (int i = size-1; i >= 0; --i){
        sumRL += arr[i][i];
    }
    // Prints the sum
    cout << sumRL << endl;

    // Starts a new line after each square print
    cout << endl;
    return 0;
}

// Prints the magic square
int printSquare(int arr[MAX][MAX], int size){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            printf("%4i", arr[i][j]);
        }
        cout << endl;
    }
    return 0;
}

/*
Prints all the data for each of the three squares, including the actual square
as well as its sums.
*/
int printData(int arr[MAX][MAX], int size){
    printSquare(arr, size);
    sumRow(arr, size);
    sumColumns(arr, size);
    sumDiagonal(arr, size);
    return 0;
}

// Creates the magic square
void makeSquare(int arr[MAX][MAX], int size){

    int row = 0;
    int column = size/2;
    // Initializes all elements of the array to 0
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            arr[i][j] = 0;
        }
    }
    // Sets initial count value
    int count = 1;
    arr [row][column] = count;
    // This loop creates the magic square
    while (count <= size*size) {
        row--;
        column++;
        // Test if it goes to the top right corner and drops it down if it does
        if (row == -1 && column == size){
            row += 2;
            column = size - 1;
        }
        // Tests if it goes past the ceiling and wraps it around if it does
        else if (row == -1) {
            row = size - 1 ;
        }
        // Tests if it goes out past the right wall and wraps it around if it does
        else if (column == size) {
            column = 0;
        }
        else{
        }
        // Checks to see if there's anything in the next index and drops it down
        // if there is something there

        if (arr[row][column] != 0){
            row += 2;
            column -= 1;
        }

        // Assigns the next number to the new index
        count++;
        arr[row][column] = count;
    }
}

// Swaps the far right and left sides of the square
void foldSquare(int arr[MAX][MAX], int size){
    int tempArr[MAX][MAX];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            tempArr[i][0] = arr[i][0];
            arr[i][0] = arr[i][size - 1];
            arr[i][size - 1] = tempArr[i][0];
        }
    }
}

// Swamps the top and bottom sides of the square
void flipSquare(int arr[MAX][MAX], int size){
    int tempArr[MAX][MAX];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            tempArr[0][i] = arr[0][i];
            arr[0][i] = arr[size-1][i];
            arr[size-1][i] = tempArr[0][i];
        }
    }
}
