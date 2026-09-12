class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); ++i)
            if (fronts[i] == backs[i])
                same.insert(fronts[i]);

        int ans = 9999;
        for (int x: fronts)
            if (!same.contains(x))
                ans = min(ans, x);

        for (int x: backs)
            if (!same.contains(x))
                ans = min(ans, x);

        return ans % 9999;
    }
};