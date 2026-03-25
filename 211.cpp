class WordDictionary {
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode() {
            for(int i=0;i<26;i++){
                next[i] = nullptr;
            }
            isEnd = false;
        }
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int idx = c - 'a';
            if(cur->next[idx] == nullptr){
                cur->next[idx] = new TrieNode;
            }
            cur = cur->next[idx];
        }
        cur->isEnd = true;
    }

    bool dfs(TrieNode* cur, string word,int k){
        //邊界
        if( cur == nullptr) return false;
        if( k == word.size()) return cur->isEnd;
        bool ans = false;
        //下層
        if(word[k] != '.'){
            int idx = word[k] - 'a';
            if(cur->next[idx] == nullptr){
                return false;
            }
            ans = ans || dfs(cur->next[idx],word,k+1);
        }
        // '.'可代表任何所以k+1
        else{
            for(int i =0;i<26;i++){
                if(cur->next[i] != nullptr){
                    ans = ans || dfs(cur->next[i],word,k+1);
                }
            }
        }

        return ans;
    }

    bool search(string word) {
        TrieNode* cur = root;
        return dfs(cur,word,0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
