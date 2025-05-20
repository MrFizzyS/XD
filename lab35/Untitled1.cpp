#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <algorithm>
using namespace std;

bool isVowel(char c) 
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(const string &word) 
{
    int count = 0;
    for (char c : word) 
	{
        if (isVowel(c)) 
		{
            count++;
        }
    }
    return count;
}
string removePunctuation(const string &word) 
{
    string result;
    for (char c : word) 
    {
        if (isalpha(c)) 
        {
            result += tolower(c);
        }
    }
    return result;
}
bool containsWord(const string &sentence, const string &word) 
{
    istringstream iss(sentence);
    string currentWord;
    while (iss >> currentWord) 
    {
        string cleanedWord = removePunctuation(currentWord);
        if (cleanedWord == word) 
        {
            return true;
        }
    }
    return false;
}

class WordProcessor {
private:
    string targetWord;
    vector<size_t> positions;

public:
    WordProcessor(const string& word) : targetWord(removePunctuation(word)) {}

    void findOccurrences(const string& filename) {
        ifstream file(filename);

        string line;
        size_t globalPos = 0;
        while (getline(file, line)) {
            string lowerLine = line;
            size_t pos = 0;
            while ((pos = lowerLine.find(targetWord, pos)) != string::npos) {
                positions.push_back(globalPos + pos);
                pos += targetWord.length();
            }
            globalPos += line.length() + 1;
        }

        file.close();

        if (positions.size() < 2) {
            throw runtime_error("Word '" + targetWord + "' not found or appears only once");
        }
    }

    void processFile(const string& inputFile, const string& outputFile) {
        ifstream in(inputFile);
        ofstream out(outputFile);

        string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        in.close();

        size_t first = positions.front();
        size_t last = positions.back();

        if (first + targetWord.length() < last) {
            content.erase(first + targetWord.length(), last - (first + targetWord.length()));
        }

        out << "Target word: " << targetWord << endl;
        out << "Occurrences: " << positions.size() << endl;
        out << "Modified content:" << content << endl;
        out.close();
    }
};

void processPartE() {
    ifstream z1File("z1.txt");

    int wordCount = 0;
    string line;
    while (getline(z1File, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
        }
    }
    z1File.close();
    ifstream tFile("t.txt");

    vector<string> s1Words;
    string tLine;
    int wordsRead = 0;
    while (wordsRead < wordCount && getline(tFile, tLine)) {
        if (!tLine.empty()) {
            s1Words.push_back(tLine);
            wordsRead++;
        }
    }
    tFile.close();

    if (s1Words.size() < wordCount) {
        throw runtime_error("Not enough words in t.txt");
    }
    string s1;
    for (const auto& word : s1Words) {
        s1 += word + " ";
    }
    if (!s1.empty()) {
        s1.pop_back();
    }
    ifstream z1FileAgain("z1.txt");
    string s2((istreambuf_iterator<char>(z1FileAgain)), istreambuf_iterator<char>());
    z1FileAgain.close();
    string s3 = s1 + " " + s2;
    istringstream iss(s3);
    vector<string> s3Words;
    string word;
    while (iss >> word) {
        s3Words.push_back(word);
    }
    sort(s3Words.begin(), s3Words.end());
    string sortedS3;
    for (const auto& w : s3Words) {
        sortedS3 += w + " ";
    }
    if (!sortedS3.empty()) {
        sortedS3.pop_back(); 
    }
    ofstream z4File("z4.txt");

    z4File << "s1 (words from t.txt):" << s1 << " ";
    z4File << "s2 (copy of z1.txt):" << s2 << " ";
    z4File << "s3 (sorted merged words):" << sortedS3 << endl;
    z4File.close();

    cout << "Results saved to z4.txt" << endl;
}
int main() 
{
	ifstream inputFile("z1.txt");
    string outputPath;
    string directory;
    cout << "Enter output file path: ";
    cin>>directory;
    ofstream outputFile(directory);
    string line;
    vector<string> words;
    vector<int> counts;
    while (getline(inputFile, line)) 
    {
        istringstream iss(line);
        string word;
        string newLine;
        while (iss >> word) 
        {
            string cleanedWord = removePunctuation(word);
            if (!cleanedWord.empty()) 
            {
                bool found = false;
                for (size_t i = 0; i < words.size(); ++i) 
                {
                    if (words[i] == cleanedWord) 
                    {
                        counts[i]++;
                        found = true;
                        break;
                    }
                }
                if (!found) 
                {
                    words.push_back(cleanedWord);
                    counts.push_back(1);
                }
            }
            newLine += word + " ";
            if (countVowels(word) > 2) 
            {
                newLine += word + " ";
            }
        }
        if (!newLine.empty()) 
        {
            newLine.pop_back();
        }
        outputFile << newLine << endl;
    }

    inputFile.close();
    outputFile.close();
    for (size_t i = 0; i < words.size(); ++i) 
    {
        for (size_t j = i + 1; j < words.size(); ++j) 
        {
            if (words[i].length() < words[j].length()) 
            {
                swap(words[i], words[j]);
                swap(counts[i], counts[j]);
            }
        }
    }
    int topCount = min(3, (int)words.size());
    cout << "3 Longest words:" << endl;
    for (int i = 0; i < topCount; ++i) 
    {
        cout << " " << words[i] <<  " - " << counts[i] << endl;
    }
        cout << "Enter a word to search in sentences: ";
    string searchWord;
    cin >> searchWord;
    searchWord = removePunctuation(searchWord);

    ifstream searchFile("z1.txt");
    cout << "Sentences containing the word " << searchWord << ":" << endl;
    while (getline(searchFile, line)) 
    {
        if (containsWord(line, searchWord)) 
        {
            cout << line << endl;
        }
    }
        try {
        cout << "Enter a word to process (must appear at least twice): ";
        string processWord;
        cin >> processWord;

        WordProcessor processor(processWord);
        processor.findOccurrences("z1.txt");
        processor.processFile("z1.txt", "z3.txt");

        cout << "saved to z3.txt" << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
        try {
        processPartE();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
    searchFile.close();  
	return 0;
}

