//20220422
class MyHashMap {
public:
    int A[1000001][2];
    MyHashMap() {
        int A[1000001][2];
    }
    
    void put(int key, int value) {
        if(A[key][0] ==1){
            A[key][1] = value;
        }
        else{
            A[key][0]=1;
            A[key][1] = value;
        }
    }
    
    int get(int key) {
        if(A[key][0]==1){
            return A[key][1];
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        A[key][0] =0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
