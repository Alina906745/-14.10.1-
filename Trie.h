#pragma once
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;


struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, string&);
bool isUnic(TrieNode* root);
vector<string> allWordsByPrefix(TrieNode*, string&);
void fillVector(struct TrieNode* root, vector<string>& result, char buf[], int ind);