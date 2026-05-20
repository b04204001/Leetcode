class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> common;
        int n = A.size();
        int count[50] = {0};
        for(int i =0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<=i;j++){
                count[A[j]]++;
            }
            for(int j = 0;j<=i;j++){
                if(count[B[j]] >0){
                    cnt++;
                    count[B[j]]--;
                }
            }
            common.push_back(cnt);
        }
        return common;
    }
};
