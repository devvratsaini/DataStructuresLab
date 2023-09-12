#include<stdio.h>

int linearSearch(int key, int arr[], int size) {
	//return -1 if array is empty
	if(size==0)
		return -1;
	
	//return if key is found
	if(arr[size] == key)
		return size;
	
	return linearSearch(key, arr, size-1);
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
	
	//calling recursive linear search function
	int index = linearSearch(key, arr, size);

	//checking if element is present in array
	if(index==-1) {
		printf("%d is not present in the array.", key);
	} else {
		printf("%d is present at index %d of array.", key, index);
	}
	
	return 0;
}
