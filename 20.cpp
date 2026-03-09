class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for (char a : s){
            if( a == '(' || a == '['  || a == '{' ){
                temp.push(a);
            }
            else{
                if (temp.empty()){
                    return false;
                }
                char b = temp.top();
                if(abs((b - a)) > 2 ){
                    return false;
                }
                temp.pop();
            }
        }
        if (!temp.empty()) {
            return  false;
        }
        return true;
    }
};
