#include <stdio.h>
#include <math.h>

double zad1(int n, int i) {
    if (i - 1 == n) {
        if (n % 2 == 1) {
            return sqrt((double) (n) / i);
        } else {
            return sqrt((double) (n) / (i * i));
        }
    }
    if (i % 2 == 1) {
        return sqrt((double) (i - 1) / (i * i) + zad1(n, ++i));
    } else {
        return sqrt((double) (i - 1) / (i) + i * zad1(n, ++i));
    }
}

double zad1a(int n) {
    double sum = 0;
    for (int i = n + 1; i > 1; --i) {
        if (i % 2 == 0) {
            sum = sqrt(((double) (i - 1) / (i) + i * sum));
        } else {
            sum = sqrt((double) (i - 1) / (i * i) + sum);
        }
    }
}

int M = 4, N = 6;

void zad2(int a[M][N]) {
    int trenutniBr[4];
    int granica = 0;
    if (M > N) {
        granica = N;
    } else {
        granica = M;
    }
    int ponoviloSe = 0;
    for (int i = 0; i < M - 2; ++i) {
        for (int j = 0; j < N - 2; ++j) {

            for (int m = granica; m > 2; --m) {
                ponoviloSe = 0;
                if (m + i > M || m + j > N) {
                    continue;
                }
                trenutniBr[0] = a[i][j];
                trenutniBr[1] = a[i][j + m - 1];
                trenutniBr[2] = a[i + m - 1][j];
                trenutniBr[3] = a[i + m - 1][j + m - 1];
                for (int k = i; k < m; ++k) {
                    for (int l = j; l < m; ++l) {

                        for (int n = 0; n < 4; ++n) {
                            if (trenutniBr[n] == a[k][l] &&
                                !((k == i && l == j) || (k == i && l == j + m - 1) || (k == i + m - 1 && l == j) ||
                                  (k == i + m - 1 && l == j + m - 1))) {
                                ponoviloSe++;
                                break;
                            }
                        }

                        if (ponoviloSe > 0) {
                            break;
                        }
                    }
                    if (ponoviloSe > 0) {
                        break;
                    }
                }
                if (ponoviloSe == 0) {
                    printf("(%d,%d) dimenzija %dx%d\n", i, j, m, m);
                    ponoviloSe = 0;
                    break;
                }
            }
        }
    }
}

void print(int matrix[M][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //printf("%lf\n", zad1(7, 2));
    //printf("%lf\n", zad1a(7));
    int matrix[][6] = {{1, 2, 3, 4, 1, 3},
                       {3, 1, 4, 1, 5, 9},
                       {2, 4, 1, 7, 6, 8},
                       {5, 5, 3, 1, 9, 2}};
    int matrix1[][4] = {{3, 4, 4, 3},
                        {4, 1, 5, 9},
                        {1, 7, 6, 8},
                        {3, 1, 9, 2}};
    zad2(matrix);
    printf("\n");
    print(matrix);

    return 0;
}
