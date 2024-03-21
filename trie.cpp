#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
  bool isEndOfWord;
  TrieNode* children[26];
};

TrieNode* getNewNode() {
  TrieNode* newNode = new TrieNode();
  newNode->isEndOfWord = false;

  for(int i = 0;i<26;++i) newNode->children[i] = NULL;

  return newNode;
}

TrieNode* root = getNewNode();

void insert(string &word) {
  int n = word.length();

  TrieNode* p = root;

  for(int i = 0;i<n;++i) {
    int idx = word[i] - 'a';

    if(p->children[idx] == NULL) p->children[idx] = getNewNode();

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

int main() {
    string s = "raja";
    insert(s);

    cout << startsWith("raj");
}