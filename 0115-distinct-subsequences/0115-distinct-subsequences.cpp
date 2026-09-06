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
    int solve(int i, int j, string &s, string &t,
              vector<vector<int>>& memo) {

        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int notTake = solve(i + 1, j, s, t, memo);
        int take = 0;
        if(s[i] == t[j]){
            take = solve(i + 1, j + 1, s, t, memo);
        }
        return memo[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(0, 0, s, t, memo);
    }
};