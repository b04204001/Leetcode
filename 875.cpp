class Solution {
public:
    bool caneat(vector<int>& piles , int speed, int h){
        int time =0;
        for(int pile : piles){
            time += (pile-1)/speed + 1;
            if(time >h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int n = piles.size();
        int right = piles[0];
        for(int i=0;i<n;i++){
            if(piles[i] > right){
                right = piles[i];
            }
        }

        while(left < right){
            int mid = (right + left)/2;
            if(caneat(piles,mid,h)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        
        return left;
    }
};



