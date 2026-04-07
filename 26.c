int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    int slow =0 ;
    for(int fast = 0;fast<numsSize;fast++){
        if( *(nums + slow) != *(nums + fast)){
            slow++;
            *(nums + slow) = *(nums + fast);
        }
    }
    return slow + 1;
}
