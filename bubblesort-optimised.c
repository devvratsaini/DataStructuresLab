#include<stdio.h>

// swap two integers function
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// optimized bubble sort function
void bubbleSort(int arr[], int size) {
	int i, j;
	for(i=0; i<size-1; i++) {
		int swapped = 0;
		for(j=0; j<size-i-1; j++) {
			// swap if smaller value is found
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
		}

	// break if array is sorted
	if(swapped == 0)
		break;
	}
}

// main function
int main() {
	printf("OPTIMIZED BUBBLE SORT\n\n");
	
	// input: size of array
	int size;
	printf("Enter the number of elements in array: ");
	scanf("%d", &size);
	
	// input: elements of array
	int i, arr[size];
	printf("Enter the elements of the array: ");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	// sorting the array
	bubbleSort(arr, size);
	
	// print: array
	printf("Sorted array: ");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
