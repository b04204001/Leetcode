class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //對速率做二分搜尋，找符合條件的
        int i = 1;
        int j = *max_element(piles.begin(),piles.end());
        int speed = j;
        while(i <= j){
            int mid = i + (j-i)/2;
            long long total_h = 0;
            for(auto p :piles){
                total_h += (p + mid -1) / mid;
            }
            if(total_h <= h){
                speed = mid;
                j = mid -1;
                
            }
            else{
                i = mid +1;
            }
        }
        return speed;
    }
};
