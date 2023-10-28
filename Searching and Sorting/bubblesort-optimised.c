/*
CODE FOR IMPLEMENTAION OF BUBBLE SORT (ITERATIVE)
	~WRITTEN BY DEVVRAT SAINI

TIME COMPLEXITY FOR BUBBLE SORT:
	BEST CASE = O (N)
	AVERAGE CASE = O (N^2)
	WORST CASE = O (N^2)
*/


#include<stdio.h>

//swaps value of two integers
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// function to print an array
void printArray(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//optimized bubble sort of array
void bubbleSort(int arr[], int size) {
	int i, j, swapped;
	for(i = 0; i < size-1; i++) {
		swapped = 0;
		for(j = 0; j < size-i-1; j++) {
			// swap if greater value is found
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
		}
		// break if no swaps occur in an iteration
		// ------array is sorted------
		if(swapped == 0) {
			break;
		}
	}
}

// main function
int main() {
	// taking size of array as input
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);

	// taking elements of array as input
	int i, arr[size];
	printf("Enter the elements of the array: ");
	for(i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	// sorting the array
	bubbleSort(arr, size);

	// printing the sorted array
	printf("Sorted array: ");
	printArray(arr, size);
	
	return 0;
}
