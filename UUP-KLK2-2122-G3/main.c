#include <stdio.h>
#include <math.h>
#include <syslimits.h>
#include <string.h>

double zad1(int n, int i) {
    if (n == i) {
        return sqrt((double) (n) / (n * n));
    }
    if (i <= n / 2) {
        return sqrt((double) (n - i + 1) / (i * i) + zad1(n, ++i));
    } else {
        return sqrt((double) (i) / (i * i) + zad1(n, ++i));
    }
}

double zad1a(int n) {
    double sum = 0;
    for (int i = n; i >= 1; --i) {
        if (i <= n / 2) {
            sum = sqrt(sum + (double) (n - i + 1) / (i * i));
        } else {
            sum = sqrt(sum + (double) (i) / (i * i));
        }
    }
    return sum;
}

int reverseNum(int num) {
    int out = 0;
    while (num > 0) {
        out = out * 10 + num % 10;
        num /= 10;
    }
    return out;
}

int numIsPalindrom(int num) {
    if (num == reverseNum(num)) {
        return 1;
    }
    return 0;
}

int m = 5, n = 4;

void zad2(int matrix[m][n]) {
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        int max = INT_MIN;
        for (int j = 0; j < m; ++j) {
            if (max < matrix[j][i]) {
                max = matrix[j][i];
            }
            temp = temp * 10 + matrix[j][i];
            if (j == m - 1 && numIsPalindrom(temp) == 0) {
                //printf("%d\n",temp);
                for (int k = 0; k < max; ++k) {
                    int t = matrix[m - 1][i];
                    for (int l = m - 1; l > 0; --l) {
                        matrix[l][i] = matrix[l - 1][i];
                    }
                    matrix[0][i] = t;
                }
            }
        }
    }
}

void print(int matrix[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int indexOf(char *str, char c, int length, int fromIndex) {
    while (c != str[fromIndex]) {
        fromIndex++;
    }

    if (fromIndex > length) {
        return length;
    }
    return fromIndex;
}

void zad3(char *str, int len) {
    int indexOfSpace = indexOf(str, ' ', len, 0);
    int indexOfLastSpace = 0;
    int currentIndexOfSpace=indexOfSpace+1;
    int usaoJe=0;
    int sub = 1;
    for (int i = 0; i < len; ++i) {
        if (i == indexOfSpace) {
            indexOfLastSpace = indexOfSpace;
            i++;
            char c=' ';
            indexOfSpace = i + indexOf(&str[i], c, len, i);
            if(indexOfSpace>len||indexOfSpace<0){
                indexOfSpace=len;
            }
            sub = 1;
            usaoJe=0;
            currentIndexOfSpace=indexOfSpace+indexOfLastSpace+1;
            if(currentIndexOfSpace%2==1){
                currentIndexOfSpace++;
            }
        }
        if (i < (currentIndexOfSpace) / 2) {
            str[i] = ((str[i] + sub++ - 48) % 10) + 48;
        } else {
            if(currentIndexOfSpace%2==0&&usaoJe==0){
                usaoJe=1;
                sub--;
            }
            sub--;
            str[i] = (((str[i] + sub) - 48) % 10) + 48;
        }


    }
    for (int i = 0; i < len; ++i) {
        printf("%c", str[i]);
    }
}


int main() {
    //printf("%lf\n", zad1(7, 1));
    //printf("%lf\n", zad1a(7));
    /*
    int matrix[][4] = {{1, 2, 2, 2},
                       {6, 3, 1, 1},
                       {5, 8, 1, 1},
                       {6, 3, 3, 1},
                       {7, 2, 1, 2}};
    print(matrix);
    printf("\n");
    zad2(matrix);
    print(matrix);
    */
    char str[] = "4385 53913 335";
    //printf("%d", indexOf(str,' ',15,11));
    zad3(str, 14);
    printf("\n5506 65234 456");


    return 0;
}
