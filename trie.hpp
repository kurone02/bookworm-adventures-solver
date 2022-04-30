#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <cstdio>
#include <string>
#define self (*this) 
using namespace std;

const int ALPHABET_SIZE = 26;

/*
    Declaration
*/

class Trie{
public:
    struct Node{
        int cnt; bool is_leaf;
        Node *child[ALPHABET_SIZE];

        Node(){
            cnt = 0; is_leaf = false;
            for(int i = 0; i < ALPHABET_SIZE; i++) child[i] = NULL;
        }
    };
    typedef Node* PNode;

private:
    /* data */
    PNode root, traverse_ptr;

    /* Private methods*/

    // Create a new node
    PNode create_node(){ return new Node(); }
    // Erase a node from the tree
    PNode erase(PNode current_node, const string &str, const int &current_id);
    // Delete a subtree in Trie
    void delete_subtree(PNode root_tree);
    // Print all words
    void print_all(PNode current_node, string str);

public:
    Trie();
    ~Trie();

    /* Public methods*/

    // Insert a new word into the dictionary
    void insert(const string &str);
    // Search for a word
    bool search(const string &str);
    // Erase a word from the dictionary
    void erase(const string &str);
    // Print all words
    void print_all();
    // Go to the chosen child of a node in the tree
    PNode next_child(const PNode &current_node, const char &c);
    // Check if the next character is in the prefix set
    bool check_next_char(const PNode &current_node, const char &c);
    // Retrieve the root of the tree
    PNode get_root();
};

#endif
