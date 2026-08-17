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
vector<vector<int>> f;
    int dfs(const vector<int>& stoneValue, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (f[left][right]) {
            return f[left][right];
        }

        int sum = accumulate(stoneValue.begin() + left,
                             stoneValue.begin() + right + 1, 0);
        int suml = 0;
        for (int i = left; i < right; ++i) {
            suml += stoneValue[i];
            int sumr = sum - suml;
            if (suml < sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, left, i) + suml);
            } else if (suml > sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, i + 1, right) + sumr);
            } else {
                f[left][right] =
                    max(f[left][right], max(dfs(stoneValue, left, i),
                                            dfs(stoneValue, i + 1, right)) +
                                            suml);
            }
        }
        return f[left][right];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        f.assign(n, vector<int>(n));
        return dfs(stoneValue, 0, n - 1);
    }
};