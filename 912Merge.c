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
