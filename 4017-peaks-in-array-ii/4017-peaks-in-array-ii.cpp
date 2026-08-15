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
    struct B{
        int n;
        vector<long long> t;
        B(int n):n(n),t(n+1){}
        void add(int x,long long v){
            for(x++;x<=n;x+=x&-x)
                t[x]+=v;
        }
        long long sum(int x){
            long long s=0;
            for(x++;x>0;x-=x&-x)
                s+=t[x];
            return s;
        }
        long long qur(int l,int r){
            if(l>r) return 0;
            return sum(r)-(l?sum(l-1):0);
        }
    };

    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        B A(n),Bi(n);
        set<int> st;

        auto isPeak = [&](int i){
            return i>0 && i<n-1&&nums[i]>nums[i-1]&&nums[i]>nums[i+1];
        };

        auto eraseData = [&](int p){
            auto it = st.find(p);
            auto nx = next(it);
            int q = (nx==st.end()?n:*nx);

            A.add(p,-1LL*p*(q-p));
            Bi.add(p,-(q-p));

            auto pr = (it==st.begin()?st.end():prev(it));
            if(pr!=st.end()){
                int x = *pr;
                A.add(x,1LL*x*(q-x));
                Bi.add(x,q-x);
                A.add(x,-1LL*x*(p-x));
                Bi.add(x,-(p-x));
            }

            st.erase(it);
        };

        auto insertData = [&](int p){
            auto nx = st.lower_bound(p);
            int q = (nx==st.end()?n:*nx);

            auto pr = (nx==st.begin()?st.end():prev(nx));
            if(pr!=st.end()){
                int x = *pr;
                A.add(x,-1LL*x*(q-x));
                Bi.add(x,-(q-x));
                A.add(x,1LL*x*(p-x));
                Bi.add(x,p-x);
            }

            st.insert(p);
            A.add(p,1LL*p*(q-p));
            Bi.add(p,q-p);
        };

        for(int i = 1;i<n-1;i++)
            if(isPeak(i))
                insertData(i);

        vector<long long> ans;

        for(auto &q:queries){
            if(q[0]==1){
                int l=q[1],r=q[2];

                auto it = st.upper_bound(r-1);

                if(it==st.begin()){
                    ans.push_back(0);
                    continue;
                }

                --it;
                int last = *it;

                if(last<=l){
                    ans.push_back(0);
                    continue;
                }

                long long sa = A.qur(l+1,last);
                long long sb = Bi.qur(l+1,last);

                long long res = sa - 1LL*l*sb;

                int nx = n;
                auto jt = next(it);

                if(jt!=st.end())
                    nx=*jt;

                res+=1LL*(last-l)*(r-nx);

                ans.push_back(res);
            }
            else{
                int idx = q[1];
                int val = q[2];

                vector<int> v;

                for(int x = idx-1;x<=idx+1;x++){
                    if(x>0 && x<n-1&& isPeak(x))
                        v.push_back(x);
                }

                for(int x:v)
                    eraseData(x);

                nums[idx]=val;

                for(int x = idx-1;x<=idx+1;x++){
                    if(x>0 && x<n-1&& isPeak(x))
                        insertData(x);
                }
            }
        }

        return ans;
    }
};