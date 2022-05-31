class Solution {
public:
    bool isValid(string s) {
        stack<char> r;
        bool ans =true;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                r.push('(');
            }
            if(s[i] == '['){
                r.push('[');
            }
            if(s[i] == '{'){
                r.push('{');
            }
            if(s[i] == ')'){
                if(!r.empty() ){
                    if(r.top() == '(' ) 
                        r.pop();
                     else{
                        ans = false;
                    }
                }
                else
                    ans =false;
            }
            if(s[i] == ']'){
                if(!r.empty() ){
                    if(r.top() == '[' ) 
                        r.pop();
                    else{
                        ans = false;
                    }
                }
                else 
                    ans =false;
            }
            if(s[i] == '}'){
                if(!r.empty() ) {
                    if(r.top() == '{' ) 
                        r.pop();
                     else{
                        ans = false;
                    }
                }
                else
                    ans =false;
            }
            
        }
        if(r.empty() && ans == true){
            return true;
        }
        else{
            return false;
        }
    }
};
