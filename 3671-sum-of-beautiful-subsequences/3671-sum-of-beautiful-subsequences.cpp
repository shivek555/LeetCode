#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    const long long MOD = 1e9+7;
    int totalBeauty(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>>divs(mx+1);
        for(int i = 1; i <= mx; ++i)
            divs[i].reserve(128);
        for(int i = 1; i <= mx; ++i)
        {
            for(int j = i; j <= mx; j+=i)
            {
                divs[j].push_back(i);
            }
        }

        vector<int>offsets(mx+1, 0);
        int pos = 0;
        for(int g = 1; g <= mx; ++g)
        {
            offsets[g] = pos;
            pos += (mx/g + 1);
        }

        vector<long long>BIT(pos, 0);

        auto query = [&](int g, int idx){
            long long sum = 0;
            while(idx > 0)
            {
                sum = (sum + BIT[offsets[g] + idx]) % MOD;
                idx -= (idx & -idx);
            }
            return sum;
        };

        auto update = [&](int g, int idx, long long val){
            while(idx < mx/g + 1)
            {
                BIT[offsets[g] + idx] = (BIT[offsets[g] + idx] + val) % MOD;
                idx += (idx & -idx);
            }
        };

        vector<long long>F(mx+1, 0);
        for(int num : nums)
        {
            for(int g : divs[num])
            {
                long long prev = query(g, num/g - 1);
                long long cur = prev + 1;
                F[g] = (F[g] + cur) % MOD;
                update(g, num/g, cur);
            }
        }

        vector<long long>N(mx+1, 0); 
        for(int g = mx; g >= 1; --g)
        {
            N[g] = F[g];
            for(int mul = 2*g; mul <= mx; mul+=g)
            {
                N[g] = (N[g] - N[mul] + MOD) % MOD;
            }
        }

        long long rt = 0;
        for(int g = 1; g <= mx; ++g)
        {
            rt = (rt + 1LL * g * N[g]) % MOD;
        }

        return rt;
    }
};