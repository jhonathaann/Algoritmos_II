#include <stdio.h>
#include <math.h>

// funcao com tempo de execução 100n^2
double func1(double n) {
    return 100 * n * n;
}

// funcao com tempo de execução 2^n
double func2(double n) {
    return pow(2, n);
}

int main() {
    double n = 0.1414; // Valor aproximado de n

    // calcula os valores antes de n
    for (int i = 3; i >= 1; i--) {
        double n_antes = n - i;
        printf("antes de n: n = %.4f, func1 = %.4f, func2 = %.4f\n", n_antes, func1(n_antes), func2(n_antes));
    }

    // calcula os valores apos n
    for (int i = 1; i <= 3; i++) {
        double n_depois = n + i;
        printf("apos n: n = %.4f, func1 = %.4f, func2 = %.4f\n", n_depois, func1(n_depois), func2(n_depois));
    }

    return 0;
}
