#include <string>
using namespace std;

// LeetCode #44 - Wildcard Matching
// Difficulty: Hard (Bonus)
// JSOR
//
// Usar un enfoque greedy con dos punteros.
// El '*' se maneja guardando su última posición y
// retrocediendo si hay una discrepancia posterior.
// Esto evita usar DP y funciona en O(n).

class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0; // puntero para el string s
        int j = 0; // puntero para el patrón p

        int star = -1;   // última posición donde apareció '*'
        int match = 0;  // posición en s cuando encontramos '*'

        while (i < s.length()) {

            // Caso 1: caracteres iguales o '?'
            if (j < p.length() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Caso 2: encontramos '*'
            else if (j < p.length() && p[j] == '*') {
                star = j;     // guardamos posición del '*'
                match = i;    // guardamos posición actual en s
                j++;          // avanzamos en el patrón
            }
            // Caso 3: no coincide, pero ya vimos un '*'
            else if (star != -1) {
                j = star + 1; // volvemos al patrón después del '*'
                match++;      // el '*' cubre un carácter más
                i = match;
            }
            // Caso 4: no hay coincidencia posible
            else {
                return false;
            }
        }

        // Ignorar '*' restantes al final del patrón
        while (j < p.length() && p[j] == '*') {
            j++;
        }

        // Si recorrimos todo el patrón, hay match
        return j == p.length();
    }
};
