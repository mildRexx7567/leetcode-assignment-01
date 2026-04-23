//JSOR
#include <string>
using namespace std;

// LeetCode #58 - Length of Last Word
// Difficulty: Easy
// Approach: Traverse from the end ignoring spaces
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {

        int length = 0;
        int i = s.length() - 1;

        // Step 1: Ignore trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
