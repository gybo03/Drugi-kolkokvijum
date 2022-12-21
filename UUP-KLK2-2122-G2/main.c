#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int j) {
    if (i == 1) {
        return i - j;
    }
    return i - (j / (j + i / zad1(n, i / 2, j * 2)));
}

int pom(int n, int pow) {
    for (int i = 0; i < pow; ++i) {
        n /= 2;
    }
    return n;
}

double zad1a(int n) {
    double sum = 1;
    int t = n;
    int power = 1;
    while (t != 1) {
        t /= 2;
        power++;
    }
    int j = pow(2, power - 1);

    for (int i = power; i > 0; i--) {
        double x = pom(n, i - 1);
        double y = j / 2;
        double z = j;
        double w = pom(n, i - 2);

        if (i == 1) {
            sum = x - z / sum;
            break;
        } else {
            sum = y + ((double) w / (x - ((double) z / sum)));
            j /= 2;
        }
    }
    return sum;
}

int n = 5;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void zad2(int a[n][n]) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j][k] > a[j + 1][k]) {
                    swap(&a[j][k], &a[j + 1][k]);
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[n - 1][j] < a[n - 1][j + 1]) {
                int temp[n];
                for (int k = 0; k < n; ++k) {
                    temp[k] = a[k][j];
                }
                for (int k = 0; k < n; ++k) {
                    a[k][j] = a[k][j + 1];
                }
                for (int k = 0; k < n; ++k) {
                    a[k][j + 1] = temp[k];
                }
            }
        }
    }
}

void print(int matrix[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
}
char *ucitajRec(char *str, int i, int length) {
    char rec[length];
    int j = i;
    int k = 0;
    while (str[j] != ' ' && str[j] != 0) {
        rec[k++] = str[j++];
    }
    return &rec;
}

void obrni(char *rec, char *cer, int length) {
    int j = length - 1;
    for (int i = 0; i < length; ++i) {
        cer[i] = rec[j--];
    }
    //cer[length] = ' ';
}

void zad3(char *str, int length) {

    char rts[length];
    obrni(str, rts, length);
    //printf("%s\n", rts);
    //printf("%s\n", str);
    for (int i = 0; i < length; ++i) {
        char rec[length];
        int p = 0;
        while (str[i] != ' ' && i < length) {
            rec[p++] = str[i++];
        }
        rec[p] = 0;
        //printf("%s\n",rec);
        for (int j = 0; j < length - strlen(rec); ++j) {
            int ponoviloSe = 0;
            for (int k = 0; k < strlen(rec); ++k) {
                if (i == j) {
                    while (str[j] != ' ') {
                        j++;
                    }
                    continue;
                }
                if (rec[k] == rts[j + k]) {
                    ponoviloSe++;
                }
            }
            if (ponoviloSe == strlen(rec)) {
                char cer[strlen(rec)];
                obrni(rec, cer, strlen(rec));
                printf("%s %s\n", rec, cer);
            }
        }
    }
}

void zad3a(char *str, int length) {
    for (int i = 0; i < length; ++i) {
        char rec[length];
        int p = 0;
        while (str[i] != ' ' && i < length) {
            rec[p++] = str[i++];
        }
        rec[p] = 0;
        for (int j = i; j < length - strlen(rec); ++j) {
            if (i == j + strlen(rec)) {
                while (str[j] != ' ') {
                    j++;
                }
                continue;
            }
            char druga[length];
            p = 0;
            while (str[j] != ' ' && i < length) {
                druga[p++] = str[j++];
            }
            druga[p] = 0;
            char treca[strlen(str)];
            obrni(druga, treca, strlen(rec));
            //printf("%s %s %s\n", rec, druga,treca);
            if (strcmp(rec, treca) == 0) {
                printf("%s %s\n", rec, druga);
            }
        }
    }

}

int main() {
    //printf("%lf\n", zad1(9,9,1));
    //printf("%lf", zad1a(9));

    int matrix[][5] = {{3, 6, 7, 5, 3},
                       {5, 6, 2, 9, 1},
                       {2, 7, 0, 9, 3},
                       {6, 0, 6, 2, 6},
                       {1, 8, 7, 9, 2}};
    //zad2(matrix);
    //print(matrix);
    char rec[] = "abc eef cba eed ghi dee aaa";
    zad3a(rec, strlen(rec));
    return 0;
}
