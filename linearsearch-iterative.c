/*
CODE FOR IMPLEMENTAION OF LINEAR SEARCH (ITERATIVE)
	~WRITTEN BY DEVVRAT SAINI

FOR LINEAR SEARCH:
	TIME COMPLEXITY = O (N)
	BEST CASE = O (1)
	WORST CASE = O (N)
*/

#include<stdio.h>

//linear search function
int linear_search_iterative(int key, int arr[], int size) {
	int i;
	int found=-1;

	//comparing elements of array with key
	for(i=0; i<size; i++) {
		if(arr[i]==key) {
			//key found
			found = i;
			break;
		}
	}
	
	//returning index of key if found, else returning -1
	return found;
}

int main() {
	//array size
	int size;
	printf("Enter the number of elements in array: ");
	scanf("%d", &size);
	
	//array elements
	int arr[size];
	printf("Enter the elements of the array: ");
	int i;
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	
	//key element to search for
	int key;
	printf("Enter the element to search for: ");
	scanf("%d", &key);
	
	//calling iterative linear search function
	int index = linear_search_iterative(key, arr, size);

	//checking if element is present in array
	if(index==-1) {
		printf("%d is not present in the array.", key);
	} else {
		printf("%d is present at index %d of array.", key, index);
	}
	
	return 0;
}
