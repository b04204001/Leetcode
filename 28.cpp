class Solution {
public:
    int strStr(string haystack, string needle) {
        bool a = false;
        int ans;
        for(int i=0;i<haystack.length();i++){
            for(int j=0;j<needle.length();j++){
                if(haystack[i] != needle[0]){
                    break;
                }
                if(haystack[i+j] == needle[j]){
                        a = true;
                }
                else{
                    a= false;
                    break;
                }
                if( (j == needle.length()-1 ) && a == true  ){
                    return i;
                }
                
            }
        }
        return -1;
    }
};
