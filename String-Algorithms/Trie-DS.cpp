/*
 * Applications ->

 * Auto Complete
 * Spell Checkers
 * Longest Prefix matching
 * String Search in O(L) where L is the size of string to be searched in a set of words
 *
 *
 * Structure:
 * Trie DS is a k-n ary Tree(that means each child can have atmost k children)
 *
 * Value of 'k' depends upon the size of character set. (In lowercase it is 26)
 */
#include<bits/stdc++.h>
using namespace std;
// Structure of Trie
// I am assuming that I am working only on lowercase letters
const int SIZE = 26;
struct node{
    bool endOfWord; // This tells that whether there exists some string which stops on this particular node.

    node* arr[SIZE] = {nullptr};
    // This tells the relation of current node with the other nodes.
    // Suppose, from this node, I want to search that whether 'b' node exists
    // So, I will look into arr "node* array" and check ->
    // If It is null, then it doesn't exist, otherwise it exists
};
node* getNode() {
    node* n = new node;
    n -> endOfWord = false;

    for(int i = 0; i < SIZE; ++i) {
        (n -> arr)[i] = nullptr;
    }

    return n;
}
void insert(node* root, string& s) {
    node* tempRoot = root;

    for(int i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        if(tempRoot -> arr[index] == nullptr) {
            // There is no relation from current node to node with "index"
            // Therefore creating a relation
            tempRoot -> arr[index] = getNode();
        }
        
        // Moving to that node
        tempRoot = tempRoot -> arr[index];
    }
    // We are at the node where our whole string ends
    tempRoot -> endOfWord = true;
}
bool search(node* root, string& s) {
    node* tempRoot = root;

    for(int i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';

        if(tempRoot -> arr[index] == nullptr) return false;

        tempRoot = tempRoot -> arr[index];
    }
    return tempRoot -> endOfWord;
}
int main() {
    node* root = getNode(); // Root Node which should never be changed

    while(1) {
        cout << "\nEnter\n1. For Inserting a string in Trie DS\n\n2. For searching a string\n\n3. Exit\n\n";
        int t; cin >> t;
        if(t == 1) {
            string s; cin >> s;
            insert(root, s);
        }
        else if(t == 2) {
            string s; cin >> s;
            cout << search(root, s) << '\n';
        }
        else break;
    }
    return 0;
}
