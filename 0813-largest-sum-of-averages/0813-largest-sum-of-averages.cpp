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
    double largestSumOfAveragesHelper(vector<int>& nums, int k, int start, vector<vector<double>>& dp) {
        if (k == 0 && start == nums.size()) return 0;
        if (k == 0 || start == nums.size()) return -1e9;
        if (dp[start][k] != -1) return dp[start][k];

        double currSum = 0, maxAverage = -1e9;
        for (int i = start; i < nums.size(); ++i) {
            currSum += nums[i];
            double average = currSum / (i - start + 1);
            maxAverage = max(maxAverage, average + largestSumOfAveragesHelper(nums, k - 1, i + 1, dp));
        }

         dp[start][k] = maxAverage;
         return dp[start][k] ; 
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(), vector<double>(k + 1, -1));
        return largestSumOfAveragesHelper(nums, k, 0, dp);
    }
};