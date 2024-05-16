#include <iostream>
#include <vector>
using namespace std;

const int MAX_ROWS = 5;
const int MAX_COLS = 5;

void dfs(vector<vector<int>>& mat, int i, int j) {
    if (i < 0 || j < 0 || i >= MAX_ROWS || j >= MAX_COLS || mat[i][j] == 0) return;
    mat[i][j] = 0;

    int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
    int dy[] = {1, -1, 0, 0, -1, -1, 1, 1};
    for (int k = 0; k < 4; k++) {
        int new_x = i + dx[k];
        int new_y = j + dy[k];
        dfs(mat, new_x, new_y);
    }
}

int main() {
    vector<vector<int>> mat =  {{1, 1, 0, 0, 1},
                                {0, 1, 0, 1, 0},
                                {1, 0, 0, 1, 1},
                                {1, 1, 0, 0, 0},
                                {1, 0, 1, 1, 1}};

    int count = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (mat[i][j] != 0) {
                dfs(mat, i, j);
                count++;
            }
        }
    }

    cout << "Number of connected components: " << count << endl;

    return 0;
}
