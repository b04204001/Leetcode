//自己想
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n,n);
        mins[0] = 0;
        for(int i=0;i<n-1;i++){
            for(int j = 1 ; j <=nums[i];j++){
                if( (i + j) < n){
                    mins[i+j] = min( mins[i]+1  , mins[i+j] );
                }
            }
        }
        return mins[n-1];
    }
};

//最優解
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;       // 總共跳了幾次
        int current_end = 0; // 目前這一次跳躍的「勢力範圍邊界」
        int farthest = 0;    // 雷達探勘到「下一跳的最遠極限」
        
        // ✨ 神細節：迴圈只走到 n - 2！
        // 因為如果你已經踩在最後一格 (n - 1)，就不需要再起跳了
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // 沿路探勘：更新下一跳到底能多遠？
            farthest = max(farthest, i + nums[i]);
            
            // 走到目前這跳的邊界了！強迫結算！
            if (i == current_end) {
                jumps++;                 // 跳躍次數 + 1
                current_end = farthest;  // 勢力範圍擴張到剛剛探勘的最遠極限
                
                // 業界微調：如果勢力範圍已經涵蓋終點，可以直接提早收工
                if (current_end >= nums.size() - 1) break; 
            }
        }
        
        return jumps;
    }
};
