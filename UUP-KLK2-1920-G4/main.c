#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int k) {
    int p = i % (n / 2);
    if (p == 0) {
        p = n / 2;
    }
    //printf("%d\n", p);
    if (i == n) {
        return n + pow(n, p);
    }
    if (i % 2 == 0) {
        return i + pow(k, p) / zad1(n, i + 1, k - 1);
    } else {
        return pow(k, p) + (double) i / zad1(n, i + 1, k - 1);
    }
}

double zad1a(int n) {
    int p = n % (n / 2);
    if (p == 0) {
        p = n / 2;
    }
    double sum = n + pow(n, p);
    int k = n;
    for (int i = n; i > 0; --i) {
        p = i % (n / 2);
        if (p == 0) {
            p = n / 2;
        }
        if (i % 2 == 0) {
            sum = i + pow(k, p) / sum;
        } else {
            sum = pow(k, p) + (double) i / sum;
        }
        k++;
    }
    return sum;
}
int n=4;
void printM(int a[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int zad2(int a[n][n]){
    int najduzaSekvenca=1;
    int i=1;
    int red=0,col=1;
    int hor=1;
    int trenutniBr=a[0][0];
    int prethodniBr;
    int trenutnaSekvenca=0;
    printf("%2d",a[0][0]);
    while(i<n*n) {
        printf("%2d",a[red][col]);
        prethodniBr=trenutniBr;
        trenutniBr=a[red][col];
        if(col==n-1&&hor==1){
            red++;
            col++;
            hor=-1;
            printf("\n");
        }
        if(col==0&&hor==-1){
            red++;
            col--;
            hor=1;
            printf("\n");
        }
        col+=hor;
        if(prethodniBr+1==trenutniBr){
            trenutnaSekvenca++;
        }
        if(trenutnaSekvenca>najduzaSekvenca){
            najduzaSekvenca=trenutnaSekvenca;
        }
        i++;
    }
    return najduzaSekvenca;
}

int zad3(char str[]){
    int najduzipodstring=0;
    int trenutniPodString=0;
    for (int i = 0; i < strlen(str); ++i) {
        char trenutnoSlovo=str[i];
        char trazenoSlovo;
        if(trenutnoSlovo<97){
            trazenoSlovo=trenutnoSlovo+32;
        }else{
            trazenoSlovo=trenutnoSlovo-32;
        }
        int j;
        for (j = strlen(str)-1; j >= 0; --j) {
            if(str[j]==trenutnoSlovo||str[j]==trazenoSlovo){
                break;
            }
        }
        trenutniPodString=j-i;
        if(trenutniPodString>najduzipodstring){
            najduzipodstring=trenutniPodString;
        }
    }
    for (int i = 0; i < strlen(str); ++i) {
        char trenutnoSlovo=str[i];
        char trazenoSlovo;
        if(trenutnoSlovo<97){
            trazenoSlovo=trenutnoSlovo+32;
        }else{
            trazenoSlovo=trenutnoSlovo-32;
        }
        int j;
        for (j = strlen(str)-1; j >= 0; --j) {
            if(str[j]==trenutnoSlovo||str[j]==trazenoSlovo){
                break;
            }
        }
        if(j-i==najduzipodstring){
            for (int k = i; k <= j; ++k) {
                printf("%c",str[k]);
            }
            printf("\n");
        }
    }

    return najduzipodstring+1;
}

int main() {
    /*printf("%lf\n", zad1(6, 1, 11));
    printf("%lf", zad1a(6));*/
    /*int a[][4]={{3, 4, 1, 6},{2, 1, 3, 1},{3, 4, 5, 5},{2, 3, 4, 5}};
    printf("%d",zad2(a));*/
    char str[]="amjZdghAshZfgh";
    //char str[]="amjdZAghshZfgh";
    printf("%d", zad3(str));
    return 0;
}
