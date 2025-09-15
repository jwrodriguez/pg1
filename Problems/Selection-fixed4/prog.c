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
  if (argc == 1 + 0)
    printf("I need more arguments!\n");
  // If we have 1 argument
  else if (argc == 1 + 1) {
    // convert the argument to a value
    int val = atoi(argv[1]);
    if (val % 2 == 0)
      printf("Even!\n");
    else
      printf("Odd\n");
  }
  // more than 1 argument
  else
    printf("I need less arguments!\n");
  //Template code ends here
  

  FILE *input = fopen(argv[1], "r"); // opens the input file based on first execution argument with read permission.
  if (input == NULL)
  { // error handling for file opening. This may be removed to check for coverage.
    printf("Error opening input file.\n");
    return 1;
  }

  int n = 0; // Variable to hold the size of the array.
  float val; // Variable to hold each float value read from the file.
  
  float *arr = malloc(1 * sizeof(float));
  // Removed arr == null to check for coverage.
  // An invalid n value would cause malloc to return null but this is allready checked for above.

  // Write the array elements from the file into the array.
  // fscan picks up where it left off skipping the int determining the size of the array.
  while(fscanf(input, "%f", &val) == 1){

    //Reallocate memory for the array to hold one more element.
    //We don't know the size in advance this time so it needs to be increase each time.
    float *temp = realloc(arr, (n + 1) * sizeof(float));
    if (temp == NULL) {
            printf("Memory allocation failed for array.\n");
            free(arr);
            fclose(input);
            return 1;
    }

    arr = temp; 
    arr[n] = val; 
    n++;
  }


  //Selection sort function call.
  //Sorting algorithm documentation link is above.
  selectionSort(arr,n);
  
  for(int i = 0; i < n; i++)
  {
    printf("%f ", arr[i]);
  }
  printf("\n");
  free(arr); // Free the allocated memory for the array.
  fclose(input); // Close the input file.  
  return 0;
}


void selectionSort(float arr[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
    
        swap(&arr[min], &arr[i]);
    }
}

void swap(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}