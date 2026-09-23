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
    int minOperations(vector<int>& nums, int x) {int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target < 0) return -1;
        if(target == 0) return n;

        int left = 0;
        int sum = 0;
        int longest = -1;

        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left++];
            }
            if(sum == target){
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : n - longest;
    }
};