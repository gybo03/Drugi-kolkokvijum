#include <stdio.h>
#include <math.h>
#include <string.h>

int fib(int n, int i, int j) {
    if (n <= 1) {
        return 1;
    }
    return i + fib(n - 1, j, i + j);
}

double zad1(int n, int j) {
    if (n == 1) {
        return 1;
    }
    return sqrt((n * n) + fib(j, 1, 1) * zad1(n - 1, j + 1));
}

double zad1a(int n){
    double sum=1;
    int j=n-1;
    for (int i = 2; i <= n; ++i) {
        sum= sqrt((i*i)+ fib(j,1,1)*sum);
        j--;
    }
    return sum;
}

int n=3;
void printM(int a[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3  d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int max(int i,int j,int a[n][n]){
    int max=-1;
    for (int k = 0; k < n; ++k) {
        if(k==i){
            continue;
        }
        for (int l = 0; l < n; ++l) {
            if(l==j){
                continue;
            }
            if(a[k][l]>max){
                max=a[k][l];
            }
        }
    }
    return max;
}

void zad2(int a[n][n],int b[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j]=a[i][j]+ max(i,j,a);
        }
    }
    printM(b);
}

int indexDelim(char str[],int i,char delim){
    int j;
    for (j = i; j < strlen(str); ++j) {
        if(str[j]==delim){
            break;
        }
    }
    return j;
}

void obrniRec(int i,int j,char str[]){
    char temp;
    while (i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void zad3(char str[]){
    int prethodniSpejs=0;
    int trenutniSpejs= indexDelim(str,prethodniSpejs,' ');
    while(trenutniSpejs<=strlen(str)){
        if((trenutniSpejs-1-prethodniSpejs)%2==0){
            obrniRec(prethodniSpejs,trenutniSpejs-1,str);
        }
        prethodniSpejs=trenutniSpejs+1;
        trenutniSpejs= indexDelim(str,prethodniSpejs,' ');
    }
    printf("%s",str);
}

int main() {
    /*printf("%lf\n", zad1(7, 1));
    printf("%lf\n", zad1a(7));
    int a[][3]={{5,3,7},{3,5,1},{2,1,3}};
    int b[3][3];
    zad2(a,b);*/
    char str[]="ikavS nad mi je kinzarp";
    zad3(str);
    return 0;
}
