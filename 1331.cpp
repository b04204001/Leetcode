class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        vector<int> sorted;
        sorted = arr;
        sort(sorted.begin(),sorted.end());

        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());


        for(int k = 0;k<n;k++){
            int i = 0;
            int j = sorted.size()-1;
            while(i <= j){
                int mid = (i + j) /2;
                if(sorted[mid] == arr[k]) {
                    ans[k] = mid +1;
                    break;
                }
                else if(sorted[mid] > arr[k]){
                    j = mid - 1;
                }
                else{
                    i = mid +1;
                }
            }
        }
        return ans;
    }
};
