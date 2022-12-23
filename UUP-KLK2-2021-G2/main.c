#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, char s, int i, int k) {
    if (abs(i) == 1 && k == n / 2) {
        return s + ((double) k / (s + i));
    }
    if (n % 2 == 0) {
        if (pow(-1, i + n) == 1) {
            if (abs(i) > n / 2 && k > 0) {
                return s + (double) k / zad1(n, s + i, -(i + 1), k - 1);
            } else {
                return s + (double) k / zad1(n, s + i, -(i + 1), k + 1);
            }
        } else {
            if (abs(i) > n / 2 && k > 0) {
                return s + (double) k / zad1(n, s + i, -(i - 1), k - 1);
            } else {
                return s + (double) k / zad1(n, s + i, -(i - 1), k + 1);
            }
        }
    } else {
        if (pow(-1, i + n) == 1) {
            if (abs(i) > n / 2 && k > 0) {
                return s + (double) k / zad1(n, s + i, -(i + 1), k - 1);
            } else if (abs(i) == n / 2) {
                return s + (double) k / zad1(n, s + i, -(i + 1), k);
            } else {
                return s + (double) k / zad1(n, s + i, -(i + 1), k + 1);
            }
        } else {
            if (abs(i) > n / 2 && k > 0) {
                return s + (double) k / zad1(n, s + i, -(i - 1), k - 1);
            } else if (abs(i) == n / 2) {
                return s + (double) k / zad1(n, s + i, -(i - 1), k);
            } else {
                return s + (double) k / zad1(n, s + i, -(i - 1), k + 1);
            }
        }
    }
}

double zad1a(int n) {
    int k = n / 2;
    char s = 'A' + k;
    double sum = s;
    for (int i = 1; i < n; ++i) {
        s = s - (-i * pow(-1, i + n));
        sum = s + (double) k / sum;

        if (i < n / 2) {
            k--;
        } else if (n % 2 == 1 && i == n / 2) {
            continue;
        } else {
            k++;
        }
    }
    return sum;
}

int n = 4;

int maxSuseda(int matrix[n][n], int i, int j) {
    int sused[4];
    if (i - 1 < 0) {
        sused[0] = 0;
    } else {
        sused[0] = matrix[i - 1][j];
    }
    if (i == n - 1) {
        sused[1] = 0;
    } else {
        sused[1] = matrix[i + 1][j];
    }
    if (j - 1 < 0) {
        sused[2] = 0;
    } else {
        sused[2] = matrix[i][j - 1];
    }
    if (j == n - 1) {
        sused[3] = 0;
    } else {
        sused[3] = matrix[i][j + 1];
    }
    int max = -1;
    for (int k = 0; k < 4; ++k) {
        if (sused[k] > max && sused[k] % 2 == 0) {
            max = sused[k];
        }
    }
    return max;
}

void print(int matrix[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sporednaDijagonala(int matrix[n][n], int izlaz[n][n]) {
    int dijagonala[n];
    for (int i = 0; i < n; ++i) {
        dijagonala[i] = matrix[i][i];
    }
    printf("\n");
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == n - 1) {
                izlaz[i][j] = dijagonala[j];
            }
        }
    }
    print(izlaz);
}

void glavnaDijagonala(int matrix[n][n], int izlaz[n][n]) {
    int dijagonala[n];

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == n - 1) {
                dijagonala[j] = matrix[i][j];
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        izlaz[i][i] = dijagonala[i];
    }
    print(izlaz);
}

void zad2(int matrix[n][n], int izlaz[n][n]) {
    sporednaDijagonala(matrix, izlaz);
    glavnaDijagonala(matrix, izlaz);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                continue;
            }
            izlaz[i][j] = maxSuseda(matrix, i, j);
        }
    }
    print(izlaz);
}

void zad3(char str[], int length) {
    int brReci = 1;
    int x = 0;
    while (str[x++] != 0) {
        if (str[x] == ' ') {
            brReci++;
        }
    }

    int duzinaSvakeReci[brReci];
    for (int i = 0; i < brReci; ++i) {
        duzinaSvakeReci[i] = 0;
    }
    int k = 0;
    for (int i = 0; i < brReci; ++i) {
        while (str[k] != 0 && str[k] != ' ') {
            duzinaSvakeReci[i]++;
            k++;
        }
        k++;
    }
    int ponavljanjeReci[brReci];
    for (int i = 0; i < brReci; ++i) {
        ponavljanjeReci[i] = 1;
    }
    k = 0;

    int max=0;
    for (int i = 0; i < brReci; ++i) {
        if(max<duzinaSvakeReci[i]){
            max=duzinaSvakeReci[i];
        }
    }
    max+=2;
    char nizStr[brReci][max];
    for (int i = 0; i < brReci; ++i) {
        char rec[duzinaSvakeReci[i] + 2];
        int j = 0;
        while (str[k] != 0 && str[k] != ' ') {
            rec[j++] = str[k];
            k++;
        }
        rec[duzinaSvakeReci[i]]=' ';
        rec[duzinaSvakeReci[i]+1] = 0;
        for (int l = 0; l < max; ++l) {
            nizStr[i][l]=rec[l];
        }
        //printf("%s\n",rec);
        k++;
        int trenutnaRec = 0;
        for (int l = 0; l < length; ++l) {
            char druga[duzinaSvakeReci[trenutnaRec] + 2];
            j = 0;
            while (str[l] != 0 && str[l] != ' ') {
                druga[j++] = str[l];
                l++;
            }
            druga[duzinaSvakeReci[trenutnaRec]] = ' ';
            druga[duzinaSvakeReci[trenutnaRec]+1] = 0;

            if (strcmp(rec, druga) == 0) {
                ponavljanjeReci[i]++;
            }
            //printf("\t%s,%d\n",druga,trenutnaRec);
            trenutnaRec++;
        }
        ponavljanjeReci[i]--;
    }
    for (int i = 0; i < brReci; ++i) {
        //printf("%s", nizStr[i]);
    }
    int min=brReci+1;
    for (int i = 0; i < brReci; ++i) {
        if(min>ponavljanjeReci[i]){
            min=ponavljanjeReci[i];
        }
    }
    char izlaz[length];
    int j=0;
    int sum=0;
    for (int i = 0; i < brReci; ++i) {
        sum+=duzinaSvakeReci[i];
        if(ponavljanjeReci[i]!=min){
            int duzinaTrenutneReci=duzinaSvakeReci[i];
            for (int l = 0; l < duzinaTrenutneReci; ++l) {
                //printf("%c",nizStr[i][l]);
                izlaz[j++]=nizStr[i][l];
            }
            izlaz[j++]=' ';
        }
    }
    izlaz[j]=0;
    for (int i = 0; i < length; ++i) {
        str[i]=izlaz[i];
    }
    printf("%s",str);
}

int main() {
    //printf("%lf\n", zad1(8, 'A', 7, 4));
    //printf("%lf\n", zad1a(6));
    int matrix[][4] = {
            {2, 6, 1, 4},
            {3, 5, 6, 8},
            {4, 1, 8, 0},
            {9, 6, 3, 7}
    };
    int izlaz[][4] = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
    };
    //zad2(matrix,izlaz);
    char str[]="hill forest woods lake forest hill";
    //char str[]="castle flower rose flower castle rose flower";
    //char str[] = "a b c d a b d a";
    zad3(str, strlen(str));


    return 0;
}
