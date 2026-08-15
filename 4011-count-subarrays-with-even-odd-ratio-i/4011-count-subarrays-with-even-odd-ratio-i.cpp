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
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
               int n = nums.size(); 
        int ans = 0; 
        for(int i = 0; i < n; i++) {
            int o = 0, e = 0; 
            for(int j = i; j < n; j++) {
                if(nums[j] % 2 > 0) o++; 
                else e++; 

                if(e * b <= o * a) ans++; 
            }
        }
        return ans; 
    }
};