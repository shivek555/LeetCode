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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        vector<int> res;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> servers;

        for(int i = 0; i < k; i++) {
            servers.insert(i);
        }

        vector<int> reqCnt(k, 0);

        int n = arrival.size();
        int mxReq = 0;
        for(int i = 0; i < n; i++) {

            while(!pq.empty() && arrival[i] >= pq.top().first) {
                servers.insert(pq.top().second);
                pq.pop();
            }

            if(servers.size() == 0) continue;

            int reqServer = i % k;
            auto itrServer = servers.lower_bound(reqServer);

            auto availServer = -1;
            if(itrServer == servers.end()) {
                availServer = *servers.begin();
            } else {
                availServer = *itrServer;
            }

            servers.erase(availServer);

            pq.push({arrival[i] + load[i], availServer});
            reqCnt[availServer]++;

            mxReq = max(mxReq, reqCnt[availServer]);
        }

        for(int i = 0; i < k; i++) {

            if(reqCnt[i] == mxReq) {
                res.push_back(i);
            }
        }

        return res;

    }
};