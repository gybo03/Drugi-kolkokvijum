#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n, int i, int j) {
    if (i == (n + 1) / 2) {
        if (n % 2 == 0) {
            return sqrt((double) i / (j * j) + sqrt((double) j / (i * i)));
        } else {
            return sqrt((double) i / (i * i));
        }
    }
    return sqrt((double) i / (j * j) + sqrt((double) j / (i * i) + zad1(n, i + 1, j - 1)));

}

double zad1a(int n) {
    double sum;
    int i = (n + 1) / 2;
    if (n % 2 == 0) {
        sum = sqrt((double) i / (pow((i + 1), 2)) +sqrt((double) (i + 1) / (i * i)));
        printf("i=%d j=%d sum=%lf\n", i,i+1,sum);
    } else {
        sum = sqrt((double) i / (i * i));
        printf("i=%d j=%d sum=%lf\n", i,i,sum);
    }
    i--;

    for (int j = n - 1 - n % 2; j <= n; ++j) {

        sum = sqrt((double) i / (j * j) + sqrt((double) j / (i * i) + sum));
        printf("i=%d j=%d sum=%lf\n", i,j,sum);
        i--;
    }
    return sum;
}

int n=5;

void printM(int a[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillM(int a[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j]=0;
        }
    }
}

void zad2(int a[n][n], int m){
    int hor=1,ver=0;
    int col=0,row=0;
    int i=0;
    fillM(a);
    while (i<n*n){
        i++;
        a[row][col]=m%10;
        if(col==n-1&&hor==1){
            hor=0;
            ver=1;
            a[row][col]=++m%10;
        }else if(row==n-1&&ver==1){
            hor=-1;
            ver=0;
            a[row][col]=++m%10;
        }else if(col==0&&hor==-1){
            hor=0;
            ver=-1;
            a[row][col]=++m%10;
        }
        row+=ver;
        col+=hor;
        if(a[row][col]){
            row-=ver;
            col-=hor;
            if(ver==-1&&hor==0){
                hor=1;
                ver=0;
            }else if(hor==1&&ver==0){
                hor=0;
                ver=1;
            }else if(hor==0&&ver==1){
                hor=-1;
                ver=0;
            }else if(hor==-1&&ver==0){
                hor=0;
                ver=-1;
            }
            a[row][col]=++m%10;
            row+=ver;
            col+=hor;
        }
    }
    printM(a);
}

int prviSledeciSpejs(char str[],int i){
    while (str[i]!=' '&&str[i]!=0){
        i++;
    }
    return i;
}

int daLiJePalindrom(char str[],int i,int j){
    int x=j;
    for (int k = i; k <= j; ++k) {
        if(str[k]!=str[x--]){
            return 0;
        }
    }
    return 1;
}

void uvecajSlova(char str[],int i,int j){
    for (int k = i; k <= j; ++k) {
        if(str[k]>97){
            str[k]=str[k]-32;
        }
    }
}

void obrniSlova(char str[],int i,int j){
    char temp;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void zad3(int str[]){
    int i=0;
    int spejs= prviSledeciSpejs(str,i);
    while(i<= strlen(str)){
        if(daLiJePalindrom(str,i,spejs-1)){
            uvecajSlova(str,i,spejs-1);
        }else{
            obrniSlova(str,i,spejs-1);
        }
        i=spejs+1;
        spejs= prviSledeciSpejs(str,i);
    }
    printf("%s",str);
}
int main() {
    /*printf("%lf\n", zad1(6, 1, 6));
    printf("%lf\n", zad1a(6));
    int a[5][5];
    zad2(a,3);*/
    char str[]="ovo je palindrom za reper";
    zad3(str);
    return 0;
}
