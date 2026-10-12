class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int freq[31] ;
        for (int x : nums) {
            for (int i = 0; i <= 30; i++) {
                if (((x >> i) & 1) == 1) {
                    freq[i]++;
                }
            }
        }
        long ans = 0;
        int MOD = (int) 1e9+7;

        for (int t = 0; t < k; t++) {
            int val = 0;
            for (int i = 30; i >= 0; i--) {
                if (freq[i] > 0) {
                    val |= (1 << i);
                    freq[i]--;
                }
            }
            ans = (ans + (long) val * val) % MOD;
        }

        return (int) ans;

    }
};