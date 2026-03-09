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



最優解:
class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        
        for (char a : s) {
            // 1. 遇到左括號：我們把「預期的右括號」推進罐子裡
            if (a == '(') {
                temp.push(')');
            } 
            else if (a == '[') {
                temp.push(']');
            } 
            else if (a == '{') {
                temp.push('}');
            } 
            // 2. 遇到右括號：準備驗證！
            else {
                // 【防護罩】如果罐子已經空了（代表右括號太多），或者跟預期的不符
                if (temp.empty() || temp.top() != a) {
                    return false; // 直接判死刑
                }
                // 驗證通過，把最上面的預期括號丟掉
                temp.pop();
            }
        }
        
        // 3. 全部跑完後，罐子必須是空的（代表所有左括號都有找到伴）
        return temp.empty(); 
    }
};
