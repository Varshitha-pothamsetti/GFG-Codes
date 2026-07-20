#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int freq;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        freq = 0;
    }
};

class Solution {
private:
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->freq++;
        }
    }
    
    string getUniquePrefix(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for(char ch : word) {
            prefix += ch;
            int index = ch - 'a';
            curr = curr->children[index];
            if(curr->freq == 1) {
                return prefix;
            }
        }
        return prefix;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        
        for(const string& word : arr) {
            insert(root, word);
        }
        
        vector<string> result;
        for(const string& word : arr) {
            result.push_back(getUniquePrefix(root, word));
        }
        
        return result;
    }
};