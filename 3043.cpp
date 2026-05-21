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


//hash set法
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // 1. 將 arr1 的所有數字及其所有前綴加入集合
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }
        
        int max_len = 0;
        
        // 2. 檢查 arr2 的數字前綴是否在集合中
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {
                    // 數字轉字串的長度等於 log10(val) + 1
                    int len = to_string(val).length(); 
                    max_len = max(max_len, len);
                    break; // 找到目前數字的最長前綴，更短的不用再找了
                }
                val /= 10;
            }
        }
        
        return max_len;
    }
};
