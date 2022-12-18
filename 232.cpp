class MyQueue {
     
public:
    stack<int> Q;

    MyQueue() {
    
    }
    
    void push(int x) {
        Q.push(x);
    }
    
    int pop() {
        stack<int> St;
        int n = Q.size();
        for(int i=0;i<n-1;i++){
            int temp = Q.top();
            Q.pop();
            St.push(temp);
        }
        int target = Q.top();
        Q.pop();
        for(int i=0;i<n-1;i++){
            int re = St.top();
            St.pop();
            Q.push(re);
        }
        return target;
    }
    
    int peek() {
        stack<int> St;
        int n = Q.size();
        for(int i=0;i<n-1;i++){
            int temp = Q.top();
            Q.pop();
            St.push(temp);
        }
        int target = Q.top();
        Q.pop();
        St.push(target);
        for(int i=0;i<n;i++){
            int rp = St.top();
            St.pop();
            Q.push(rp);
        }
        return target;
    }
    
    bool empty() {
        if(Q.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
