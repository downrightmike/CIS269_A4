/*Magic square program that creates squares with random numbers and then sees if they are magic.
*/

#include <iomanip>             
#include <iostream>              
using namespace std;           
const int NUMBER_OF_ROWS = 6;    
const int NUMBER_OF_COLUMNS = 5; 
void printMatrix(int matrix[][NUMBER_OF_COLUMNS],
                 int NUMBER_OF_ROWS); 
void sumRows(int matrix[][NUMBER_OF_COLUMNS],
             int NUMBER_OF_ROWS);
int sumRowsCheck(int matrix[][NUMBER_OF_COLUMNS],
             int NUMBER_OF_ROWS); 
void largestInRows(int matrix[][NUMBER_OF_COLUMNS],
                   int NUMBER_OF_ROWS);

int main()                              
{                                       
  srand(time(0));
  for(int i = 0; i < 10000; i++){
  int board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
      for(int r = 0; r < NUMBER_OF_ROWS; r++){
        for(int c = 0; c < NUMBER_OF_COLUMNS; c++){
          board[r][c] = rand() % 10;
        }
      }
  //need to check if rows ==
    int check = sumRowsCheck(board, NUMBER_OF_ROWS);
   if( check == 0){
  printMatrix(board, NUMBER_OF_ROWS);                                 // print the board
  cout << endl;                                                       // 
  sumRows(board, NUMBER_OF_ROWS);                                     // Sum of rows
  sumRowsCheck(board, NUMBER_OF_ROWS);                                // Sum verify
  cout << endl;                                                       // 
  largestInRows(board, NUMBER_OF_ROWS);                               // Largest int found
    } 
   // else{ cout << "No Magic here." << endl;}
    }// end of i loop
  
  return 0;                                                           //
} // 
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
int sumRowsCheck(int matrix[][NUMBER_OF_COLUMNS], int noOfRows) {
  int sum;
  int sling[noOfRows];// Like a sling of Oreos
  // Sum of each individual row
  for (int row = 0; row < noOfRows; row++) {
    sum = 0;
    for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
      sum = sum + matrix[row][col];
      sling[row] = sum;
  }
  /*for(int num = 0; num < 6; num++){
  cout << sling[num] << " ";
    }  cout << endl;*/
  if(sling[0] != sling[1]){
    return 1;
  }else if(sling[0] != sling[2]){
    return 1;
  }else if(sling[0] != sling[3]){
    return 1;
  }else if(sling[0] != sling[4]){
    return 1;
  }else if(sling[0] != sling[5]){
    return 1;
  }else{
    return 0;
  }
}
void printMatrix(int matrix[][NUMBER_OF_COLUMNS], int noOfRows) {
  for (int row = 0; row < noOfRows; row++) {
    for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
      cout << setw(5) << matrix[row][col] << " ";
    cout << endl;
  }
}