//easy
class Solution {
public:
    bool isPalindrome(int x) {
    string num = to_string(x);
    string re = to_string(x);
    int y= num.length();
    reverse(re.begin() , re.end());
    if( num.compare(re) ==0){
        return true;
    }
    else{
        return false;
    }

}

    
};
