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
    int largestInteger(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(auto n: nums) freq[n]++;
    int ans = -1, uniqueLargest = -1, largest = -1;
    for(int i = 0; i < nums.size(); ++i) {
        if(freq[nums[i]] == 1) uniqueLargest = max(uniqueLargest, nums[i]);
        largest = max(largest, nums[i]);
    }
    if(k == 1) return uniqueLargest;
    if(k == nums.size()) return largest;
    if(freq[nums[0]] == 1) ans = max(ans, nums[0]); 
    if(freq[nums.back()] == 1) ans = max(ans, nums.back());
    return ans;
}
};