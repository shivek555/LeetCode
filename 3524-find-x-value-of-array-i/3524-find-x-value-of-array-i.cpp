int freq[5], freq2[5];
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
    static vector<long long> resultArray(vector<int>& nums, int k) {
        const int n=nums.size();
        if (k==1) return {1LL*n*(n+1)/2};
        vector<long long> ans(k, 0);
        memset(freq, 0, sizeof(int)*k);
        for (int x: nums){
            const int r=x%k;
            memset(freq2, 0, sizeof(int)*k);
            ans[r]++;
            for (int j=0; j<k; j++){
                const int prod=j*r%k;
                freq2[prod]+=freq[j];
                ans[prod]+=freq[j];
            }
            freq2[r]++;
            memcpy(freq,freq2, sizeof(int)*k);
        }
        return ans;
    }
};