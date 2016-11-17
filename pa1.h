#ifndef PA1_H
#define PA1_H
#define MAX 15

#include <iostream>

int sumRow(int arr[MAX][MAX], int size);
int sumColumns(int arr[MAX][MAX], int size);
int sumDiagonal(int arr[MAX][MAX], int size);
int printSquare(int arr[MAX][MAX], int size);
int printData(int arr[MAX][MAX], int size);
void makeSquare(int arr[MAX][MAX], int size);
void foldSquare(int arr[MAX][MAX], int size);
void flipSquare(int arr[MAX][MAX], int size);

#endif
