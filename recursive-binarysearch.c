#include<stdio.h>
#include<stdbool.h>

//function implementing recursive binary search
int binSearchRec(int arr[], int low, int high, int key) {
	if(low<=high) {
		int mid = (high + low)/2;
		
		//check if key is present at mid
		if(arr[mid] == key)
			return mid;
		
		//if key is lesser than mid, ignore right half
		if(arr[mid]>key)
			return binSearchRec(arr, low, mid-1, key);
			
		//if key is greater than mid, ignore left half
		return binSearchRec(arr, mid+1, high, key);
	}
	return -1;
}

int main() {
	//array size
	int size;
	printf("Enter the number of elements in array: ");
	scanf("%d", &size);
	
	//array elements
	int arr[size];
	printf("Enter the elements of the array: ");
	for(int i=0; i<size; i++)
		scanf("%d", &arr[i]);
	
	//key element to search for
	int key;
	printf("Enter the element to search for: ");
	scanf("%d", &key);
	
	//calling recursive binary search function
	int result = binSearchRec(arr, 0, size-1, key);
	if(result==-1)
		printf("%d is not present in the array.", key);
	else
		printf("%d found at index %d of the array", key, result);
	
	return 0;
}
