// 682 daily 0410
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        stack <int> stk;
        for(int i=0;i< ops.size();i++){
            if( ops[i] == "C"){
                stk.pop();
            }
            else if( ops[i] == "D"){
                int t0 = stk.top();
                stk.pop();
                int y = t0*2;
                stk.push(y);
            }
            else if (ops[i] == "+"){
                int t1 = stk.top();
                stk.pop();
                int t2 = stk.top();
                stk.pop();
                int t3 = t1+t2;
                stk.push(t1);
                stk.push(t2);
                stk.push(t3);
            }        
            else{
                stk.push(stoi(ops[i]));
            }
        }
        while(!stk.empty()){
            int x = stk.top();
            ans += x;
            stk.pop();
        }
        return ans;
    }
    
};

//wrong
