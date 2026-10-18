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
private:
    int rows, cols, leftBound, topBound, rightBound, bottomBound;
    vector<vector<int>> path;

    void addToPath(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            path.push_back({row, col});
        }
    }

    void traverseEast(int start, int end) {
        for (int i = start; i <= end; ++i) addToPath(topBound, i);
    }

    void traverseWest(int start, int end) {
        for (int i = start; i >= end; --i) addToPath(bottomBound, i);
    }

    void traverseSouth(int start, int end) {
        for (int i = start; i <= end; ++i) addToPath(i, rightBound);
    }

    void traverseNorth(int start, int end) {
        for (int i = start; i >= end; --i) addToPath(i, leftBound);
    }

public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        this->rows = rows;
        this->cols = cols;
        int totalCells = rows * cols;
        path.reserve(totalCells);

        leftBound = rightBound = cStart;
        topBound = bottomBound = rStart;
        ++rightBound;

        addToPath(rStart, cStart);

        while (path.size() < totalCells) {
            if (topBound >= 0) traverseEast(max(0, leftBound + 1), min(cols - 1, rightBound));
            ++bottomBound;
            if (path.size() >= totalCells) break;

            if (rightBound < cols) traverseSouth(max(0, topBound + 1), min(rows - 1, bottomBound));
            --leftBound;
            if (path.size() >= totalCells) break;

            if (bottomBound < rows) traverseWest(min(cols - 1, rightBound - 1), max(0, leftBound));
            --topBound;
            if (path.size() >= totalCells) break;

            if (leftBound >= 0) traverseNorth(min(rows - 1, bottomBound - 1), max(0, topBound));
            ++rightBound;
            if (path.size() >= totalCells) break;
        }

        return path;
    }
};