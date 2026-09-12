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
    struct reverseComparer {
  bool operator()(const string& a, const string& b) {
    for (auto pa = a.rbegin(), pb = b.rbegin(); pa != a.rend() && pb != b.rend(); ++pa, ++pb) if (*pa != *pb) return *pa < *pb;
    return a.size() < b.size();
  }
};
int minimumLengthEncoding(vector<string>& ws, int res = 0) {
  sort(ws.begin(), ws.end(), reverseComparer());
  for (auto i = 0; i < ws.size() - 1; ++i) res += ws[i].size() <= ws[i + 1].size() 
    && ws[i] == ws[i + 1].substr(ws[i + 1].size() - ws[i].size()) ? 0 : ws[i].size() + 1;
  return res + ws[ws.size() - 1].size() + 1;
}
};