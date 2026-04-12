/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));
    for(int i = 0;i<numsSize;i++){
        int diff = target - nums[i];
        for(int j = i + 1 ; j< numsSize;j++){
            if( diff == nums[j]){
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
