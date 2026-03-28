概念: Graph 裡有沒有 cycle？
1. 找沒有前置課的
2. 修掉它
3. 影響其他課（indegree--）
4. 新的 0 再加入 queue
5. 看能不能修完全部



//優解
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //用adjacency list
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        //建立先後關係，indegree負責找可直接修，graph是adjacency list，負責前置關係
        for(auto p : prerequisites){
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        //BFS 用 queue
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
            //pop = 修掉，並把所有相關課程前置-1，
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
