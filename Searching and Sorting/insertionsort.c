/*
CODE FOR IMPLEMENTAION OF INSERTION SORT (ITERATIVE)
	~WRITTEN BY DEVVRAT SAINI

TIME COMPLEXITY FOR INSERTION SORT:
	BEST CASE = O (N)
	AVERAGE CASE = O (N^2)
	WORST CASE = O (N^2)
*/

#include <stdio.h>
#include <math.h>

// Function to implement Insertion Sort
void insertionSort(int arr[], int n) {
	int i, j, key;
	
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i-1;

		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

// Function to print a given array
void printArray(int arr[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Main function
int main() {
	int i, arr[50], n;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	// Taking elements of array as input
	printf("Enter elements of the array: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	// Sorting the array
	insertionSort(arr, n);
	
	// Printing the sorted array
	printf("\nSorted array: ");
	printArray(arr, n);
	
	return 0;	
}
