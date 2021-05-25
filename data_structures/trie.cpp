/**
 * Use as:
 * Trie* trie = new Trie();
 * trie->insert(word);
 * bool result1 = trie->search(word);
 * bool result2 = trie->startsWith(prefix);
 */

#define NUM_CHARS 256

struct TrieNode {
    TrieNode *children[NUM_CHARS] = {};
    bool terminal = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie();
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};

void Trie::insert(string word) {
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

Trie::Trie() {
    root = new TrieNode();
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
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

/** Returns if the word is in the trie. */
bool Trie::search(string word) {
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
