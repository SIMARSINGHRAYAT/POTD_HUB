class TrieNode {
public:
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    string longestString(vector<string> &words) {
        // Sort for lexicographical order handling
        sort(words.begin(), words.end());

        TrieNode* root = new TrieNode();
        string result = "";

        for (const string& word : words) {
            if (insertAndCheck(root, word)) {
                if (word.length() > result.length()) result = word;
            }
        }
        return result;
    }

private:
    bool insertAndCheck(TrieNode* root, const string& word) {
        TrieNode* node = root;
        bool allPrefixesPresent = true;

        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];

            // Check if current prefix was previously inserted as a complete word
            if (i < word.length() - 1 && !node->isEnd) {
                allPrefixesPresent = false;
            }
        }

        node->isEnd = true;
        return allPrefixesPresent;
    }
};
