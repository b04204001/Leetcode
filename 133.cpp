
//憂解
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if (node == nullptr) return nullptr;

        // 已經複製過，直接回傳
        if (mp.count(node)) return mp[node];

        // 建立新節點
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
