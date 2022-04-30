#include "trie.hpp"
#include <fstream>

class LongestWord{

private:
    // The dictionary
    Trie dict;
    // Scrambled words
    string word;

    string dfs(Trie::PNode current_node, bool *available);

public:
    // Constructor
    LongestWord();
    // Constructor
    LongestWord(const string &str);
    // Deconstructor
    ~LongestWord();
    // Define a new scrambled word
    void define_word(const string &str);
    // Solve the problem
    string solve();
};
