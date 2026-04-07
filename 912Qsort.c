/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int * a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void Qsort(int* nums ,int left , int right){
    if (left >= right) return;
    //選定中間
    
    //左中
    if( *(nums + left) > *(nums + (right + left)/2 )) {  
        swap((nums + left) , (nums + (right + left)/2 ) );
    }
    //左右
    if( *(nums + left) > *(nums + right) ){
        swap((nums + left) , (nums + right ));
    } 
    //中又
    if( *(nums + (right + left)/2 ) > *(nums + right)) {  
        swap((nums + (right + left)/2 ) , (nums + right) );
    }
    swap((nums + left) , (nums + (right + left)/2 ) );
    int pivot= *(nums + left);
    //開始n次
    int l = left + 1;
    int r = right;
    while( l <= r){
        while( l <= r && *(nums + r) > pivot){
            r--;
        }
        while(l <= r && *(nums + l) < pivot){
            l++;
        }
        if(l <= r){
            swap((nums + l) , (nums +r));
            l++;
            r--;
        }
    }
    swap(nums + left , nums + r);
    Qsort(nums , left , r-1 );
    Qsort(nums , r+1 , right);
    return;
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    Qsort(nums , 0 , numsSize -1 );
    return nums;
}
