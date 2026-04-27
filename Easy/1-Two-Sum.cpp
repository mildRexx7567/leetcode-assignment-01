// LeetCode #1 - Two Sum
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seen; // número -> índice (JSOR estuvo aquí)

        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int needed = target - current;

            // Si ya vimos el número que falta, devolvemos los índices
            if (seen.find(needed) != seen.end()) {
                return {seen[needed], i};
            }

            // Guardamos el número actual
            seen[current] = i;
        }

        return {}; // JSOR
    }
};
