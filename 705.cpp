//20220421 daily
class MyHashSet {
    int A[1000001];
public:
    MyHashSet() {
        int A[1000001];
    }
    
    void add(int key) {
        A[key]=1;
    }
    
    void remove(int key) {
        A[key]=0;
    }
    
    bool contains(int key) {
        if(A[key] >0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
