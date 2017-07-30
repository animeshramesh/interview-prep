class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd; // Denotes whether node is a leaf

    TrieNode(bool end=false) {
        memset(children,NULL,sizeof(children));
        isEnd=end;
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroy(root);
    }
    
    // Delete nodes from bottom up
    void destroy(TrieNode* node) {
        for(int i=0;i<26;i++)
            if(node->children[i]) 
                destroy(node->children[i]);
        delete node;
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* run = root;
        for (char c : word) 
        {
            if (!(run -> children[c - 'a'])) 
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* node=root;
        for(int i=0;i<key.size();i++)
            if(node->children[key[i]-'a']==NULL)
                return false;
            else
                node=node->children[key[i]-'a'];
        return node->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++)
            if(node->children[prefix[i]-'a']==NULL)
                return false;
            else
                node=node->children[prefix[i]-'a'];
        return true;
    }
private:
    TrieNode* root;
};