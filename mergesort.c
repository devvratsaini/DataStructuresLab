#include<stdio.h>

void printArray(int arr[], int size) {
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int leftArr[n1], rightArr[n2];
 
    for (i=0; i<n1; i++)
        leftArr[i] = arr[l+i];
    
    for (j=0; j<n2; j++)
        rightArr[j] = arr[m+1+j];
 
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
 
    
    while (i<n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
	
    while (j<n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
	
	mergeSort(arr, 0, size);
	
	printf("Sorted array is: ");
	printArray(arr, size);
	
	return 0;
}
