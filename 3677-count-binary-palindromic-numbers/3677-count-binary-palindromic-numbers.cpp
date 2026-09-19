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
    vector<int> digit;
    int cache[51][51][2][2];
    int dp(int l, int r, int flg, int ok) {
        if(l > r) {
            return (!flg || (flg && ok));
        }
        
        int& ans = cache[l][r][flg][ok];
        if(ans != -1) {
            return ans;
        }
        ans = 0;
        int limit = flg ? digit[l - 1] : 1;
        for(int d = 0; d <= limit; d++) {
            if(l == 1 && d == 0) {
                continue;
            }
            bool next_ok = ok;
            if(ok) {
                next_ok = d <= digit[r - 1];
            } else {
                next_ok = d < digit[r - 1];
            }
            ans += dp(l + 1, r - 1, flg && (d == limit), next_ok);
        }
        return ans;
    }

    int dp(long long n) {
        while(n) {
            digit.push_back(n % 2);
            n /= 2;
        }
        reverse(digit.begin(), digit.end());
        memset(cache, -1, sizeof(cache));
        int ans = 1;
        for(int cnt = 1; cnt <= digit.size(); cnt++) {
            ans += dp(1, cnt, (cnt == digit.size()), 1);
        }
        return ans;
    }

    int countBinaryPalindromes(long long n) {
        return dp(n);
    }
};