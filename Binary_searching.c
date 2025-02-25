#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid+1;  // Element found at mid
        
        if (arr[mid] < target)
            low = mid + 1;  // Search the right half
        else
            high = mid - 1;  // Search the left half
    }
    
    return -1;  // Element not found
}

int main() {
    int n, target;

    // Asking user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Asking user to input the elements of the array
    printf("Enter the elements (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Asking user for the target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Calling binary search
    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found in the array");
        printf("\nProgrammed by Roshan Yadav");
    return 0;
}