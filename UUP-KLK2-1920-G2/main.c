#include <stdio.h>
#include <string.h>

double faktorijal(int n) {
    if (n == 1) {
        return 1;
    }
    return n * faktorijal(n - 1);
}

double zad1(int n, int i, int j) {
    if (((n + 1) / 2) == i) {
        printf("i=%d j=%d\n", i, j);
        printf("i=%d j=%d\n================\n", j, i);
        return i + faktorijal(j) / (j + faktorijal(i));
    }
    printf("i=%d j=%d\n", i, j);
    printf("i=%d j=%d\n================\n", j, i);
    return i + faktorijal(j) / (j + faktorijal(i) / zad1(n, i + 1, j - 1));
}

double fatkroijelIter(int n) {
    int sum = 1;
    for (int i = 2; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}

double zad1a(int n) {
    int i = (n + 1) / 2;
    int j = (n / 2) + 1;
    int x = i - 1;
    double sum;
    printf("i=%d j=%d\n", i, j);
    printf("i=%d j=%d\n================\n", j, i);
    if (n % 2 == 0) {

        sum = i + faktorijal(j) / (j + faktorijal(i));

    } else {

        sum = i + faktorijal(j);

    }
    i--;
    j++;

    for (int k = 0; k < x; ++k) {
        printf("i=%d j=%d sum=%lf\n", i, j, sum);
        printf("i=%d j=%d\n================\n", j, i);

        sum = i + fatkroijelIter(j) / (j + fatkroijelIter(i) / sum);
        i--;
        j++;

    }
    return sum;
}

int n = 5;

void put_matrix(int n, int a[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d\t", a[i][j]);
        putchar('\n');
    }
}

void zad2(int a[n][n], int br) {
    int hor = -1, ver = 0;
    int col = n - 1;
    int row = 0;
    int i = 0;
    while (i < n * n) {
        a[row][col] = br % 10;
        i++;
        if (col == 0 && hor == -1) {
            i--;
            br += 2;
            hor = 0;
            ver = 1;
            continue;
        } else if (row == n - 1 && ver == 1) {
            i--;
            br += 2;
            hor = 1;
            ver = 0;
            continue;
        } else if (col == n - 1 && hor == 1) {
            i--;
            br += 2;
            hor = 0;
            ver = -1;
            continue;
        } /// row == 0 && ver == -1 se nikad nece desiti 
        /// zato sto je a[0][0] vec popunjeno
        row += ver;
        col += hor;
        if (a[row][col]) {
            row -= ver;
            col -= hor;
            //levo
            if (hor == -1 && ver == 0) {
                br += 2;
                hor = 0;
                ver = 1;
                //dole
            } else if (hor == 0 && ver == 1) {
                br += 2;
                hor = 1;
                ver = 0;
                //desno
            } else if (hor == 1 && ver == 0) {
                br += 2;
                hor = 0;
                ver = -1;
                //gore
            } else if (hor == 0 && ver == -1) {
                br += 2;
                hor = -1;
                ver = 0;
            }
            a[row][col] = br % 10;
            row += ver;
            col += hor;

        }
    }
}
int daLiJeLj(int i,char str[]){
    if(i<strlen(str)/2+1){
        if(str[i]=='l'||str[i]=='L'&&str[i+1]=='j'){
            return 1;
        }
    }else{
        if(str[i]=='j'&&str[i-1]=='L'||str[i-1]=='l'){
            return 1;
        }
    }
    return 0;
}
int daLiJeNj(int i,char str[]){

    if(i<(strlen(str))/2){
        if(str[i]=='n'||str[i]=='N'&&str[i+1]=='j'){
            return 1;
        }
    }else{
        if(str[i]=='j'&&str[i-1]=='N'||str[i-1]=='n'){
            return 1;
        }
    }
    return 0;
}
void zad3(char str[]){
    int j= strlen(str)-1;
    int i=0;
    int ispalo=0;
    while(i<j&&ispalo==0){
        if(str[i]==' '){
            i++;
        }
        if(str[j]==' '){
            j--;
        }
        if(daLiJeLj(i,str)==1 && daLiJeLj(j,str)==1||daLiJeNj(i,str)==1&& daLiJeNj(j,str)==1){
            i+=2;
            j-=2;
        }
        if(str[i]!=str[j]&&i<j){
            ispalo=1;
        }
        j--;
        i++;
    }
    if(ispalo==0){
        printf("palindrom");
    }else{
        printf("nije palindrom");
    }
}

int main() {
    /*printf("%lf\n", zad1(7, 1, 7));
    printf("%lf", zad1a(7));*/
    /*int a[5][5];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = 0;

    zad2(a, 3);
    put_matrix(5, a);*/
    char str[]="i jogurt ujutru goji";
    //char str[]="a bca aaaaacba";
    //char str[]="idu ljudi";
    zad3(str);


    return 0;
}
