#include <stdio.h>
#include <stdlib.h>

int n, k;
int combinations = 0;

void choose(int money, int* bags, int bag_n, int bag_index) {
    if (money == k) {
        combinations++;
        return;
    }
    if (money > k || bag_index >= bag_n) {
        return;
    }

    // Include the current bag in the combination
    choose(money + bags[bag_index], bags, bag_n, bag_index + 1);

    // Exclude the current bag and move to the next bag
    choose(money, bags, bag_n, bag_index + 1);
}

int main() {
    scanf("%d", &n);
    int* bags = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &bags[i]);
    scanf("%d", &k);

    choose(0, bags, n, 0);
    printf("%d\n", combinations);

    free(bags);
    return 0;
}
