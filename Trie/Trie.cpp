/*
Suppose we are given a list of words:
words[] = ["apple", "mango", "not", "no", "news", "code"]

Suppose, you are given a word, and you want to know whether
this exists in the "words" array

Naive Approach: Do a linear search and look for each word, whether
it matches with the given word
Time Complexity: O(words.size() * word.size())

Using a Balanced Binary Search Tree:
In this, the time complexity would be: O(word.size() & log(words.size()))

Using a Trie:
The complexity would be: O(word.size())

Trie is Efficient!!

But:
	-> It uses more space
	-> Requires Precomputation
	
Structure of a node:
node [
	char data;
	hashmap (key, node*); // This will help to know the node* for a parti
	// cular key
	bool isTerminal;
]
*/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	char data;
	node* h[26] {nullptr};
	bool isTerminal;
	
	node(char d) {
		data = d;
		isTerminal = false;
	}
};

class Trie {
private:
	node* root;
	
public:
	Trie() {
		root = new node('\0');
	}
	
	// Adding a Word in Trie
	void addWord(string s) {
		node* temp = root;
		
		for(int i = 0; i < s.size(); ++i) {
			if(temp->h[s[i] - 'a'] == nullptr) {
				temp->h[s[i] - 'a'] = new node(s[i]);
			}
			temp = temp -> h[s[i] - 'a'];
		}
		temp -> isTerminal = true;
	}
	
	bool search(string s) {
		node* temp = root;
		
		for(int i = 0; i < s.size(); ++i) {
			if(temp->h[s[i] - 'a'] == nullptr) return false;
			
			temp = temp->h[s[i] - 'a'];
		}
		
		return temp->isTerminal;
	}
	
	void remove(string word) {
		node* temp = root;
		
		vector<node*> v = {root};
		for(int i = 0; i < word.size(); ++i) {
			if(temp -> h[word[i] - 'a'] == nullptr) return;
			
			temp = temp -> h[word[i] - 'a'];
			v.push_back(temp);
		}
		
		v[v.size() - 1] -> isTerminal = false;
		
		for(int i = (int)v.size() - 2; i >= 0; --i) {
			// How to know whether a node should be deleted or not!
			// It can be deleted if:
			// 1. It's "isTerminal" is false
			// 2. All the child of the node should be "nullptr"
			
			node* ptr = v[i + 1];
			bool del = true;
			
			del &= (!ptr -> isTerminal);
			
			for(int j = 0; j < 26; ++j) {
				del &= (ptr -> h[j] == nullptr);
			}
			if(del) {
				v[i] -> h[ptr -> data - 'a'] = nullptr;
				delete ptr;
			}
			else break;
		}
	}
};

int main() {
	Trie t;
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		string s; cin >> s;
		t.addWord(s);
	}
	int q; cin >> q;
	while(q--) {
		string x; cin >> x;
		cout << boolalpha << t.search(x) << endl;
	}
	return 0;
}
