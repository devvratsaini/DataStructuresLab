#include<stdio.h>

void printArray(int arr[], int size) {
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
}

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

int main() {
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Enter elements of the array:\n");
	int i;
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	
	insertionSort(arr, size);
	
	printf("Sorted array is: ");
	printArray(arr, size);
	
	return 0;
}
