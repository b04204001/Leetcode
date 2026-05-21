class Solution {
public:
    int countdigit(int i){
        int len = 0;
        while( i > 0){
            i/=10;
            len++;
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int max_len = 0;
        for(auto a : arr1){
            int len = countdigit(a);
            for(int i = 0;i<len;i++){
                int prefix = a/(pow(10,i));
                if(!mp1.count(prefix)){
                    mp1[prefix] = len - i;
                }
            }
        }
        for(auto a : arr2){
            int len = countdigit(a);
            for(int i = 0;i<len;i++){
                int prefix = a/(pow(10,i));
                if(!mp2.count(prefix)){
                    mp2[prefix] = len - i;
                }
            }
        }

        for(auto pair : mp1){
            if(mp2.count(pair.first)){
                max_len = max(max_len , pair.second);
            }
        }

        return max_len;
    }
};
