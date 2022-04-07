//1046  0407 daily
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end(), less<int>());
        //sort_heap(stones.begin(), stones.end(), less<int>());
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
