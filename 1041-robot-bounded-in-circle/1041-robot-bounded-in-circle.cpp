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
    bool isRobotBounded(string instructions) {
        int n = instructions.size();
        int x = 0, y = 0, dir = 0;

        for (int i = 0; i < 4 * n; i++) {
            if (instructions[i % n] == 'L') {
                dir = (dir + 3) % 4;
            } else if (instructions[i % n] == 'R') {
                dir = (dir + 1) % 4;
            } else {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else x--;
            }
        }

        return (x == 0 && y == 0);
    }
};