void swap(int*a , int*b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void Qsort(int*nums, int head, int tail){
    if ( head >= tail) return;
    //選pivot
    
    int mid = (head + tail )/ 2 ;
    if( *(nums + head) > *(nums + mid) ) swap(nums + head,nums + mid); 
    if( *(nums + head) > *(nums + tail) ) swap(nums + head, nums + tail); 
    if( *(nums + mid) > *(nums + tail) ) swap(nums + mid, nums + tail); 
    swap(nums + head , nums + mid );
    int pivot = *(nums + head);
    //開始
    int l = head + 1;
    int r = tail;
    while(l <= r){
        while( l <=r && *(nums + l) < pivot) l++;
        while( l <= r&& *(nums + r) > pivot) r--;
        if( l<=r){
            swap(nums + l,nums + r);
            l++;
            r--;
        }
        
    }
    swap(nums + head, nums + r);
    Qsort(nums, head , r -1);
    Qsort(nums, r + 1 , tail);
}

int majorityElement(int* nums, int numsSize) {
    Qsort(nums, 0 , numsSize - 1);
    return nums[numsSize/2];
}
