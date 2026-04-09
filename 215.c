void swap(int* a , int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* nums, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && nums[left] > nums[largest]) largest = left;
    if(right < n && nums[right] > nums[largest]) largest = right;
    if(largest != i){
        swap(nums + i,nums + largest);
        heapify(nums, n, largest );
    }
    return;
}
int findKthLargest(int* nums, int numsSize, int k) {
    //建立max heap
    for(int i = numsSize/2 -1 ;i >=0;i-- ){
        heapify(nums,numsSize,i);
    }
    //swap
    for(int i = 0;i<k-1;i++){
        swap(nums ,nums + numsSize - 1 - i );
        heapify(nums,numsSize-1-i, 0);
    }
    return nums[0];
}
