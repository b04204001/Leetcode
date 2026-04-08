/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Merge(int* nums ,int left , int mid , int right){
    int alen = mid - left + 1;
    int blen = right - (mid + 1) + 1;
    int A[alen];
    int B[blen];
    for(int i = 0 ; i<alen;i++){
        A[i] = nums[left + i];
    }
    for(int j = 0; j <blen;j++){
        B[j] = nums[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while( i< alen && j < blen){
        if( A[i] < B[j] ){
            nums[k++] = A[i++]; 
        }
        else{
            nums[k++] = B[j++]; 
        }
    }
    while(i < alen){
        nums[k++] = A[i++]; 
    }
    while(j<blen){
        nums[k++] = B[j++]; 
    }
    return ;
}
void Mergesort(int* nums ,int left , int right){
    if( left >= right) return;
    int mid = (left + right) /2;
    Mergesort(nums , left , mid);
    Mergesort(nums, mid + 1 , right);
    Merge(nums, left , mid , right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    Mergesort(nums , 0 , numsSize -1 );
    return nums;
}




//CHATGPT
#include <stdlib.h>

void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // merge 兩段
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // 剩餘補上
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // copy 回原陣列
    for (int p = left; p <= right; p++) {
        nums[p] = temp[p];
    }
}

void mergeSort(int* nums, int left, int right, int* temp) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid, temp);
    mergeSort(nums, mid + 1, right, temp);

    merge(nums, left, mid, right, temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* temp = (int*)malloc(sizeof(int) * numsSize);

    mergeSort(nums, 0, numsSize - 1, temp);

    free(temp);
    return nums;
}
