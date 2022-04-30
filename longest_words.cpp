#include "longest_words.hpp"

LongestWord::LongestWord(){
    ifstream fi("data.dic");
    string x;
    while(fi >> x){
        dict.insert(x);
    }
    word = "";
}

LongestWord::LongestWord(const string &str){
    ifstream fi("data.dic");
    string x;
    while(fi >> x){
        dict.insert(x);
    }
    word = str;
}

LongestWord::~LongestWord(){
    // dict.~Trie();
}

void LongestWord::define_word(const string &str){
    word = str;
}

string LongestWord::dfs(Trie::PNode current_node, bool *available){
    if(current_node == NULL) return "";
    string res = "";
    for(size_t i = 0; i < word.length(); i++){
        if(!available[i]) continue;
        if(!dict.check_next_char(current_node, word[i])) continue;
        Trie::PNode next_node = dict.next_child(current_node, word[i]);
        available[i] = false;
        string current_res = word[i] + dfs(next_node, available);
        available[i] = true;
        if(res.length() < current_res.length()) res = current_res;
    }
    return res;
}

string LongestWord::solve(){
    bool *available = new bool[word.length()];
    for(size_t i = 0; i < word.length(); i++) available[i] = true;
    string res = dfs(dict.get_root(), available);
    delete[] available;
    return res;
}
