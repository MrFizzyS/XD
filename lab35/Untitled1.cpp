#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>

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

int main() 
{
    ifstream inputFile("z1.txt");
    ofstream outputFile("z1_output.txt");

    string line;
    while (getline(inputFile, line)) 
	{
        istringstream iss(line);
        string word;
        string newLine;
        while (iss >> word) 
		{
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
    return 0;
}
