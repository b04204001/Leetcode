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
