#include "Trie.h"
#include <iostream>
#include "Trie.h"

using namespace std;


TrieNode* getNewNode(void)
{
  
    struct TrieNode* pNode = new TrieNode;

    
    pNode->isEndOfWord = false;

   
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        
        int index = key[i] - 'a';

        
        if (!node->children[index]) {
            node->children[index] = getNewNode();
        }
        node = node->children[index];
    }
    
    node->isEndOfWord = true;
}


bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


TrieNode* remove(TrieNode* root, string key, int depth)
{
   
    if (!root)
        return nullptr;

    if (depth == key.size()) {

        
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false)
    {
        delete (root);
        root = nullptr;
    }

   
    return root;
}

void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res)
{
    if (root == nullptr)
        return;

    if (isUnic(root)) {
        buf[ind] = '\0';
        res += buf;
        res += " ";
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            buf[ind] = i + 'a';
            findMinPrefixes(root->children[i], buf, ind + 1, res);
        }
    }
}

bool isUnic(TrieNode* root) {
    if (isEmpty(root))
        return true;

    int childCount = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr)
            childCount++;
    }
    if (childCount > 1)
        return false;
    if (childCount == 1 && root->isEndOfWord)
        return false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            return isUnic(root->children[i]);
        }
    }
    return false;
}

vector<string> allWordsByPrefix(struct TrieNode* root, string& prefix)
{
    vector<string> result;
    struct TrieNode* node = root;
    char buf[ALPHABET_SIZE];
    int ind = 0;

    for (int i = 0; i < prefix.length(); i++)
    {
        int index = prefix[i] - 'a';
        buf[ind] = prefix[i];
        ind++;
        if (!node->children[index])
            return result;

        node = node->children[index];
    }
    fillVector(node, result, buf, ind);
    return result;
}

void fillVector(struct TrieNode* root, vector<string>& result, char buf[], int ind) {
    if (root->isEndOfWord) {
        buf[ind] = '\0';
        result.push_back(buf);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            buf[ind] = i + 'a';
            fillVector(root->children[i], result, buf, ind + 1);
        }
    }
}