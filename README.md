# Word Frequency Processor (C++)

## Overview

This program reads raw text input and computes word frequencies after applying a cleaning, filtering, and sorting pipeline.  
Everything is implemented manually using basic C++ constructs (vectors, loops, strings) to expose the full logic of text processing.

---

## Input Format

Input is provided via standard input (`stdin`) in two sections.

### 1. Raw text section
- Contains the main text
- Words are separated by spaces or tabs
- Ends when the line contains:

###END###

---

### 2. Stop words section
- Contains stop words separated by spaces or tabs

---

## Processing Steps

Each word from the raw input goes through a pipeline:

---

### 1. Tokenization
- Lines are split manually using spaces and tabs
- Words are stored in a vector

---

### 2. Stop-word preprocessing
- Stop words are converted to lowercase using ASCII conversion
- Stored in `stopWordsSanitized`

---

### 3. Word sanitization (`sanitizeWord`)

Each word is transformed in this exact order:

#### Step 1: Lowercasing
- Converts `A–Z` → `a–z` using ASCII arithmetic

#### Step 2: Trim punctuation
- Removes punctuation only from the **start and end**
- Internal punctuation is preserved

#### Step 3: Remove numbers
A word is removed if:
- It is a pure integer (e.g. `123`)
- OR a valid decimal number (e.g. `12.34`)

Invalid numeric formats like `12.3.4` are NOT removed

---

### 4. Stop-word filtering
- Sanitized words are compared against sanitized stop words
- If a match is found → word is skipped

---

### 5. Frequency counting
Words are stored in:

`struct WordCount {
    string word;
    int count;
};`

Rules:
- If word exists → increment count
- Otherwise → add new entry

---

### 6. Sorting

Words are sorted by:

1. Highest frequency first
2. If tie → alphabetical order

Example:
<br>
test: 2  
world: 2  

---

## Output Format

Total words original: <number>  
Total words after filter: <number>  
Word Frequencies:  
word1: count  
word2: count  

---

## Complexity

Let:
- N = number of input words
- M = number of stop words
- K = number of unique words

Then:

- Stop-word check: O(M) per word
- Frequency update: O(K) per word
- Sorting: O(K²)

Overall: not optimized for large datasets.

---

## Design Notes

- No STL hash maps used (intentional)
- Manual parsing instead of `stringstream`
- ASCII-only lowercase conversion
- Educational implementation focusing on clarity over performance

---

## Possible Improvements

- Replace stop-word vector with `unordered_set`
- Replace frequency vector with `unordered_map`
- Replace sorting loop with `std::sort`
- Add stricter numeric validation
- Improve performance for large inputs

---

## Purpose

This project is designed to build a low-level understanding of:

- tokenization
- string normalization
- filtering pipelines
- frequency counting
- sorting with custom rules