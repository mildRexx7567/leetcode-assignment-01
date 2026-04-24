#include <vector>
using namespace std;

// LeetCode #46 - Permutations
// Difficulty: Medium
// hi JSOR here
//
// Idea principal (JSOR):
// Usar backtracking para generar todas las permutaciones posibles.
// Vamos construyendo una permutación paso a paso y marcamos
// qué elementos ya han sido usados.

class Solution {
public:

    // Función auxiliar de backtracking
    void backtrack(vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& result,
                   vector<bool>& used) {

        // Si ya usamos todos los números, guardamos la permutación
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Probamos cada número disponible
        for (int i = 0; i < nums.size(); i++) {

            // Si el número ya fue usado, lo saltamos
            if (used[i]) continue;

            // Elegimos el número actual
            current.push_back(nums[i]);
            used[i] = true;

            // JSOR aplica backtracking aquí 🔁
            backtrack(nums, current, result, used);

            // Deshacemos la elección (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        // Iniciamos el backtracking
        backtrack(nums, current, result, used);

        return result;
    }
};
