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
    long long numGoodSubarrays(vector<int>& v, int k) {

        map<long long, long long> mp;
        int n = v.size();
        mp[0]++;
        long long sum = 0;
        long long cnt = 0;

        for (int i = 0; i < n;) {

            int j = i;
            long long sum2 = sum;

            while (j < n && v[j] == v[i]) {
                sum2 += (long long)v[j];
                sum2 %= k;
                cnt += mp[sum2 % k];
                j++;
            }

            j = i;
            while (i < n && v[j] == v[i]) {
                sum += v[j];
                sum %= k;
                mp[sum]++;
                i++;
            }
        }

        return cnt;
    }
};