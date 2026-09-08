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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastValid = -1;
        int lastInvalid = -1;
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                lastInvalid = i;
            }

            if (nums[i] >= left && nums[i] <= right) {
                lastValid = i;
            }

            if (lastValid > lastInvalid) {
                answer += lastValid - lastInvalid;
            }
        }

        return answer;
    }
};