#include <stdio.h>
#include <math.h>
#include <string.h>

double zad1(int n,int i,int j,int p){
    if(j==1){
        if(n%2==0){
            return sqrt((double)j/pow(i,(n/2)));
        }else{
            return sqrt(pow(i,(n/2)%j+1));
        }
    }
    if(n%2==0){
        if(j%2==0){
            if (j > (n / 2)) {
                return sqrt(pow(i, (n / 2) - (j - (n / 2)) + 1) / j + zad1(n, i - 1, j - 1,p));
            } else {
                return sqrt(pow(i, (n / 2) - (j) + 1) / j + zad1(n, i - 1, j - 1,p));
            }

        } else {
            if (j > (n / 2)) {
                return sqrt((double) j / pow(i, (n / 2) - (j - (n / 2)) + 1) + zad1(n, i - 1, j - 1,p));
            } else {
                return sqrt((double) j / pow(i, (n / 2) - (j) + 1) + zad1(n, i - 1, j - 1,p));
            }
        }
    }else{
        if(p%(n/2)==0){
            p=n/2;
        }
        if(j%2==1){
            if (j > (n / 2)) {
                return sqrt(pow(i, p) / j + zad1(n, i - 1, j - 1,(p+1)%(n/2)));
            } else {
                return sqrt(pow(i, p) / j + zad1(n, i - 1, j - 1,(p+1)%(n/2)));
            }
        } else {
            if (j > (n / 2)) {
                return sqrt((double) j / pow(i, p) + zad1(n, i - 1, j - 1,(p+1)%(n/2)));
            } else {
                return sqrt((double) j / pow(i, p) + zad1(n, i - 1, j - 1,(p+1)%(n/2)));
            }
        }
    }
}

double zad1a(int n){
    int i=n;
    double sum=0;
    int p=(n/2);
    if(n%2==1){
        p=n%(n/2);
    }
    for (int j = 1; j <= n; ++j) {
        if(n%2==0){
            if(j%2==1){
                sum= sqrt((double)j/ pow(i,p)+sum);
            }else{
                sum= sqrt(pow(i,p)/j +sum);
            }
        }else{
            if(j%2==0){
                sum= sqrt((double)j/ pow(i,p)+sum);
            }else{
                sum= sqrt(pow(i,p)/j +sum);
            }
        }
        i++;
        p--;
        if(p==0){
            p=n/2;
        }
    }
    return sum;
}
int n=4;
int zad2(int a[n][n]){
    int trenutniBrPon=1;
    int maksBrPon=0;
    int row=1,col=0;
    int ver=1;
    int i=0;
    int trenutniBr=a[0][0];
    int prethodniBr=a[0][0];
    while (i<n*n){
        i++;
        trenutniBr=a[row][col];
        if(prethodniBr==trenutniBr){
            trenutniBrPon++;
        }else{
            prethodniBr=trenutniBr;
            trenutniBrPon=1;
        }
        if(trenutniBrPon>maksBrPon){
            maksBrPon=trenutniBrPon;

        }
        if(row==n-1&&ver==1){
            ver=-1;
            col++;
            row++;
        }
        if(row==0&&ver==-1){
            ver=1;
            col++;
            row--;
        }
        row+=ver;
    }
    return maksBrPon;
}

int najblizaSlova(char* tok){
    int br=-1;
    int minBr= strlen(tok);
    for (int i = 0; i < strlen(tok); ++i) {
        for (int j = strlen(tok)-1; j > i; --j) {
            if(tok[i]==tok[j]){
                br=j-(i+1);
            }
        }
        if(minBr>br&&br!=-1){
            minBr=br;
        }
    }
    if(br==-1){
        return -1;
    }
    return minBr;
}

void zad3(char str[]){
    char* tok=strtok(str," ");
    while (tok!=NULL){
        if(najblizaSlova(tok)>=0){
            printf("%s-%d\n",tok,najblizaSlova(tok));
        }
        tok= strtok(NULL," ");
    }
}

int main() {
    /*printf("%lf\n", zad1(7,13,7,1));
    printf("%lf\n", zad1a(7));
    int a[][4]={{3, 4, 1, 6},{1, 2, 9, 8},{5, 6, 6, 1},{2, 3, 1, 1}};
    printf("%d",zad2(a));*/
    char str[]=" mamaa kjloijk abc hjkjk";
    zad3(str);
    return 0;
}
