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
    int MOD = 1e9 + 7;
    
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        
        vector<vector<long>> A = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        
        vector<vector<long>> v = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        
        n--;
        while (n > 0) {
            if ((n & 1) != 0) {
                v = multiply(v, A);
            }
            
            A = multiply(A, A);
            n >>= 1;
        }
        
        int ans = 0;
        for (long num : v[0]) {
            ans = (ans + num) % MOD;
        }
        
        return ans;
    }
    
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B) {
        vector<vector<long>> result(A.size(), vector<long>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                for (int k = 0; k < B.size(); k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        
        return result;
    }
};