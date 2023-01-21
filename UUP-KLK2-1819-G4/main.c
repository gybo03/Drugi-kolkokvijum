#include <stdio.h>
#include <math.h>
#include <string.h>

double fib(int n, int i, int j) {
    if (n <= 0) {
        return 1;
    }
    return i + fib(n - 1, j, i + j);
}

double zad1(int n, char s, int i) {
    if (i + 3 == n) {
        return s + fib(i, 1, 1) / (s - 1);
    }
    if (n % 2 == 0) {
        if (s > 97) {
            if (abs(i) % 2 == 0) {
                return s - fib(i, 1, 1) / zad1(n, s - 1, i + 1);
            } else {
                return s + fib(i, 1, 1) / zad1(n, s - 1, i + 1);
            }

        } else {
            return s - fib(i, 1, 1) / zad1(n, 97 + (n + 1) / 2, i + 1);
        }

    } else {
        if (s > 97) {
            if (abs(i) % 2 == 1) {
                return s - fib(i, 1, 1) / zad1(n, s - 1, i + 1);
            } else {
                return s + fib(i, 1, 1) / zad1(n, s - 1, i + 1);
            }
        } else {
            return s - fib(i, 1, 1) / zad1(n, 97 + (n) / 2, i + 1);
        }

    }

}

double zad1a(int n){
    char s=97;
    double sum=s+1+ fib(n-3,1,1)/s;
    for (int i = n-3; i >=-1 ; --i) {
        if(s>=96+(n+1)/2){
            s=97;
        }else{
            s++;
        }
        if(n%2==0){
            if(abs(i)%2==0){
                sum=s- fib(i,1,1)/sum;
            }else{
                sum=s+ fib(i,1,1)/sum;
            }
        }else{
            if(abs(i)%2==1){
                sum=s- fib(i,1,1)/sum;
            }else{
                sum=s+ fib(i,1,1)/sum;
            }
        }

    }
    return sum;
}
int n=3;
int minVrednostSusednihKolona(int a[n][n],int j){
    int min=4214231;
    if(j-1>=0){
        for (int i = 0; i < n; ++i) {
            if(a[i][j-1]<min){
                min=a[i][j-1];
            }
        }
    }
    if(j+1<n){
        for (int i = 0; i < n; ++i) {
            if(a[i][j+1]<min){
                min=a[i][j+1];
            }
        }
    }
    return min;
}

int maksSusednihVrsta(int a[n][n],int i){
    int max=-256744326;
    if(i-1>=0){
        for (int j = 0; j < n; ++j) {
            if(a[i-1][j]>max){
                max=a[i-1][j];
            }
        }
    }
    if(i+1<n){
        for (int j = 0; j < n; ++j) {
            if(a[i+1][j]>max){
                max=a[i+1][j];
            }
        }
    }
    return max;
}

void zad2(int a[n][n],int b[n][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j]= abs(minVrednostSusednihKolona(a,j)- maksSusednihVrsta(a,i));
            printf("%d",b[i][j]);
        }
        printf("\n");
    }

}

int zbirCif(int i,int j,char str[]){
    int zbir=0;
    for (int k = i; k < j; ++k) {
        //printf("%c\n",str[k]);
        zbir+=str[k]-48;
    }
    return zbir;
}

int indexDelimitera(char str[],int i,char delim){
    int j;
    for (j = i; j < strlen(str); ++j) {
        if(str[j]==delim){
            break;
        }
    }
    return j;
}

void zad3(char str[]){
    int trenutnoPonavljanje=1;

    int trenutniMinus= indexDelimitera(str, 0, '-');
    int prethodniMinus=0;
    int maxPonavljanja=1;
    int zbir;
    int zbirMaksPonavljanja;
    printf("%d\n", zbirCif(prethodniMinus,trenutniMinus,str));
    while(trenutniMinus <= strlen(str)){
        zbir= zbirCif(prethodniMinus,trenutniMinus,str);

        while(trenutniMinus < strlen(str)){
            prethodniMinus=trenutniMinus+1;
            trenutniMinus= indexDelimitera(str,prethodniMinus,'-');
            printf("%d\n", zbirCif(prethodniMinus,trenutniMinus,str));
            if(zbir==zbirCif(prethodniMinus,trenutniMinus,str)){
                trenutnoPonavljanje++;
            }
        }
        if(trenutnoPonavljanje>maxPonavljanja){
            maxPonavljanja=trenutnoPonavljanje;
            zbirMaksPonavljanja=zbir;
        }
        prethodniMinus=trenutniMinus+1;
        trenutniMinus= indexDelimitera(str, prethodniMinus, '-');
    }
    printf("zbir %d ",zbirMaksPonavljanja);
    prethodniMinus=0;
    trenutniMinus= indexDelimitera(str, prethodniMinus, '-');
    while(trenutniMinus<= strlen(str)){
        if(zbirCif(prethodniMinus,trenutniMinus,str)==zbirMaksPonavljanja){
            for (int i = prethodniMinus; i <trenutniMinus ; ++i) {
                printf("%c",str[i]);
            }
            printf("-");
        }
        prethodniMinus=trenutniMinus+1;
        trenutniMinus= indexDelimitera(str,prethodniMinus,'-');
    }

}


int main() {
    /*printf("%lf\n", zad1(7, 'c', -1));
    printf("%lf", zad1a(7));
    int a[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int b[3][3];
    zad2(a,b);*/
    char str[]="234-567-908-171-456-432";
    //printf("%d\n", zbirCif(0,3,str));
    zad3(str);
    return 0;
}
