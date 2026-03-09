class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right =0;
        int left = 0;
        int n = s.size();
        bool A[128] = {false};
        int max_length =0 ;
        
        for (right =0;right<n;right++){
            char c = s[right];
            while(A[c] == true){
                A[s[left]] = false;
                left++;
            } 
            A[c] = true;
            max_length = max(max_length,right-left +1);
        }
        
        return max_length;
    }
};
