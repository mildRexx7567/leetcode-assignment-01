#include <unordered_map>
#include <string>
using namespace std;

// LeetCode #13 - Roman to Integer
// Difficulty: Easy
// Approach: Map values and subtract when needed
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            int current = values[s[i]];

            // If next value is greater, subtract current
            if (i + 1 < s.length() && current < values[s[i + 1]]) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};
