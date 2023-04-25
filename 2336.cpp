class SmallestInfiniteSet {
public:
    set<int> set;
    int current;
    SmallestInfiniteSet() {
        current =1;
    }
    
    int popSmallest() {
        if(set.size()){
            int temp = *set.begin();
            set.erase(temp);
            return temp;
        }
        else{
            current++;
            return current-1;
        }
        
    }
    
    void addBack(int num) {
        if(current>num)
            set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

