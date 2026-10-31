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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int sum = 0, N = queries.size();
        for (int n : nums) {
            if (n % 2 == 0) sum += n;
        }
        
        vector<int> ans(N, 0);
        for (int i = 0; i < N; i++) {
            int val = queries[i][0], index = queries[i][1];
            int oldValue = nums[index];
            nums[index] += val;
            
            bool wasEven = (oldValue % 2) == 0;
            bool nowEven = (nums[index] % 2 == 0);
            
            if (wasEven && nowEven) {
                sum += val;
                ans[i] = sum;
            } else if (!wasEven && nowEven) {
                sum += nums[index];
                ans[i] = sum;
            } else if (wasEven && !nowEven) {
                sum -= oldValue;
                ans[i] = sum;
            } else {
                ans[i] = sum;
            }
        }
        
        return ans;
    }
};