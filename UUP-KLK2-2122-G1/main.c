#include <stdio.h>
#include <math.h>
#include <string.h>

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
    return sum;
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
                for (int k = i; k < m + i - 1; ++k) {
                    for (int l = j; l < m + j - 1; ++l) {

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

void zad3(char *str, int length) {
    char prvaRec[4];
    prvaRec[3]=0;
    char drugaRec[4];
    drugaRec[3]=0;
    int pocetakPrveReci = 0;
    int pocetakDrugeReci = -2;
    int krajPrveReci = -2;
    int krajDrugeReci = -2;
    int x=0;
    while(str[x++]!=' '){
    }
    pocetakDrugeReci=x;
    krajPrveReci=x-2;
    while(str[x++]!=' '){
    }
    krajDrugeReci=x-2;
    x=length-1;
    while(str[x--]!=' '){
    }
    int pocetakPoslednjeReci=x+2;
    for (int i = 0; i < pocetakPoslednjeReci; ++i) {
        prvaRec[0] = str[i];
        prvaRec[1] = str[i + 1];
        prvaRec[2] = str[i + 2];

        if (str[i-1]==' ') {
            pocetakPrveReci=i;
            int y=pocetakPrveReci;
            while(str[y++]!=' '&&str[y]!=0){
            }
            if(pocetakPrveReci==pocetakPoslednjeReci){
                krajPrveReci=length-1;
            }else{
                krajPrveReci=y-2;
            }

        }
        if(prvaRec[0]==' '){
            continue;
        }
        //printf("i=%d,%d\n", pocetakPrveReci,krajPrveReci);
        //printf("%s\n",prvaRec);


        for (int j = krajPrveReci+2; j < length - 3; ++j) {
            drugaRec[0] = str[j];
            drugaRec[1] = str[j + 1];
            drugaRec[2] = str[j + 2];

            if (str[j-1]==' ') {
                pocetakDrugeReci=j;
                int y=pocetakDrugeReci;
                while(str[y++]!=' '&&str[y]!=0){
                }
                if(pocetakDrugeReci==pocetakPoslednjeReci){
                    krajDrugeReci=length-1;
                }else{
                    krajDrugeReci=y-2;
                }
            }
            if(drugaRec[0]==' '){
                continue;
            }

            //printf("\tj=%d,%d\n", pocetakDrugeReci,krajDrugeReci);
            if (prvaRec[0]==drugaRec[0]&&prvaRec[1]==drugaRec[1]&&prvaRec[2]==drugaRec[2]) {
                if(pocetakPrveReci==pocetakDrugeReci){
                    continue;
                }

                /*printf("(%d,%d)-(%d,%d)\n", pocetakPrveReci,krajPrveReci, pocetakDrugeReci,krajDrugeReci);
                printf("%d-%d\n",i,j);
                printf("%s-%s\n",prvaRec,drugaRec);*/

                for (int k = pocetakPrveReci; k <=krajPrveReci ; ++k) {
                    printf("%c",str[k]);
                }
                printf("-");
                for (int k = pocetakDrugeReci; k <=krajDrugeReci ; ++k) {
                    printf("%c",str[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    //printf("%lf\n", zad1(6, 2));
    //printf("%lf\n", zad1a(6));
    /*int matrix[][6] = {{1, 2, 3, 4, 1, 3},
                       {3, 1, 4, 1, 5, 9},
                       {2, 4, 1, 7, 6, 8},
                       {5, 5, 3, 1, 9, 2}};
    int matrix1[][4] = {{3, 4, 4, 3},
                        {4, 1, 5, 9},
                        {1, 7, 6, 8},
                        {3, 1, 9, 2}};*/
    //zad2(matrix);
    //printf("\n");
    //print(matrix);
    char str[] = "pravac jug jugozapad moj zdrav zivot moja pravila";
    zad3(str, 50);

    return 0;
}
