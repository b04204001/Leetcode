//1046  0407 daily
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end(), less<int>());
        sort_heap(stones.begin(), stones.end(), greater<int>()); 
        int max1,max2;
        while(stones.size() >1){
            max1 = stones[0];
            pop_heap(stones.begin(), stones.end(), less<int>());
            stones.pop_back();
            max2 = stones[0];
            pop_heap(stones.begin(), stones.end(), less<int>());
            stones.pop_back();
            if(max1 != max2){
                stones.push_back(abs(max1-max2)  );
                push_heap(stones.begin(), stones.end(), less<int>());
            }
        }
        return stones.size() ? stones.front() : 0;
    }
};


//
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s : stones){
            pq.push(s);
        }
        //priority_queue<int> pq(stones.begin(), stones.end());  //這樣似乎更快 
        while(pq.size() > 1){
            int m = pq.top();
            pq.pop();
            int n = pq.top();
            pq.pop();
            if(m-n != 0) pq.push((m-n));
        }
        if(!pq.empty()) return pq.top() ;
        return 0;
    }
};
