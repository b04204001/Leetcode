/*
想像成一個樹，往下有26條路，有一個單字近來，根據字母順序比如 a -> 有 a-z 26條路，apple的要找p那條路走，然後p再找p，用p - 'a'轉換成矩陣idx，職後字的結尾會再端點用bool設定這是一個單字的結尾
insert 插入首先用指標找到root，然後一個一個比對，如果是nullptr就建立新node，然後直到結尾調整end
search 依樣先找root，比對，如果nullptr回傳false，到底看isend就true。
start with 類似search但就不用看isEnd，
*/
class Trie {
    struct TrieNode {
        TrieNode* next[26]; // 每個點有 26 條出路
        bool isEnd;         // 是否是一個完整單字
        //初始化
        TrieNode() {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char w : word) {
            int idx = w - 'a';
            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char w : word) {
            int idx = w - 'a';
            if (cur->next[idx] == nullptr) return false;
            cur = cur->next[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char w : prefix) {
            int idx = w - 'a';
            if (cur->next[idx] == nullptr) return false;
            cur = cur->next[idx];
        }
        return true;
    }
};
