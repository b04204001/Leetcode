class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int A[10000];
        int j=0;
        for(int i=0; i<s.length();i++){
            ans++;
            if( s[i] == ' ' ){
                A[j] =ans-1;
                j++;
                ans =0;
            }
        }
        while(ans ==0){
            ans = A[j-1];
            j--;
        }
        return ans;
    }
};

