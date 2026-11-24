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
    int maxLength(std::vector<int>& nums) 
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; ++i) 
        {
            int currentGCD = nums[i];
            int currentLCM = nums[i];
            double reciprocal = 1.0/nums[i];
            
            for (int j = i; j < n; ++j) 
            {
                if (j > i) 
                {
                    currentGCD = gcd(currentGCD, nums[j]);
                    currentLCM = lcm(currentLCM,nums[j]); 
                    reciprocal /= nums[j];
                }
                if (currentGCD * currentLCM * reciprocal>0.99999999) 
                    maxLen = max(maxLen, j - i + 1);
                
            }
        }
        return maxLen;
    }
};


