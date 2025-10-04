#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> findWordsContainingChar(const vector<string>& words, char targetChar) {
    vector<string> result;
    for (const string& word : words) {
        if (word.find(targetChar) != string::npos) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    vector<string> words = {"apple", "banana", "cherry", "date"};
    char targetChar = 'a';
    vector<string> filteredWords = findWordsContainingChar(words, targetChar);
    cout << "Words containing '" << targetChar << "':\n";
    for (const string& word : filteredWords) {
        cout << word << endl;
    }
    return 0;
}
