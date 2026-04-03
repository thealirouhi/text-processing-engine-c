#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===== Struct =====
struct WordCount {
    string word;
    int count;
};

// ===== Function declarations =====
bool isPunctuation(char c);
string sanitizeWord(string word);
bool isStopWord(string word, vector<string> stopWords);
vector<WordCount> updateWordCount(vector<WordCount> frequencies, string word);
vector<WordCount> sortWordCounts(vector<WordCount> frequencies);

// ===== Function definitions (empty for now) =====
bool isPunctuation(char c) {
    return false;
}

string sanitizeWord(string word) {
    return word;
}

bool isStopWord(string word, vector<string> stopWords) {
    return false;
}

vector<WordCount> updateWordCount(vector<WordCount> frequencies, string word) {
    return frequencies;
}

vector<WordCount> sortWordCounts(vector<WordCount> frequencies) {
    return frequencies;
}

// ===== Main =====
int main() {
    cout << "Program started" << endl;
    return 0;
}