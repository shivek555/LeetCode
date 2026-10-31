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
    int maxTurbulenceSize(std::vector<int>& A) {
        int N = A.size();
        if (N < 2) return N;

        int ans = 1;
        int anchor = 0;

        auto compare = [&](int x, int y) {
            if (x < y) return -1;
            if (x > y) return 1;
            return 0;
        };

        for (int i = 1; i < N; ++i) {
            int c = compare(A[i - 1], A[i]);
            if (c == 0) {
                anchor = i;
            } else {
                if (i == N - 1 || c * compare(A[i], A[i + 1]) != -1) {
                    ans = std::max(ans, i - anchor + 1);
                    anchor = i;
                }
            }
        }

        return ans;
    }
};