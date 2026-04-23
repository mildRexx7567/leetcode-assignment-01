// LeetCode #9 - Palindrome Number
// Difficulty: Easy
// Approach: Reverse half of the number
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {

        // Fast checks
        if (x < 0) return false;                 // Negative numbers are not palindromes
        if (x % 10 == 0 && x != 0) return false; // Ends with 0 but not zero itself

        int reversedHalf = 0;

        // Reverse only half of the number
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // Even digits: x == reversedHalf
        // Odd digits: x == reversedHalf / 10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
