#include <iostream>
#include "longest_words.hpp"
using namespace std;

LongestWord solver;

int main(){
    string inp;
    cout << "Please enter a string: ";
    cin >> inp;
    solver.define_word(inp);
    cout << "The longest word is: " << solver.solve() << endl;
    return 0;
}
