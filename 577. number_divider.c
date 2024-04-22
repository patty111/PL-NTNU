#include <stdio.h>

// void partition(int n, int k, int *arr, int idx, int start) {
//     if (n < 0) return;
//     if (n == 0 && idx == k) {
//         for (int i = 0; i < k; i++) {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//         return;
//     }
//     if (idx == k) return;
//     for (int i = start; i >= 0; i--) {
//         arr[idx] = i;
//         partition(n - i, k, arr, idx + 1, i);
//     }
// }

// int main() {
//     int n = 6, k = 3;
//     int arr[k];
//     partition(n, k, arr, 0, n);
//     return 0;
// }


int count = 0;


// n: The number to be partitioned.
// k: The number of parts.
// idx: The current index in the partition.
// start: The maximum value that can be used in the current part of the partition.
// The partition function is a recursive function that generates all possible partitions of n into k parts. It takes the following parameters:

// In the partition function:
// If n is less than 0, it returns immediately because there's no valid partition.
// If n is 0 and idx is k, it means a valid partition of n into k parts has been found, so it increments count and returns.
// If idx is k but n is not 0, it means more than k parts are used, so it returns immediately.
// It then loops from start to 0, and makes a recursive call to partition with n - i, k, idx + 1, and i.
// In the main function, it reads n and k from the input, calls partition to count the number of partitions, and then prints the count.

void partition(int n, int k, int idx, int start) {
    if (n < 0) return; // dont add then TLE
    if (n == 0 && idx == k) {
        count++;
        return;
    }
    if (idx == k) return;
    for (int i = start; i >= 0; i--) {
        partition(n - i, k, idx + 1, i);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[k];
    partition(n, k, 0, n);
    printf("%d\n", count);
    return 0;
}

// 若有 n 個字元，輸出其所有排列方式。
// string str;

// void Perm(int i, int n){
//     if(i == n){
//         cout << str << "\n";
//     }
//     else{
//         for(int j=i; j<n; j++){
//             swap(str[i], str[j]); //把j字元換到開頭
//             Perm(i+1, n);         //剩下的字元作排列組合
//             swap(str[i], str[j]); //把j字元放回原位
//         }
//     }
// }