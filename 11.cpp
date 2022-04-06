class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        else{
        int left = 0;
        int right = height.size() - 1;
        int maxa = 0;
        while(left < right){
            int w = (right - left);
            int h = min(height[left], height[right]);
            int area = w * h;
            maxa = max(maxa, area);
            if(height[left] < height[right]) 
                left++;
            else if(height[left] > height[right]) 
                right--;
            else{
                left++;
                right--;
            }
        }
        return maxa;
        }
    }
};
