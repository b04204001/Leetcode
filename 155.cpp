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
            if (val < stack[top_id]){
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
