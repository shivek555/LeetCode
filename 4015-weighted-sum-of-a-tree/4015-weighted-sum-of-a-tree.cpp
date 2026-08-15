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
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> depth(n);
        queue<int> q;

        depth[0] = 1;
        q.push(0);

        int h = 1;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : children[u]) {

                depth[v] = depth[u] + 1;

                h = max(h, depth[v]);

                q.push(v);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] *
                   (h - depth[i] + 1);
        }

        return ans;
    }
};