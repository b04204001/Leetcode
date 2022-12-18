class MyQueue {
     
public:
    int A[9];
    int front;
    int end;

    MyQueue() {
       A[9];
       front =0;
       end =0;        
    }
    
    void push(int x) {
        A[end] = x;
        end++;
    }
    
    int pop() {
        int temp = A[front];
        front++;
        return temp;
    }
    
    int peek() {

        return A[front];
    }
    
    bool empty() {
        if(front == end)
            return true;
        else
            return false;
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
