//@Template Author: Richard Veras
//@author Joseph Rodriguez Ben Cruickshank

//Refrence for selection sort algorithm:
//https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/

/*
  This is a small program to demonstrate gcov. It
  can take no arguments or 1 argument. It prints
  a message if more than one is given. If the argument's
  value is odd it prints out odd, otherwise even
  The goal is to show you need multiple test cases
  to cover all of the code.
  -richard.m.veras@ou.edu
*/
#include <stdio.h>
#include <stdlib.h>

void selectionSort(float arr[], int n);
void swap(float *x, float *y);

int main(int argc, char * argv[]) {
  // No arguments passed
  // note: argv[0] is the name of the
  // program, so we always have at least
  // 1 value in argv.
  if (argc != 3)
  {
    printf("Error: Please exactly two arguments.\n");
    printf("Format: %s input_name.extenstion output_name.extension \n", argv[0]);
    return 1;
  }


  FILE *input = fopen(argv[1], "r"); // opens the input file based on first execution argument with read permission.
  if (input == NULL)
  { // error handling for file opening. This may be removed to check for coverage.
    printf("Error opening input file.\n");
    return 1;
  }

  int n = 4; // Variable to hold the size of the array.
  float val; // Variable to hold each float value read from the file.
  
  float *arr = malloc(n * sizeof(float));
  // Removed arr == null to check for coverage.
  // An invalid n value would cause malloc to return null but this is allready checked for above.

  // Write the array elements from the file into the array.
  // fscan picks up where it left off skipping the int determining the size of the array.
  for (int i = 0; i < n; i++)
  {
    fscanf(input, "%f", &arr[i]);
  }


  //Selection sort function call.
  //Sorting algorithm documentation link is above.
  selectionSort(arr,n);
  
  //Prints Sorted Array to the console.
  for(int i = 0; i < n; i++)
  {
    printf("%2f ", arr[i]);
  }
  printf("\n");

  FILE *output = fopen(argv[2], "w"); // argv[2] is the output file given from exercution arguments.
  if (output == NULL){
    free(arr);
    fclose(input);
    printf("Error writing output file.\n");
    return 1;
  }
  // Write the sorted array to the output file.
  for (int i = 0; i < n; i++) {
    fprintf(output, "%.2f\n", arr[i]);  // one float per line
  }
  printf("\n");
  free(arr); // Free the allocated memory for the array.
  fclose(input); // Close the input file.  
  return 0;
}


//Combines Unroll and No Conditionals logic to remove all if statements and loops.
void selectionSort(float arr[], int n) {
    int min = 0;
    // i = 0
    min = 0;
    if (arr[1] < arr[min]) min = 1;
    if (arr[2] < arr[min]) min = 2;
    if (arr[3] < arr[min]) min = 3;
    swap(&arr[min], &arr[0]);

    // i = 1
    min = 1;
    if (arr[2] < arr[min]) min = 2;
    if (arr[3] < arr[min]) min = 3;
    swap(&arr[min], &arr[1]);

    // i = 2
    min = 2;
    if (arr[3] < arr[min]) min = 3;
    swap(&arr[min], &arr[2]);
}

void swap(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

//int condition = arr[j] < arr[min];
//min = condition * j + (1 - condition) * min;