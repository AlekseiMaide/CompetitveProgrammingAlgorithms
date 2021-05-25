#define NUM_CHARS 256

struct TrieNode {
    TrieNode *children[NUM_CHARS] = {};
    bool terminal = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int N = word.size();
        TrieNode *tmp = root;
        
        for (int i = 0; i < N; i++) {
            if (tmp->children[word[i]] == NULL) {
                tmp->children[word[i]] = new TrieNode();
            }
            
            tmp = tmp->children[word[i]];
        }
        
        tmp->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int N = word.size();
        TrieNode *tmp = root;
        
        for (int i = 0; i < N; i++) {
            if (tmp->children[word[i]] == NULL) {
                return false;
            }
            
            tmp = tmp->children[word[i]];
        }
        
        return tmp->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int N = prefix.size();
        TrieNode *tmp = root;
        
        for (int i = 0; i < N; i++) {
            if (tmp->children[prefix[i]] == NULL) {
                return false;
            }
            
            tmp = tmp->children[prefix[i]];
        }
        
        return true;
    }
};
