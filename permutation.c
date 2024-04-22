#include <stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void numSwap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(char *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}
void printNumArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void permute(char *array, int start, int end) {
    if (start == end) {
        printArray(array, end + 1); // Print the permutation
        return;
    } else {
        for (int i = start; i <= end; i++) {
            swap((array + start), (array + i)); // Swap the current element with itself and then with every other element
            permute(array, start + 1, end); // Recurse with the next element in the array
            swap((array + start), (array + i)); // Backtrack to restore the original array before the next iteration
        }
    }
}

void num_permute(int* array, int start, int end) {
    if (start == end) {
        printNumArray(array, end + 1); // Print the permutation
        return;
    } else {
        for (int i = start; i <= end; i++) {
            numSwap(array+start, array+i); // Swap the current element with itself and then with every other element
            num_permute(array, start + 1, end); // Recurse with the next element in the array
            numSwap((array + start), (array + i)); // Backtrack to restore the original array before the next iteration
        }
    }
}

int main() {
    // char permutation
    char array[] = "12345";
    int n = sizeof(array) / sizeof(array[0]) - 1; // Calculate the number of elements in the array, excluding the null terminator
    permute(array, 0, n - 1); // Generate permutations

    // int permutation
    // int array[4] = {10, 20, 30, 40};
    // num_permute(array, 0, 3);

    return 0;
}