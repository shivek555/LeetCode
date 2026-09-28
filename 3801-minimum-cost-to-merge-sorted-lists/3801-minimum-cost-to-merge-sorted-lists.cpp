#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int m = 1 << n;

        vector<int> len(m);
        vector<long long> med(m);

        for (int mask = 1; mask < m; ++mask) {
            int totalSize = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    totalSize += lists[i].size();
            }

            vector<int> v;
            v.reserve(totalSize);

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    v.insert(v.end(), lists[i].begin(), lists[i].end());
            }

            sort(v.begin(), v.end());

            len[mask] = v.size();
            med[mask] = v[(v.size() - 1) / 2];
        }

        const long long INF = 4000000000000000LL;
        vector<long long> dp(m, INF);

        dp[0] = 0;

        for (int i = 0; i < n; ++i)
            dp[1 << i] = 0;

        for (int mask = 1; mask < m; ++mask) {
            int bit = mask & -mask;

            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (!(sub & bit))
                    continue;

                int other = mask ^ sub;

                if (!other)
                    continue;

                if (dp[sub] == INF || dp[other] == INF)
                    continue;

                long long cost =
                    (long long)len[mask] +
                    llabs(med[sub] - med[other]);

                dp[mask] = min(
                    dp[mask],
                    dp[sub] + dp[other] + cost
                );
            }
        }

        return dp[m - 1];
    }
};