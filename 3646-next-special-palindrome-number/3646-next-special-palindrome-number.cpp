typedef long long ll;
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
    long long specialPalindrome(long long n) {
        static vector<long long> specials;
        if (specials.empty()) init(specials);
        auto it = upper_bound(specials.begin(), specials.end(), n);
        return *it;
    }

private:
    void init(vector<long long> &v) {
        vector<char> half;
        string mid;
        for (int mask = 1; mask < (1<<9); ++mask) {
            int sum = 0, oddCnt = 0;
            for (int d = 1; d <= 9; ++d) if (mask & (1<<(d-1))) {
                sum += d;
                if (d % 2) ++oddCnt;
            }
            if (sum > 18 || oddCnt > 1) continue;
            half.clear(); mid.clear();
            for (int d = 1; d <= 9; ++d) if (mask & (1<<(d-1))) {
                int cnt = d;
                if (cnt % 2) {
                    mid = string(1, '0'+d);
                }
                int h = cnt / 2;
                while (h--) half.push_back('0' + d);
            }
            sort(half.begin(), half.end());
            do {
                string left(half.begin(), half.end());
                string right = left;
                reverse(right.begin(), right.end());
                string s = left + mid + right;
                if (!s.empty()) {
                    long long x = stoll(s);
                    v.push_back(x);
                }
            } while (next_permutation(half.begin(), half.end()));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
};