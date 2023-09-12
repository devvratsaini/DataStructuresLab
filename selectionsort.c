#include<stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

void selectionSort(int arr[], int size) {
	int i, j, imin;
	
	for(i=0; i<size-1; i++) {
		imin = i;
		
		for(j=i+1; j<size; j++)
			if(arr[j] < arr[imin])
				imin = j;
				
		swap(&arr[i], &arr[imin]);
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
	
	selectionSort(arr, size);
	
	printf("Sorted array is: ");
	printArray(arr, size);
  
	return 0;	
}
