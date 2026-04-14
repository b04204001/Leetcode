/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Getdigit(int n ,int e){
    return (n / e) % 10;
}
void Radixsort(int* nums, int n){
    //找最小
    int min = nums[0];
    for(int i = 0;i<n;i++){
        if( nums[i] < min) min = nums[i];
    }
    //處理負數
    for(int i = 0;i<n;i++){
        nums[i] -= min;
    }
    //找最大
    int max = nums[0];
    for(int i = 0;i<n;i++){
        if( nums[i] > max) max = nums[i];
    }
    // 從最低位開始排序
    for(int exp = 1; max/exp > 0;exp *=10){
        // 計數每個位數的值
        int output[n];
        int count[10] = {0};
        for(int i = 0;i<n;i++){
            int digit = Getdigit( nums[i] , exp);
            count[digit]++;
        }
        // 累計計數
        for(int i = 1;i<10;i++){
            count[i] += count[i-1];
        }
        // 建構輸出陣列
        for(int i = n-1;i>=0;i--){
            int digit = Getdigit( nums[i] , exp);
            //因為count是個數，所以要-1變index
            output[count[digit]-1] = nums[i];
            count[digit]--;
        }

        // 複製回原陣列
        for(int i = 0;i<n;i++){
            nums[i] = output[i];
        }
    }
    //還原
    for(int i = 0;i<n;i++){
        nums[i] += min;
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    Radixsort(nums , numsSize );
    return nums;
}
