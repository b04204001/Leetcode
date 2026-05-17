class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> visited(n, false); 
        visited[start] = true;

        while(!q.empty()){
            int levelsize = q.size();
            for(int i = 0;i<levelsize;i++){
                int cur = q.front();
                q.pop();
                if( arr[cur] == 0) return true;
                int right = cur + arr[cur];
                if(right < n && !visited[right]){
                    q.push(right);
                    visited[right] = true;
                }
                int left = cur - arr[cur];
                if(left >= 0 && !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
            }
        }
        return false ;
    }
};
