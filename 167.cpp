20220609
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int k = numbers[i] + numbers[j];
            if(k<target){
                i++;
            }
            else if(k>target){
                j--;
            }
            else{
               ans = {i+1,j+1};
               return ans; 
            }
        }
        return ans;
    }
};
