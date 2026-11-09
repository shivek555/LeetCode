#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool DFS(int i, int j, vector<vector<int>>& grid, int n, int m, int color,
             vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }
        if (grid[i][j] != color) {
            return false;
        }
        visited[i][j] = true;
        bool check = DFS(i + 1, j, grid, n, m, color, visited) &
                     DFS(i - 1, j, grid, n, m, color, visited) &
                     DFS(i, j + 1, grid, n, m, color, visited) &
                     DFS(i, j - 1, grid, n, m, color, visited);
        if (!check) {
            grid[i][j] = 2000;
        }
        return true;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int n = grid.size();
        int m = grid[0].size();
        int temp = grid[row][col];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool ok = DFS(row, col, grid, n, m, temp, visited);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2000) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
};