#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int j, int k) {
    if (k == n) {
        return pow(i, k) + k;
    }
    if (n % 2 == 0) {
        if (k % 2 == 1 && k <= n / 2) {
            return i + pow(j, k) / zad1(n, i - 2 * k, j - 1, k + 1);
        } else if (k % 2 == 0 && k <= n / 2) {
            return pow(i, k) + (double) (j) / zad1(n, i - 2 * k, j - 1, k + 1);
        } else if (k % 2 == 1 && k > n / 2) {
            return i + pow(k, k) / zad1(n, i - 2 * k, j--, k + 1);
        } else {
            return pow(i, k) + (double) (k) / zad1(n, i - 2 * k, j--, k + 1);
        }
    } else {
        if (k % 2 == 1 && k <= n / 2) {
            return pow(i, k) + (double) (j) / zad1(n, i - 2 * k, j - 1, k + 1);
        } else if (k % 2 == 0 && k <= n / 2) {
            return i + pow(j, k) / zad1(n, i - 2 * k, j - 1, k + 1);
        } else if (k % 2 == 1 && k > n / 2) {
            return pow(i, k) + (double) (k) / zad1(n, i - 2 * k, j--, k + 1);
        } else {
            return i + pow(k, k) / zad1(n, i - 2 * k, j--, k + 1);
        }
    }
}

double zad1a(int n) {
    int i = n * 2, j = 1;
    double sum = 1;
    for (int k = n; k >= 1; --k) {
        if (n % 2 == 1) {
            if (k % 2 == 1 && k <= n / 2) {
                sum = pow(i, k) + j / sum;
            } else if (k % 2 == 0 && k <= n / 2) {
                sum = i + pow(j, k) / sum;
            } else if (k % 2 == 1 && k > n / 2) {
                sum = pow(i, k) + (double) (k) / sum;
            } else {
                sum = i + pow(k, k) / sum;
            }
            i = i + 2 * (k - 1);
            j++;
        } else {
            if (k % 2 == 1 && k <= n / 2) {
                sum = i + pow(j, k) / sum;
            } else if (k % 2 == 0 && k <= n / 2) {
                sum = pow(i, k) + j / sum;
            } else if (k % 2 == 1 && k > n / 2) {
                sum = i + pow(k, k) / sum;
            } else {
                sum = pow(i, k) + (double) (k) / sum;
            }
            i = i + 2 * (k - 1);
            j++;
        }

    }
    return sum;
}

int n = 6;

