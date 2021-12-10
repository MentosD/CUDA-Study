#include <stdio.h>
#define dof 3

double add(double a[dof][dof], double b[dof][dof], double c[dof][dof]) {
    for (int i = 0; i < dof; i++) {
        for (int j = 0; j < dof; j++) {
            c[i][j] = 0;
            for (int k = 0; k < dof; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c[dof][dof];
};

int main() {
    double a[dof][dof] = {{0, 1, 2},
                          {1, 2, 3},
                          {2, 3, 4}};
    double b[dof][dof] = {{0, 1, 2},
                          {1, 2, 3},
                          {2, 3, 4}};
    double c[dof][dof];
    c[dof][dof] = add(a, b, c);
    printf("%lf\n", c[0][0]);
};