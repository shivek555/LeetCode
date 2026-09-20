#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[128 * 1024 * 1024];
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
    void dfs(int u, 
             const vector<int>& nums,
             const vector<vector<int>>& gr, 
             vector<bool>& vis, 
             priority_queue<int, vector<int>, greater<int>>& even, 
             priority_queue<int>& odd) {
        if (u & 1) odd.push(nums[u]);
        else even.push(nums[u]);
        vis[u] = true;
        for (const auto& v: gr[u]) if (!vis[v]) dfs(v, nums, gr, vis, even, odd);
    }

    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        vector<vector<int>> gr(n);
        for (const auto& swap: swaps) {
            gr[swap[0]].push_back(swap[1]);
            gr[swap[1]].push_back(swap[0]);
        }
        long long res = 0;
        vector<bool> vis(n);
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                priority_queue<int, vector<int>, greater<int>> even;
                priority_queue<int> odd;
                dfs(u, nums, gr, vis, even, odd);
                while (!even.empty() && !odd.empty() && even.top() < odd.top()) {
                    int temp = odd.top();
                    odd.pop();
                    odd.push(even.top());
                    even.pop();
                    even.push(temp);
                }
                while (!even.empty()) {
                    res += even.top();
                    even.pop();
                }
                while(!odd.empty()) {
                    res -= odd.top();
                    odd.pop();
                }
            }
        }
        return res;
    }
};