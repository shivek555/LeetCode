#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[128 * 1024 * 1024];
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

    map<pair<int,int>,pair<long long , vector<int>>>dp;

    int find_index(int index,vector<vector<int>>&intervals)
    {
        int lb=index+1;
        int ub=intervals.size()-1;

        int result=intervals.size();
        while(lb<=ub)
        {
            int mid=(lb+ub)>>1;
            if(intervals[mid][0]>intervals[index][1])
            {
                result=mid;
                ub=mid-1;
            }
            else
            {
                lb=mid+1;
            }
        }
        return result;
    }

    pair<long long,vector<int>> solve(vector<vector<int>>&intervals,int n,int index,int k)
    {
        if(index>=n || k==0)
        {
            return {0,{}};
        }

        if(dp.find({index,k})!=dp.end())
        {
            return dp[{index,k}];
        }

        pair<long long,vector<int>> not_take=solve(intervals,n,index+1,k);

        int next_index=find_index(index,intervals);
        pair<long long,vector<int>> take=solve(intervals,n,next_index,k-1);

        take.first+=intervals[index][2];
        take.second.push_back(intervals[index][3]);
        sort(take.second.begin(),take.second.end());

        pair<long long,vector<int>>result;
        if(take.first>not_take.first)
        {
            result=take;
        }
        else if(not_take.first>take.first)
        {
            result=not_take;
        }
        else if(not_take.first==take.first)
        {
            result.first=take.first;
            result.second=min(take.second,not_take.second);
        }
        dp[{index,k}]=result;
        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());

        pair<long long,vector<int>>result=solve(intervals,n,0,4);

        return result.second;
        
    }
};