class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
         map<int,int> count;
         for(int x: nums){
             count[x]++;
         }
         for (auto i : count){
             if(i.second==1){
                return i.first; 
             }
         }
        return 0;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0 ;i<n;i++){
            sum ^= nums[i];
        }
        return sum;
    }
};
用XOR，A ^ A 會變成0，同時有交換率，所以可以倆倆抵銷，所以對奇數次無效。
