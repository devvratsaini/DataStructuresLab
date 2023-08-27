//WRITTEN BY DEVVRAT SAINI
//PROGRAM TO PERFORM LINEAR SEARCH IN AN ARRAY
//

#include<stdio.h>
#include<stdbool.h>

//linear search function
void linearSearch(int arr[], int size, int key) {
	int i;
	bool found=-1;

  //comparing elements of array with key
	for(i=0; i<size; i++) {
		if(arr[i]==key) {
			//key found
			found = i;
			break;
		}
	}
	
	if(found==-1)
		printf("%d is not present in the array.", key);
	else
		printf("%d found at index %d of the array.", key, i);
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
	
	//calling linear search function
	linearSearch(arr, size, key);
	
	return 0;
}
