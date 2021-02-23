class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return true;
    }

public:
    Trie* next[26] = {};
    bool isword = false;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      Trie* t = new Trie();
      for (string word: words) t -> insert(word);
      vector<string> res;
      vector<char> cur;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                dfs(t, board, res, i, j, cur);
            }
        }
      
      return res;
    }
private:
    unordered_set<string> seen;
    void dfs(Trie* t, vector<vector<char>>& board, vector<string>& res, int i, int j, string word) {
      if (i >= board.size()||i < 0||j >= board[0].size()||j < 0||board[i][j] == '*'||!t -> next[board[i][j] - 'a']) return;

      word = word + board[i][j];
      t = t->next[board[i][j] - 'a']
        
      if (t -> isword & !seen.count(word)) {
        res.push_back(word);
        seen.insert(word)
      }

      char prevChar = board[i][j];
      board[i][j] = '*';


      dfs(t, board, res, i+1, j, cur);
      dfs(t, board, res, i-1, j, cur);
      dfs(t, board, res, i, j+1, cur);
      dfs(t, board, res, i, j-1, cur);

      board[i][j] = prevChar;
    }
};
