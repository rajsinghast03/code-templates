#include<bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
  bool isEndOfWord;
  TrieNode* children[26];

  TrieNode() {
    isEndOfWord = false;
    for(int i = 0;i<26;++i) children[i] = NULL;
  }
};

class TrieHelper{
  private:
   TrieNode* root;
  public:
    TrieHelper() {
      root = new TrieNode();
    }

  void insert(string &word) {
  int n = word.length();

  TrieNode* p = root;

  for(int i = 0;i<n;++i) {
    int idx = word[i] - 'a';

    if(p->children[idx] == NULL) p->children[idx] = new TrieNode();

    p = p->children[idx];
  }

  p->isEndOfWord = true;
}

  bool search(string &word) {
   int n = word.length();

  TrieNode* p = root;

  for(int i = 0;i<n;++i) {
    int idx = word[i] - 'a';

    if(p->children[idx] == NULL) return false;

    p = p->children[idx];
  }

  return p->isEndOfWord = true;
}

bool startsWith(string word) {
   int n = word.length();

  TrieNode* p = root;

  int i = 0;

  for(;i<n;++i) {
    int idx = word[i] - 'a';

    if(p->children[idx] == NULL) return false;

    p = p->children[idx];
  }

  return i == n;
}

};

int main() {
    TrieHelper hp;
    string s = "raja";
    hp.insert(s);
   cout <<  hp.startsWith("raj");
}