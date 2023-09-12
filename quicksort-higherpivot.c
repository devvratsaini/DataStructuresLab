#include<stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int quicksort_higher(int arr[], int low, int high) {
	if(low < high) {
		int pivot = high, i = low, j = high;
		while (i < j) {
			while (arr[i] <= arr[pivot] && i <= high)
				i++;
			while (arr[j] > arr[pivot] && j >= low)
				j--;
			if(i < j)
				swap(&arr[i], &arr[j]);
		}
		swap(&arr[j], &arr[pivot]);
		quicksort_higher(arr, low, pivot - 1);
		quicksort_higher(arr, pivot + 1, high);
	}
}

int main() {
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Enter elements of the array:\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	
	quicksort_higher(arr, 0, size - 1);
	
	printf("Sorted array is: ");
	printArray(arr, size);
	
	return 0;
}
