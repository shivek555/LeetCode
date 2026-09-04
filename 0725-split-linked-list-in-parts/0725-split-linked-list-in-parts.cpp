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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        int size = 0;
        ListNode* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }

        int splitSize = size / k;
        int numRemainingParts = size % k;

        current = head;
        for (int i = 0; i < k; i++) {
            ListNode newPart(0);
            ListNode* tail = &newPart;

            int currentSize = splitSize;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentSize++;
            }
            for (int j = 0; j < currentSize; j++) {
                tail->next = new ListNode(current->val);
                tail = tail->next;
                current = current->next;
            }
            ans[i] = newPart.next;
        }

        return ans;
    }
};