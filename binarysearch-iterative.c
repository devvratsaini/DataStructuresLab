#include<stdio.h>
#include<stdbool.h>

//function implementing iterative binary search
int binSearchIter(int arr[], int low, int high, int key) {
	while(low<=high) {
		int mid = (high + low)/2;
		
		//check if key is present at mid
		if(arr[mid] == key)
			return mid;
		
		//if key is lesser than mid, ignore right half
		if(arr[mid]>key)
			high = mid - 1;
			
		//if key is greater than mid, ignore left half
		else
			low = mid + 1;
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
	
	//calling iterative binary search function
	int result = binSearchIter(arr, 0, size-1, key);
	if(result==-1)
		printf("%d is not present in the array.", key);
	else
		printf("%d found at index %d of the array", key, result);
	
	return 0;
}
