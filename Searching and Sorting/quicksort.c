/*
CODE FOR IMPLEMENTAION OF QUICK SORT
	~WRITTEN BY DEVVRAT SAINI

TIME COMPLEXITY FOR QUICK SORT:
	BEST CASE = O (N * LOG N)
	AVERAGE CASE = O (N * LOG N)
	WORST CASE = O (N * LOG N)
*/


#include <stdio.h>

// Function to swap two numbers
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

// Function for creating partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
	
	int j;
    for (j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main function
int main() {
    int i, arr[50], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
	
	// Taking elements of the array as input
    printf("Enter elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array
    int start = 0, end = n-1;
    quickSort(arr, start, end);
    
    // Printing the Sorted Array
    printf("\nSorted Array: ");
    printArray(arr, n);
    
    return 0;
}
