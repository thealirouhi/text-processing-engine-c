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
string toLowerAscii(string word);
string trimPunctuation(string word);
string removeNumbers(string word);
string sanitizeWord(string word);
bool isStopWord(string word, vector<string> stopWords);
vector<WordCount> updateWordCount(vector<WordCount> frequencies, string word);
vector<WordCount> sortWordCounts(vector<WordCount> frequencies);

// ===== Function definitions =====
bool isPunctuation(char c) {
    return c == '.' ||
           c == ',' ||
           c == '!' ||
           c == '?' ||
           c == ':' ||
           c == ';' ||
           c == '\"' ||
           c == '\'';
}

string toLowerAscii(string word) {
    string result;

    for (char c : word) {
        if (c >= 'A' && c <= 'Z') {
            result += (c + 32);
        } else {
            result += c;
        }
    }

    return result;
}

string trimPunctuation(string word) {
    int start = 0;
    int end = word.size() - 1;

    while (start <= end && isPunctuation(word[start])) {
        start++;
    }

    while (end >= start && isPunctuation(word[end])) {
        end--;
    }

    if (start > end) return "";

    return word.substr(start, end - start + 1);
}

string removeNumbers(string word) {
    int dotCount = 0;
    bool hasDigit = false;
    bool isNumber = true;

    for (char c : word) {
        if (c >= '0' && c <= '9') {
            hasDigit = true;
            continue;
        }
        else if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isNumber = false;
            }
        }
        else {
            isNumber = false;
        }
    }

    // must contain at least one digit
    if (!hasDigit) {
        isNumber = false;
    }

    if (isNumber) {
        return "";
    }

    return word;
}

string sanitizeWord(string word) {
    word = toLowerAscii(word);
    word = trimPunctuation(word);
    word = removeNumbers(word);

    return word;
}

bool isStopWord(string word, vector<string> stopWords) {
    return false;
}

vector<WordCount> updateWordCount(vector<WordCount> frequencies, string word) {
    for (WordCount& wc : frequencies) {
        if (wc.word == word) {
            wc.count++;
            return frequencies;
        }
    }

    WordCount newEntry;
    newEntry.word = word;
    newEntry.count = 1;

    frequencies.push_back(newEntry);

    return frequencies;
}

vector<WordCount> sortWordCounts(vector<WordCount> frequencies) {
    return frequencies;
}

// ===== Main =====
int main() {
    vector<string> rawWords;
    vector<string> stopWords;
    vector<string> stopWordsSanitized;
    vector<WordCount> frequencies;

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

    int totalOriginal = rawWords.size();

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

    // ===== Process words =====
    for (string w : stopWords) {
        stopWordsSanitized.push_back(toLowerAscii(w));
    }

    int totalFiltered = 0;

    for (string w : rawWords) {
        w = sanitizeWord(w);

        if (w == "") continue;

        if (isStopWord(w, stopWordsSanitized)) continue;

        frequencies = updateWordCount(frequencies, w);
        totalFiltered++;
    }

    // ===== Sort =====
    frequencies = sortWordCounts(frequencies);

    // ===== Output =====
    cout << "Total words original: " << totalOriginal << endl;
    cout << "Total words after filter: " << totalFiltered << endl;
    cout << "Word Frequencies:" << endl;

    for (WordCount wc : frequencies) {
        cout << wc.word << ": " << wc.count << endl;
    }

    return 0;
}