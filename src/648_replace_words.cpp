class TrieNode {
public:
  bool isword;
  string str;
  TrieNode *next[26];
  TrieNode() {
    memset(next, 0, sizeof(next));
    isword = false;
  }
  ~TrieNode() {}
};
class Trie {
public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete root; }
  void buildTree(vector<string> &dict) {
    for (const string &s : dict) {
      TrieNode *cur = root;
      for (const char &c : s) {
        if (cur->next[c - 'a'] == nullptr) {
          cur->next[c - 'a'] = new TrieNode();
          cur = cur->next[c - 'a'];
        } else if (cur->next[c - 'a']->isword ==
                   true) { // if a shorter root exists, we just stop build
          cur = nullptr;
          break;
        } else
          cur = cur->next[c - 'a'];
      }
      if (cur != nullptr) { // mark the string and flag
        cur->isword = true;
        cur->str = s;
      }
    }
    return;
  }
  string replace(string s) {
    TrieNode *cur = root;
    string res = "";
    for (char c : s) {
      cur = cur->next[c - 'a'];
      if (cur == nullptr)
        break;
      if (cur->isword == true) {
        res = cur->str;
        break;
      }
    }
    if (res != "")
      return res;
    return s;
  }

private:
  TrieNode *root;
};

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    stringstream sen(sentence);
    string res = "";
    string token;
    Trie tree;
    tree.buildTree(dictionary);
    while (getline(sen, token, ' ')) {
      res += tree.replace(token);
      res += " ";
    }
    return res.substr(0, res.size() - 1);
  }
};

