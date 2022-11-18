/*Write a program that uses a 3 3 3 array and randomly place each
integer from 1 to 9 into the nine squares.
The program calculates the magic number by adding all the numbers in the array
and then dividing the sum by 3. The 3 3 3 array is a magic square if the sum of
each row, each column, and each diagonal is equal to the magic number. Your
program must contain at least the following functions: a function to randomly
fill the array with the numbers a function to determine if the array is a magic
square. Run these functions for some large number of times, say 1,000, 10,000,
or 1,000,000, and see the number of times the array is a magic square.
*/
// Two-dimensional arrays as parameters to functions.
#include <iomanip>               //Line 2
#include <iostream>              //Line 1
using namespace std;             // Line 3
const int NUMBER_OF_ROWS = 6;    // Line 4
const int NUMBER_OF_COLUMNS = 5; // Line 5
void printMatrix(int matrix[][NUMBER_OF_COLUMNS],
                 int NUMBER_OF_ROWS); // Line 6
void sumRows(int matrix[][NUMBER_OF_COLUMNS],
             int NUMBER_OF_ROWS); // Line 7
void largestInRows(int matrix[][NUMBER_OF_COLUMNS],
                   int NUMBER_OF_ROWS); // Line 8
int main()                              // Line 9
{                                       // Line 10
  int board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {
      {17, 8, 24, 10, 28}, {9, 20, 16, 55, 90}, {25, 45, 35, 8, 78},
      {5, 0, 96, 45, 38},  {76, 30, 8, 14, 28}, {9, 60, 55, 62, 10}}; // Line 11
  printMatrix(board, NUMBER_OF_ROWS);                                 // Line 12
  cout << endl;                                                       // Line 13
  sumRows(board, NUMBER_OF_ROWS);                                     // Line 14
  cout << endl;                                                       // Line 15
  largestInRows(board, NUMBER_OF_ROWS);                               // Line 16
  return 0;                                                           // Line 17
} // Line 18
// Place the definitions of the functions printMatrix,
// sumRows, and largestInRows as described previously here.
void largestInRows(int matrix[][NUMBER_OF_COLUMNS], int noOfRows) {
  int largest;
  // Largest element in each row
  for (int row = 0; row < noOfRows; row++) {
    largest = matrix[row][0]; // Assume that the first element
    // of the row is the largest.
    for (int col = 1; col < NUMBER_OF_COLUMNS; col++)
      if (largest < matrix[row][col])
        largest = matrix[row][col];
    cout << "The largest element of row " << (row + 1) << " = " << largest
         << endl;
  }
}
void sumRows(int matrix[][NUMBER_OF_COLUMNS], int noOfRows) {
  int sum;

  // Sum of each individual row
  for (int row = 0; row < noOfRows; row++) {
    sum = 0;
    for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
      sum = sum + matrix[row][col];
    cout << "Sum of row " << (row + 1) << " = " << sum << endl;
  }
}
void printMatrix(int matrix[][NUMBER_OF_COLUMNS], int noOfRows) {
  for (int row = 0; row < noOfRows; row++) {
    for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
      cout << setw(5) << matrix[row][col] << " ";
    cout << endl;
  }
}