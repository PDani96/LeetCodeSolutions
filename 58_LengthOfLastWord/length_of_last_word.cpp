#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // create vector to store words
        vector<string> words;

        // split string into words delimited by " "
        words = splitString(s);

        // get last word in vector
        string lastWord = words[words.size() - 1];
        // return size of word
        return lastWord.length();
    }

    vector<string> splitString(string s){
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        return words;
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input); // Read the entire line including spaces

    int result = solution.lengthOfLastWord(input);
    cout << "Length of the last word: " << result << endl;

    return 0;
}