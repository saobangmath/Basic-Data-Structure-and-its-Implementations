#include <bits/stdc++.h>
const int ALPHABET_SIZE = 26;
using namespace std;
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord ;
};
TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode();
    pNode->isEndOfWord = false;
    for(int i = 0; i< ALPHABET_SIZE;i++){
        pNode->children[i] = NULL;
    }
    return pNode;
};
void insertTrie(struct TrieNode *root, std::string key){
    struct TrieNode *p = root;
    for (int i= 0; i < key.length();i++){
        int index = key[i] - 'a';
        if (! p->children[index]){
            p->children[index] = getNode();
        }
        p = p->children[index];
    }
    p->isEndOfWord = true;
};
bool searchTrie(struct TrieNode *root,std::string key){
  struct TrieNode *p = root;
  for (int i = 0; i<key.length() ;i++){
    if (!p->children[i]){
        return false;
    }
    else{
        p = p->children[i];
    }
  }
  return (p!=NULL && p->isEndOfWord);
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
