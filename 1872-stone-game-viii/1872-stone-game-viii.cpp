class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> dp (stones.size()-1);
        dp[0] = stones[0]+stones[1];
        for (int i=1; i<dp.size(); i++) dp[i] = dp[i-1] + stones[i+1];
        int max1 = dp[dp.size()-1];
        for (int i=dp.size()-2; i>=0; i--) max1 = max(max1,dp[i]-max1);
        return max1;
    }
};