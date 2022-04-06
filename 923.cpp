// 0407 daily
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long ans=0;
        int find;
        int mod = 1000000007;
        vector<long> count(101,0);
        for(int i : A ) count[i]++;//把counting sort概念把數字擺好
        for(int i=0;i< 101;i++){ //跑一圈
            for(int j= i ;j< 101;j++){ //跑一圈
                find = target -i-j; //選好兩個找剩下的
                if(find <0 || find>100) continue; //不存在
                if(i== j && find == j){    
                    ans += (count[i] *(count[i]-1 )*(count[i] -2))/6;
                }
                else if(i== j && find != j){ //兩同
                    ans += count[find] *(count[j]*(count[j] -1))/2;
                }
                else if(i <j && j<find ){//三種不同
                    ans += count[i] *count[j] *count[find];
                }
                 ans %= mod;
            }
        }
        
        return ans;
    }
};
