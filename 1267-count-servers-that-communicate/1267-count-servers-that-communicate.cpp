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
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int communicableServersCount = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            int rowCounts = 0;
            int serverColumnIndex = -1;

            for (int colIndex = 0; colIndex < cols; ++colIndex) {
                if (grid[rowIndex][colIndex]) {
                    if (rowCounts == 0) {
                        serverColumnIndex = colIndex;
                    }
                    rowCounts += 1;
                }
            }

            bool canCommunicate = (rowCounts !=1);

            if (!canCommunicate) {
                for (int i = 0; i < rows; ++i) {
                    if (i != rowIndex && grid[i][serverColumnIndex]) {
                        canCommunicate = true;
                        break;
                    }
                }
            }

            if (canCommunicate) {
                communicableServersCount += rowCounts;
            }
        }

        return communicableServersCount;
    }
};