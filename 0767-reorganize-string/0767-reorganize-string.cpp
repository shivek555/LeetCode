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
    string reorganizeString(string S) {
	vector<int> cnt(26);
	int mostFreq = 0, i = 0;

	for(char c : S)
		if(++cnt[c - 'a'] > cnt[mostFreq])
			mostFreq = (c - 'a');

	if(2 * cnt[mostFreq] - 1 > S.size()) return "";

	while(cnt[mostFreq]) {
		S[i] = ('a' + mostFreq);
		i += 2;
		cnt[mostFreq]--;
	}

	for(int j = 0; j < 26; j++) {
		while(cnt[j]) {
			if(i >= S.size()) i = 1;
			S[i] = ('a' + j);
			cnt[j]--;
			i += 2;
		}
	}

	return S;
}
};