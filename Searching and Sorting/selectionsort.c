/*
CODE FOR IMPLEMENTAION OF SELECTION SORT (ITERATIVE)
	~WRITTEN BY DEVVRAT SAINI

TIME COMPLEXITY FOR SELECTION SORT:
	BEST CASE = O (N^2)
	AVERAGE CASE = O (N^2)
	WORST CASE = O (N^2)
*/	

#include<stdio.h>

// Function to implement Selection Sort
void selectionSort(int arr[] ,int n) {
	int i, j, imin;
	
	for (i = 0; i < n-1; i++) {
		imin = i;
		
		for (j = i+1; j < n; j++) {
			if (arr[j] < arr[imin]) {
				imin=j;
			}
		}
		
		// swapping
		int temp;
		temp = arr[i];
		arr[i] = arr[imin];
		arr[imin] = temp;
	}
}

// Function to print a given array
void printArray(int arr[], int n) {
	int i;
	
	for(i = 0; i < n; i++) {
	    printf("%d ",arr[i]);
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
	selectionSort(arr, n);
	
	// Printing sorted array
	printf("\nSorted Array: ");
	printArray(arr, n);
	
	return 0;	
}
