#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *res = malloc(numsSize * sizeof(int));
    if (!res) return NULL;
    res[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        res[i] = nums[i] + res[i - 1];
    }
    return res;
}

int main() {
    return 0;
}