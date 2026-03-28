概念:
1. 找沒有前置課的
2. 修掉它
3. 影響其他課（indegree--）
4. 新的 0 再加入 queue
5. 看能不能修完全部
  

//優解
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto p : prerequisites){
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            count++;

            for(auto nei : graph[cur]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};
