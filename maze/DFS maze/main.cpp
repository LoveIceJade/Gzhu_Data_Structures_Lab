#include"Stack.h"

int main() {
    cout << "迷宫的初始状态(0表示通道，1表示墙)：" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << mg[i][j] << " ";
        }
        cout << endl;
    }

    cout << "从(1,1)到(8,8)的所有路径：" << endl;
    FindAllPaths(1, 1, 8, 8);

    return 0;
}
