//20220408 daily
class KthLargest {
    vector<int> n;
    int i;
public:
    KthLargest(int k, vector<int>& nums) {
        n = nums;
        i = k;
        sort(n.begin(),n.end());
    }
    
    int add(int val) {
        auto it = lower_bound(n.begin(), n.end(), val);
        n.insert(it, val);
        return n[n.size()-i];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums) {
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
