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
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        int num=0;
        for(int i=0;i<cpdomains.size();i++){
            for(int j=0;j<cpdomains[i].size();j++){
                if(cpdomains[i][j]==' '){
                    num=stoi(cpdomains[i].substr(0,j));
                    map[cpdomains[i].substr(j+1,cpdomains[i].size())]+=num;
                }
                if(cpdomains[i][j]=='.'){
                    map[cpdomains[i].substr(j+1,cpdomains[i].size())]+=num;
                }
            }
        }
        vector<string> ans;
        for(auto& i:map){
            ans.push_back(to_string(i.second) +" "+i.first);
        }
        return ans;
    }
};