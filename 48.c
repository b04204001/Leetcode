void swap(int*a , int*b){
    int temp = *a;
    *a= *b;
    *b = temp;
}
void reverse(int*a , int*b){
    while(a<b){
        swap(a,b);
        a++;
        b--;
    }
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    //1. 主對角線」對摺   
    for(int i = 0;i<matrixSize;i++){
        for(int j = i+1;j<matrixSize;j++){
            swap(&matrix[i][j],&matrix[j][i]);
        }
    }
    //2. 把每一列 (Row)「左右水平翻轉」 (Reverse)
    for(int i = 0;i<matrixSize;i++){
        reverse(&matrix[i][0],&matrix[i][matrixColSize[i]-1]);
    }

}
