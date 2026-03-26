
//憂解
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        //邊界條件
        if (node == nullptr) return nullptr;
        // 節點已經複製過，直接回傳
        if (mp.count(node)) return mp[node];
        
        //這層: 複製節點
        // 建立新節點，並加入hash代表複製成功。
        Node* clone = new Node(node->val);
        mp[node] = clone;
        // 複製鄰居
        for (auto nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
