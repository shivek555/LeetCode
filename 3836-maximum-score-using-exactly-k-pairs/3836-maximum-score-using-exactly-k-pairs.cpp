#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long memo[101][101][101];
bool vis[101][101][101];



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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        memset(vis, false, sizeof(vis));
        auto go = [&](this auto&& go, int i, int j, int p) -> long long {
            if(p == k) return 0;
            if(min(n - i, m - j) < k - p) return -INF;
            if(vis[i][j][p]) return memo[i][j][p];
            vis[i][j][p] = true;
            return memo[i][j][p] = max({
                1LL * nums1[i] * nums2[j] + go(i + 1, j + 1, p + 1),
                go(i + 1, j, p),
                go(i, j + 1, p)
            });
        };
        return go(0, 0, 0);
    }
};