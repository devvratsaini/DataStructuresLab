/*
CODE FOR IMPLEMENTAION OF BINARY SEARCH (RECURSIVE)
	~WRITTEN BY DEVVRAT SAINI

FOR BINARY SEARCH:
	TIME COMPLEXITY = O (LOG N)
	BEST CASE = O (1)
	WORST CASE = O (LOG N)
*/

#include<stdio.h>

//function implementing recursive binary search
int binSearchRec(int key, int arr[], int low, int high) {
	if(low<=high) {
		int mid = (high + low)/2;
		
		//check if key is present at mid
		if(arr[mid] == key)
			return mid;
		
		//if key is lesser than mid, ignore right half
		if(arr[mid]>key)
			return binSearchRec(key, arr, low, mid-1);
			
		//if key is greater than mid, ignore left half
		return binSearchRec(key, arr, mid+1, high);
	}
	//else return -1 if not found
	return -1;
}

int main() {
	//array size
	int size;
	printf("Enter the number of elements in array: ");
	scanf("%d", &size);
	
	//array elements
	int i, arr[size];
	printf("Enter the elements of the array: ");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	
	//key element to search for
	int key;
	printf("Enter the element to search for: ");
	scanf("%d", &key);
	
	//calling recursive binary search function
	int result = binSearchRec(key, arr, 0, size-1);
	if(result==-1)
		printf("%d is not present in the array.", key);
	else
		printf("%d found at index %d of the array", key, result);
	
	return 0;
}
