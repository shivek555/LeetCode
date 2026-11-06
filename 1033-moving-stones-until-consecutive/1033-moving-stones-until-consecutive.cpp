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
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> p(3,0);

        p[0] = a;
        p[1] = b;
        p[2] = c;

        sort(p.begin(), p.end());

        vector<int> v(2,0);

        int left = p[1] - p[0];
        int right = p[2] - p[1];

        if(left == 1 && right == 1) {
            return v;
        }

        if(left <= 2 || right <= 2) {
            v[0] = 1;
        } else {
            v[0] = 2;
        }

        v[1] = left + right - 2;

        return v;
    }
};