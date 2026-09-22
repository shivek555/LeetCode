struct Info {
    int product = 1, pre[5] {};
    Info() {}
    Info(int x) : product(x) { pre[x] = 1; }
};

struct SegmentTree {
    vector<Info> tree;
    int sz, k;
    SegmentTree(int n, int c_k) : k(c_k), tree(vector<Info>(4*n)), sz(n) {}

    Info add(const Info& left, const Info& right) {
        Info res(left.product * right.product % k);
        copy(left.pre, left.pre + size(left.pre), res.pre);
        for(int x = 0; x < size(right.pre); x++)
            res.pre[left.product * x % k] += right.pre[x];
        return res;
    }
    void update(int pos, const Info& val, int v, int vl, int vr) {
        if(vl == vr) {
            tree[v] = val;
        }else {
            int vmid = (vl + vr) / 2;
            if(pos <= vmid) update(pos, val, 2*v, vl, vmid);
            else update(pos, val, 2*v+1, vmid+1, vr);

            tree[v] = add(tree[2*v], tree[2*v + 1]);
        }
    }
    Info query(int l, int r, int v, int vl, int vr) {
        if(l <= vl && vr <= r) return tree[v];
        if(vr < l || r < vl) return Info();
        int vmid = vl + (vr-vl)/2;
        return add(query(l, r, 2*v, vl, vmid), query(l, r, 2*v+1, vmid+1, vr));
    }
};
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
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree segtree(nums.size(), k);
        vector<int> res(queries.size());

        for(int i = 0, n = nums.size(); i < n; i++)
            segtree.update(i, Info(nums[i] % k), 1, 0, n - 1);

        for(int i = 0, n = nums.size(), sz = queries.size(); i < sz; i++) {
            segtree.update(queries[i][0], Info(queries[i][1] % k), 1, 0, n - 1);
            res[i] = segtree.query(queries[i][2], n - 1, 1, 0, n - 1).pre[queries[i][3]];
        }
        return res;
    }
};