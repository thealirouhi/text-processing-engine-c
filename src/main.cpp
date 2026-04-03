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
    vector<string> rawWords;
    vector<string> stopWords;
    string line;

    // ===== Read raw text =====
    while (getline(cin, line)) {
        if (line == "###END###") break;

        string current = "";

        for (char c : line) {
            if (c == ' ' || c == '\t') {
                if (!current.empty()) {
                    rawWords.push_back(current);
                    current = "";
                }
            } else {
                current += c;
            }
        }

        if (!current.empty()) {
            rawWords.push_back(current);
        }
    }

    // ===== Read stop words =====
    while (getline(cin, line)) {
        if (line == "###END###") break;

        string current = "";

        for (char c : line) {
            if (c == ' ' || c == '\t') {
                if (!current.empty()) {
                    stopWords.push_back(current);
                    current = "";
                }
            } else {
                current += c;
            }
        }

        if (!current.empty()) {
            stopWords.push_back(current);
        }
    }

    // temporary debug output
    cout << "=== Raw Words ===" << endl;
    for (const string& w : rawWords) {
        cout << w << endl;
    }

    cout << "=== Stop Words ===" << endl;
    for (const string& w : stopWords) {
        cout << w << endl;
    }

    return 0;
}