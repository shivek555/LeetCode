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
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        set<int> banned;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<mines.size();i++) {
            banned.insert(mines[i][0]*n + mines[i][1]);
        }
        int ans=0,count=0;

        for(int i=0;i<n;i++) {
            count =0;
            for(int j=0;j<n;j++) {
                count = (banned.find(i*n+j)!=banned.end()) ? 0 : count+1;
                dp[i][j] = count;
            }
            count =0;
            for(int j=n-1;j>=0;j--) {
                count = (banned.find(i*n+j) != banned.end()) ? 0 : count+1;
                dp[i][j] = min(dp[i][j] , count);
            }
        }
        
        for(int j=0;j<n;j++) {
            count=0;
            for(int i=0;i<n;i++) {
                count = (banned.find(i*n+j)!=banned.end()) ? 0 : count+1;
                dp[i][j] = min(dp[i][j],count);
            }
            count=0;
             for(int i=n-1;i>=0;i--) {
                count = (banned.find(i*n+j) != banned.end()) ? 0 : count+1;
                dp[i][j] = min(dp[i][j] , count);
                ans = max(ans , dp[i][j])  ; 
            }
        }
        return ans;        
    }
};