#include <stdio.h>

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        // Declare a variable to check if any swapping happens in this step
        int swapped = 0;
        
        // Perform the comparison and swapping
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                // Swap if the current item is greater than the next item
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                
                swapped = 1; // Mark as swapped
            }
        }
        
        // If no swapping happened in this step, then the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array:\n");
    printArray(data, size);
    
    bubbleSort(data, size);
    
    printf("Sorted Array:\n");
    printArray(data, size);
    
    return 0;
}