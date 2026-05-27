class MinStack {
public:
    vector<int> stack;
    vector<int> min_stack;
    int top_id = -1;
    
    MinStack() {
    }
    
    void push(int val) {   
        stack.push_back(val);
        if ( top_id == -1){
            min_stack.push_back(val);
        }
        else{
            if (val < min_stack[top_id]){
                min_stack.push_back(val);
            }
            else{
                min_stack.push_back(min_stack[top_id]);
            }
        }
        top_id++;
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
        top_id--;
    }
    
    int top() {
        return stack[top_id];
    }
    
    int getMin() {
        return min_stack[top_id];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

更好:
class MinStack {
public:
    vector<int> st;
    vector<int> min_st;

    MinStack() { }
    
    void push(int val) {
        st.push_back(val);
        // 當 min_st 為空，或者新值小於等於當前最小值時，才寫入 min_st
        if (min_st.empty() || val <= min_st.back()) {
            min_st.push_back(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        // 如果要彈出的值正好是當前最小值，min_st 也要跟著彈出
        if (st.back() == min_st.back()) {
            min_st.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back(); // 根據 LeetCode 題目要求，呼叫 top 時堆疊必不為空
    }
    
    int getMin() {
        return min_st.back();
    }
};

