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
    int longestStrChain(vector<string>& words) {
        std::unordered_map<std::string, int> chains;  
        std::vector<std::string> sortedWords = words;
        std::sort(sortedWords.begin(), sortedWords.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();  
        });

        for (const std::string& word : sortedWords) {
            chains[word] = 1;  

            for (int i = 0; i < word.length(); i++) {
                std::string pred = word.substr(0, i) + word.substr(i + 1); 
                if (chains.find(pred) != chains.end()) {
                    chains[word] = std::max(chains[word], chains[pred] + 1);
                }
            }
        }

        int maxChainLength = 0;
        for (const auto& entry : chains) {
            maxChainLength = std::max(maxChainLength, entry.second);
        }

        return maxChainLength;        
    }
};