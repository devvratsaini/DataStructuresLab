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

//optimized bubble sort of array
void bubbleSort(int arr[], int size) {
	for(int i = 0; i < size - 1; i++) {
		int swapped = false;
		for(int j = 0; j < size - i - 1; j++) {
		
			//swap if smaller value is found
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
	if(swapped == false)
		break;
	}
}

int main() {
	printf("BUBBLE SORT\n\n");
	
	//input: size of array
	int size;
	printf("Enter the number of elements in array: ");
	scanf("%d", &size);
	
	//input: elements of array
	int arr[size];
	printf("Enter the elements of the array: ");
	for(int i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	//sorting the array
	int numSwaps = 0;
	int numPasses = 0;
	for(int i = 0; i < size - 1; i++) {
		int swapped = false;
		numPasses++;
		
		for(int j = 0; j < size - i - 1; j++) {
			//swap if smaller value is found
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
				numSwaps++;
			}
		}
		
		if(swapped == false)
			break;
	}
	
	//print: array
	printf("Sorted array: ");
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n%d swaps occurred.", numSwaps);
	printf("\n%d passes occurred.", numPasses);
	
	return 0;
}
