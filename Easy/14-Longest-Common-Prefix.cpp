#include <vector>
#include <string>
using namespace std;

// LeetCode #14 - Longest Common Prefix
// Difficulty: Easy
// Approach: Reduce prefix until it matches all strings
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        string prefix = strs[0]; // Take first string as base

        for (int i = 1; i < strs.size(); i++) {
            string current = strs[i];

            // Reduce prefix until it matches the start of current
            while (current.find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);

                if (prefix.empty()) return "";
            }
        }
           //JSOR
        return prefix;
    }
};
