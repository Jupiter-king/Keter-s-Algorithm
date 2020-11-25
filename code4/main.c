#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
#define INFINIFY 65535


// 输入路径连接表
int **Pathmatrix(int n) {
    int **matrix;
    // 为二维数组动态分配空间
    matrix = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int *) malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

// matrix是领结表，D用于存储带权长度
void Floyd(int **matrix, int n) {
    // 为P和D动态分配空间
    int **P;
    // 为二维数组动态分配空间
    int v, w, k;
    int **D;
    // 为二维数组动态分配空间
    D = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        D[i] = (int *) malloc(sizeof(int) * n);
    }
    for (v = 0; v < n; v++) {  // 初始化D
        for (w = 0; w < n; w++) {
            D[v][w] = matrix[v][w]; // D[v][w]值即对应点间的权值
        }
    }
    for (k = 0; k < n; ++k) {
        for (v = 0; v < n; ++v) {
            for (w = 0; w < n; ++w) {
                if (D[v][w] > (D[v][k] + D[k][w])) {
                    D[v][w] = D[v][k] + D[k][w];
                }
            }
        }
    }
    // 接下来判断医院建在哪里才是最短的
    int minID = 0;
    int minSum = INFINIFY;
    int sum;
    for (v = 0; v < n; ++v) {
        sum = 0;
        for (w = 0; w < n; ++w) {
            sum += D[v][w];
        }
        if (sum < minSum) {
            minSum = sum;
            minID = v;
        }
    }
    printf("Hospital should be built in %c", minID + 97);
}


int main() {
    int n;
    scanf("%d", &n);
    int **maze = Pathmatrix(n);
    Floyd(maze,n);
    return 0;
}


// 输入样例
/*
6
0 12 3 65535 9 10
12 0 65535 2 6 65535
3 65535 0 2 65535 6
65535 2 2 0 4 7
9 6 65535 4 0 4
10 65535 6 7 4 0
*/



