void print(int matrix[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void shift(int *niz, int length, int k) {
    for (int i = 0; i < abs(length - k); ++i) {
        int temp = niz[0];
        for (int j = 0; j < length - 1; ++j) {
            niz[j] = niz[j + 1];
        }
        niz[length - 1] = temp;
    }
}

void printNiz(int *niz, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%2d", niz[i]);
    }
    printf("||||||\n");
}

void zad2(int a[n][n], int k) {
    int length = n * 4 - 4;
    int row = 0, column = 0;
    int horizontal = 1, vertical = 0;
    for (int ring = 0; ring < n / 2; ++ring) {
        length = (n - 2 * ring) * 4 - 4;
        int i = 0;
        int niz[length];
        row = ring;
        column = ring;
        while (i < length) {
            niz[i] = a[row][column];
            if (row == ring && column == n - ring - 1 && horizontal == 1) {
                horizontal = 0;
                vertical = 1;
            }
            if (row == n - ring - 1 && column == n - ring - 1 && vertical == 1) {
                horizontal = -1;
                vertical = 0;
            }
            if (row == n - ring - 1 && column == ring && horizontal == -1) {
                horizontal = 0;
                vertical = -1;
            }
            if (row == ring && column == ring && vertical == -1) {
                horizontal = 1;
                vertical = 0;
            }
            row += vertical;
            column += horizontal;
            i++;
        }
        //printNiz(niz,length);
        shift(niz, length, k);
        //printNiz(niz,length);
        i = 0;
        row = ring;
        column = ring;
        horizontal = 1, vertical = 0;
        while (i < length) {
            a[row][column] = niz[i];
            if (row == ring && column == n - ring - 1 && horizontal == 1) {
                horizontal = 0;
                vertical = 1;
            }
            if (row == n - ring - 1 && column == n - ring - 1 && vertical == 1) {
                horizontal = -1;
                vertical = 0;
            }
            if (row == n - ring - 1 && column == ring && horizontal == -1) {
                horizontal = 0;
                vertical = -1;
            }
            if (row == ring && column == ring && vertical == -1) {
                horizontal = 1;
                vertical = 0;
            }
            row += vertical;
            column += horizontal;
            i++;
        }
    }
}

int zad3(char ulaz2[], char ulaz[]) {

    int max = -1, min = 300;
    for (int i = 0; i < strlen(ulaz); ++i) {
        if (ulaz[i] > max) {
            max = ulaz[i];
        }
        if (ulaz[i] < min) {
            min = ulaz[i];
        }
    }
    int length = max - min + 1;
    int bucket[length];
    for (int i = 0; i < length; ++i) {
        bucket[i] = 0;
    }
    for (int i = 0; i < strlen(ulaz); ++i) {
        if (ulaz[i] >= 97) {
            bucket[ulaz[i] - 97]++;
        } else {
            bucket[ulaz[i] - 65]++;
        }

    }
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        if (bucket[i] != 0) {
            sum++;
        }
    }


    int duzineSubStringova[sum];
    int pSum = 0;
    for (int i = 0; i < length; ++i) {
        int duzinaSubStringa = 0;
        for (int j = 0; j < length; ++j) {
            if (i == j) {
                continue;
            }
            if (bucket[i] == 0) {
                duzinaSubStringa = 0;
                break;
            }
            duzinaSubStringa += bucket[j];

        }
        if (bucket[i] != 0) {
            duzineSubStringova[pSum] = duzinaSubStringa;
            pSum++;
        }
        duzinaSubStringa = 0;
    }
    int pSum2 = 0;
    int josVeciBrojac = 0;
    for (int i = 0; i < length; ++i) {
        char subString[duzineSubStringova[pSum2] + 1];
        pSum2++;
        int veciBrojac = 0;
        int pok = 0;
        if (bucket[i] == 0) {
            pSum2--;
            continue;
        }
        for (int j = 0; j < strlen(ulaz); ++j) {
            if (ulaz[j] >= 97) {
                if (i + 97 != ulaz[j]) {
                    subString[pok++] = ulaz[j];
                }
            } else {
                if (i + 65 != ulaz[j]) {
                    subString[pok++] = ulaz[j];
                }
            }
        }
        subString[duzineSubStringova[pSum2 - 1]] = 0;

        for (int j = 0; j < strlen(ulaz2); ++j) {
            int brojac = 0;
            for (int k = 0; k < duzineSubStringova[pSum2 - 1]; ++k) {
                if (ulaz2[j + k] == subString[k]) {
                    brojac++;
                }
            }
            if (brojac == duzineSubStringova[pSum2 - 1]) {
                veciBrojac++;
            }

        }
        if (veciBrojac != 0) {
            josVeciBrojac += veciBrojac;

        }
        printf("%s-%d\n", subString, veciBrojac);

    }
    printf("%d", josVeciBrojac);
    return josVeciBrojac;
}

int main() {
    int n = 7;
    //scanf("%d", &n);
    //printf("%lf\n", zad1(n, n * (n+1), n, 1));
    //printf("%lf\n", zad1a(n));
    /*int matrix[][6] = {{3, 2, 6, 4, 5, 8},
                       {7, 4, 3, 2, 7, 1},
                       {0, 5, 6, 9, 2, 3},
                       {0, 7, 9, 4, 9, 4},
                       {9, 2, 2, 9, 4, 9},
                       {4, 3, 2, 4, 3, 2}};
    print(matrix);
    zad2(matrix, 8);
    printf("\n");
    print(matrix);*/
    char ulaz2[] ="BBDDADADA";
    char ulaz[] = "ABBDA";
    /*char ulaz[] = "abc";
    char ulaz2[] = "cbaebabacd";*/
    zad3(ulaz2, ulaz);
    return 0;
}
