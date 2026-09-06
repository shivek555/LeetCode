
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int kthGrammar(int n, int k) {
        int count = __builtin_popcount(k - 1);
        return count % 2 == 0 ? 0 : 1;
    }
};