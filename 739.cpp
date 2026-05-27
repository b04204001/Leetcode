//TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(temperatures[j] > temperatures[i]){
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};

//正解
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        stack<int> st;
        st.push(0);
        for(int i = 1;i<n;i++){
            while(!st.empty() && temperatures[i] > temperatures[ st.top()]){
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx;
            }
            st.push(i);
        }
        return answer;
    }
};
