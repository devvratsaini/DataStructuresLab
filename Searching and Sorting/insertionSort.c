#include<stdio.h>

// function to print an array in order
void printArray(int arr[], int size) {
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
}

// insertion sort function
void insertionSort(int arr[], int size) {
	int i, j, key;
	for (i=1; i<size; i++) {
		key = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

// main function
int main() {
	//input: size of array
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);

	// input: array elements
	int arr[size];
	printf("Enter elements of the array:\n");
	int i;
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	// sorting the array
	insertionSort(arr, size);
	
	// printint the sorted array
	printf("Sorted array is: ");
	printArray(arr, size);
	
	return 0;
}
