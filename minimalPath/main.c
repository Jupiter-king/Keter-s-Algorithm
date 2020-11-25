#include <stdio.h>
#include <stdlib.h>

typedef int **MGraph;
#define INFINITY 65535 // 定义65535为无穷大

struct grid {
    int weight;
    int id;
    int x;
    int y;
};

struct Maze {
    struct grid **grids;
    int numVertexes;
    int height; // 迷宫高度
    int length; // 迷宫长度
    int startX; // 迷宫开始位置的X
    int startY; // 迷宫开始位置的Y
    int endX;
    int endY;
    int startID; // 起始格子对应的ID
    int endID;   // 终止格子对应的ID
    int **GMaze; //领接矩阵
    int *GMazeX; //领接矩阵 元素对应的x坐标
    int *GMazeY; //领接矩阵 元素对应的y坐标
};


// 创建二维数组
struct Maze *crateMaze() {
    struct Maze *mazeInfo = (struct Maze *) malloc(sizeof(struct Maze));
    int height, length, startX, startY, endX, endY;
    // 输入信息
    scanf("%d %d", &mazeInfo->height, &mazeInfo->length);
    scanf("%d %d %d %d", &mazeInfo->startX, &mazeInfo->startY, &mazeInfo->endX, &mazeInfo->endY);
    struct grid **grids;
    int numVertexes = 0;
    // 动态分配二维数组的内存
    grids = (struct grid **) malloc(sizeof(struct grid *) * mazeInfo->length);
    for (int i = 0; i < mazeInfo->length; ++i) {
        grids[i] = (struct grid *) malloc(sizeof(struct grid) * mazeInfo->length);
    }
    int id = 0; // 用于给各个格子编号，方便生成领接矩阵
    int flag=0;
    int x,y; // 用于存储v0的x和y
    for (int i = 0; i < mazeInfo->height; ++i) {
        for (int j = 0; j < mazeInfo->length; ++j) {
            scanf("%d", &grids[i][j].weight);
            if (grids[i][j].weight != -1) {
                if (flag==0){
                    x = i;
                    y = j;
                    flag = 1;
                }
                numVertexes += 1; // 统计道路格子的数量
                grids[i][j].id = id;
                grids[i][j].x = i;
                grids[i][j].y = j;
                if (i == mazeInfo->startX && j == mazeInfo->startY) {
                    mazeInfo->startID = id;
                } else if (i == mazeInfo->endX && j == mazeInfo->endY) {
                    mazeInfo->endID = id;
                }
                id++;
            }
        }
    }
    grids[mazeInfo->startX][mazeInfo->startY].id = 0;
    grids[x][y].id = mazeInfo->startID;
    mazeInfo->grids = grids;
    mazeInfo->numVertexes = numVertexes;
    return mazeInfo;
}

int **applyStorage(int height, int length) {
    int **array;
    // 动态分配二维数组的内存
    array = (int **) malloc(sizeof(int *) * height);
    for (int i = 0; i < length; ++i) {
        array[i] = (int *) malloc(sizeof(int) * length);
    }
    return array;
}

// 将二维数组转化为领接表的格式
void arrayToGMaze(struct Maze *maze) {
    int **GMaze = applyStorage(maze->numVertexes, maze->numVertexes);
    int *GMazeX = (int *) malloc(sizeof(int) * maze->numVertexes);
    int *GMazeY = (int *) malloc(sizeof(int) * maze->numVertexes);
    int x, y;
    // 四个方向
    int direction[4][2] = {{0,  1},
                           {1,  0},
                           {0,  -1},
                           {-1, 0}};
    // 初始化领接表
    for (int i = 0; i < maze->numVertexes; ++i) {
        for (int j = 0; j < maze->numVertexes; ++j) {
            GMaze[i][j] = INFINITY; // 初始化为无穷大
        }
    }
    for (int i = 0; i < maze->height; ++i) {
        for (int j = 0; j < maze->length; ++j) {
            if (maze->grids[i][j].weight != -1) {
                GMazeX[maze->grids[i][j].id] = i;
                GMazeY[maze->grids[i][j].id] = j;
                // 扫描四个方向有没有可用的通路
                for (int k = 0; k < 4; ++k) {
                    x = i + direction[k][0];
                    y = j + direction[k][1];
                    // 没有越界的情况
                    if (x >= 0 && y >= 0 && x < maze->height && y < maze->length) {
                        if (maze->grids[x][y].weight != -1) {
                            GMaze[maze->grids[i][j].id][maze->grids[x][y].id] = maze->grids[x][y].weight;
                        }
                    }
                }
                // 添加上自己
                GMaze[maze->grids[i][j].id][maze->grids[i][j].id] = 0;
            }
        }
    }
    maze->GMaze = GMaze;
    maze->GMazeX = GMazeX;
    maze->GMazeY = GMazeY;
}

void Dijkstra(struct Maze *maze) {
    int v, w, k, min;
    int *final = (int *) malloc(sizeof(int) * maze->numVertexes); // final[w]=1 表示求得顶点v0到vw的距离
    int *D = (int *) malloc(sizeof(int) * maze->numVertexes); // 用于存储最短路径下标
    int *P = (int *) malloc(sizeof(int) * maze->numVertexes); // 用于存储最短路径下标
    for (v = 0; v < maze->numVertexes; v++) {
        final[v] = 0; // 全部顶点初始化为未知最短路径状态
        D[v] = maze->GMaze[0][v];
        P[v] = 0; // 初始化路径数组权值为0
    }
    D[0] = 0; // v0 到 v0路径为0
    final[0] = 1; // v0不要求 求路径
    // 开始主循环，每次求得v0到某个v顶点到最短路径
    for (v = 1; v < maze->numVertexes; v++) {
        min = INFINITY;
        for (w = 0; w < maze->numVertexes; w++) {
            if (!final[w] && D[w] < min) {
                k = w;
                min = D[w];
            }
        }
        final[k] = 1; // 将目前找到到最近到顶点变为1
        for (w = 0; w < maze->numVertexes; w++) { // 修正当前最短路径和距离
            // 如果经过v顶点到路径比现在这条路径到长度短到话
            if (!final[w] && (min + maze->GMaze[k][w] < D[w])) {
                D[w] = min + maze->GMaze[k][w]; // 修改当前路径到长度
                P[w] = k;
            }
        }
    }
    int i = maze->endID;
    printf("(%d %d)",maze->endX,maze->endY);
    while (P[i] != 0) {
        printf("(%d %d)", maze->GMazeX[P[i]], maze->GMazeY[P[i]]);
        i = P[i];
    }
    printf("(%d %d)",maze->startX,maze->startY);
}


int main() {
    struct Maze *maze = crateMaze();
    arrayToGMaze(maze);
    Dijkstra(maze);
    return 0;
}


// 测试用例
/**
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
**/
