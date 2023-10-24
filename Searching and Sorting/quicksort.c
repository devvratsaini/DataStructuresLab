/*
CODE FOR IMPLEMENTAION OF INSERTION SORT (ITERATIVE)
	~WRITTEN BY DEVVRAT SAINI

TIME COMPLEXITY FOR INSERTION SORT:
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


void quickSort(int arr[], int low, int high) {
    if (low < high) {
    	// Choosing pivot position
        int pivot = arr[low];
        
        int i = low;   
        int j = high;

        while (i <= j) {
            while (arr[i] <= pivot) {
                i++;
            }
            
            while (arr[j] > pivot) {
                j--;
            }
            
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }

        // Changing pivot position
        swap(&arr[j], &arr[low]);
		
        // Sorting the sub-arrays recursively
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

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
