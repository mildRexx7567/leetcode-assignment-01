#include <climits>
#include <cstdlib>
using namespace std;

// LeetCode #29 - Divide Two Integers
// Difficulty: Medium
// Author: JSOR
//
// (JSOR):
// Simular la división sin usar *, / o %
// usando restas y desplazamientos de bits (bit shifting).
// Esto permite lograr una complejidad O(log n).

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Caso especial para evitar overflow:
        // INT_MIN / -1 produce un número fuera del rango de int
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determinar el signo del resultado
        // XOR: si solo uno es negativo, el resultado es negativo
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convertimos a long long ANTES de aplicar abs
        // (JSOR) Esto evita overflow con INT_MIN
        long long a = llabs((long long) dividend);
        long long b = llabs((long long) divisor);

        // Usamos long long para evitar overflow durante el cálculo
        long long result = 0;

        // Mientras el dividendo sea mayor o igual al divisor
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Duplicamos el divisor usando bit shifting
            // para restar la mayor cantidad posible en cada paso
            while (a >= (temp << 1)) {
                temp <<= 1;        // equivale a temp *= 2
                multiple <<= 1;    // equivale a multiple *= 2
            }

            // Restamos el valor acumulado
            a -= temp;
            result += multiple;
        }

        // Aplicamos el signo final
        if (negative) result = -result;

        // Aseguramos que el resultado esté dentro del rango de int
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int) result;
    }
};
