class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf{};
    TrieNode() {
        isLeaf = false;
        for (size_t i{0}; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                curr->children[c-'a'] = newNode;
            }

            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }

    int lcp(const string& word, int prefixLen) {
    TrieNode* node = root;
    int i = 0;
    while (i < min((int)word.length(), prefixLen)) {
        int idx = word[i] - 'a';
        if (node->children[idx] == nullptr) return i;
        node = node->children[idx];
        i++;
    }
    return min((int)word.length(), prefixLen);
}


};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 1) {
            return strs[0];
        }
        int mini = 0;
        for (int i = 1; i < strs.size(); i++) {
            if (strs[mini].size() > strs[i].size()) {
                mini = i;
            }
        }
        
        Trie trie{};
        trie.insert(trie.root, strs[mini]);
        int prefixLen = strs[mini].length();

        for (size_t i{0}; i < strs.size(); i++) {
            prefixLen = trie.lcp(strs[i], prefixLen);
        }
        


        return strs[0].substr(0, prefixLen);
    }
};