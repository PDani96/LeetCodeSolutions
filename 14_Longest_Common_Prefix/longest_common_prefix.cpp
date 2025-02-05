#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // use entire first string as first prefix to check
        string prefix = strs[0];

        // loop through the remaining strings in the vector
        for(int i = 1; i < strs.size(); i++){
            // if the prefix is not in the current string keep looping
            while(strs[i].find(prefix) != 0){
                // trim a character off of the prefix and try again
                prefix.pop_back();

                // if there is no more prefix left to check return an empty string
                if (prefix.size() == 0) {
                    return prefix;
                }
            }
        }

        // all strings have been checked, return the remaining prefix
        return prefix;        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs1) << endl; // Expected: "fl"

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs2) << endl; // Expected: ""

    // Test case 3
    vector<string> strs3 = {"interview", "internet", "internal"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs3) << endl; // Expected: "inte"

    // Test case 4 (All identical)
    vector<string> strs4 = {"test", "test", "test"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs4) << endl; // Expected: "test"

    // Test case 5 (Single word)
    vector<string> strs5 = {"single"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs5) << endl; // Expected: "single"

    return 0;
}