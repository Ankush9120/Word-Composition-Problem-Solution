#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

// structure of node
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord = false;
    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            children[i] = NULL;
        }
    }
};

// function to insert words in Trie
void insertWord(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (node->children[index] == NULL)
        {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// function to check whether word is compounded or not
bool isCompoundWord(TrieNode *root, const string &word, int EndCount)
{
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (node->children[index] == NULL)
        {
            return false;
        }
        node = node->children[index];
        if (node->isEndOfWord)
        {
            if (i == word.length() - 1 && EndCount > 0)
            {
                return true;
            }
            if (isCompoundWord(root, word.substr(i + 1), EndCount + 1))
            {
                return true;
            }
        }
    }
    return false;
}

// function to check longest compound word
string findLongestCompoundWord(TrieNode *node, const vector<string> &words)
{
    TrieNode *root = node;
    string longestCompoundWord;
    for (const string &word : words)
    {
        if (isCompoundWord(root, word, 0) && word.length() > longestCompoundWord.length())
        {
            longestCompoundWord = word;
        }
    }
    return longestCompoundWord;
}

// function to check second longest compound word
string findSecondLongestCompoundWord(TrieNode *node, const vector<string> &words, const string &longestCompoundWord)
{
    TrieNode *root = node;
    string secondLongestCompoundWord;
    for (const string &word : words)
    {
        if (word == longestCompoundWord)
        {
            continue;
        }
        if (isCompoundWord(root, word, 0) && word.length() > secondLongestCompoundWord.length())
        {
            secondLongestCompoundWord = word;
        }
    }
    return secondLongestCompoundWord;
}

int main()
{
    TrieNode *root = new TrieNode();
    auto start = chrono::high_resolution_clock::now();

    ifstream inputFile("Input_02.txt");   // replace filename from here
    vector<string> words;

    // reading words from file
    if (inputFile.is_open())
    {
        string word;
        while (getline(inputFile, word))
        {
            words.push_back(word);   // inserting words in vector
            insertWord(root, word);   // inserting words in trie
        }
        inputFile.close();
    }
    else
    {
        cout << "Unable to open the input file." << endl;
        return 1;
    }

    string longestCompoundWord = findLongestCompoundWord(root, words);
    string secondLongestCompoundWord = findSecondLongestCompoundWord(root, words, longestCompoundWord);

    // file processing time calculation
    auto end = chrono::high_resolution_clock::now();
    double processingTime = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1e6;

    cout << "1. Longest Compound Word: " << longestCompoundWord << endl;
    cout << "2. Second Longest Compound Word: " << secondLongestCompoundWord << endl;
    cout << "Time taken to process: " << processingTime << " seconds" << endl;

    return 0;
}