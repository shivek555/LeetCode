#define ff first
#define ss second
#define ll long long
const int inf = 1e9 + 100;
struct PST {
    private:
    struct Node {
        int cnt;
        ll sm;
        Node(int cnt = 0, ll sm = 0) : cnt(cnt), sm(sm) {}
        friend Node operator+(const Node& x, const Node& y) { return {x.cnt + y.cnt, x.sm + y.sm}; };
        friend Node operator-(const Node& x, const Node& y) { return {x.cnt - y.cnt, x.sm - y.sm}; };
    };
    int n;
    vector<Node> root;
    vector<int> t, a;
    vector<pair<int, int>> child;
    int new_node() { root.push_back(Node(0, 0)); child.push_back({0, 0}); return root.size() - 1; }
    int get_id(ll x) { return int(lower_bound(begin(a), end(a), x) - begin(a)); }
    public:
    PST() {}

    PST(const vector<int>& arr) : a(arr) {
        t.resize(arr.size());
        new_node(); 
        sort(begin(a), end(a));
        a.erase(unique(begin(a), end(a)), end(a));
        n = a.size();
        for(int i = 0, prev = 0; i < (int)arr.size(); i++) {
            t[i] = new_node();
            update(t[i], prev, get_id(arr[i]), Node(1, arr[i]), 0, n - 1);
            prev = t[i];
        }
    }

    void update(int curr, int prev, int id, Node delta, int left, int right) {  
        root[curr] = root[prev];    
        child[curr] = child[prev];
        if(left == right) { 
            root[curr] = root[curr] + delta;
            return;
        }
        int middle = (left + right) >> 1;
        if(id <= middle) child[curr].ff = new_node(), update(child[curr].ff, child[prev].ff, id, delta, left, middle); 
        else child[curr].ss = new_node(), update(child[curr].ss, child[prev].ss, id, delta, middle + 1, right);
        root[curr] = root[child[curr].ff] + root[child[curr].ss];
    }

    int kth(int l, int r, int k) {
        return kth((l == 0 ? 0 : t[l - 1]), t[r], k, 0, n - 1);
    }

    int kth(int l, int r, int k, int left, int right) {
        if(root[r].cnt - root[l].cnt < k) return -inf;
        if(left == right) return a[left];
        int middle = (left + right) >> 1;
        int left_cnt = root[child[r].ff].cnt - root[child[l].ff].cnt;
        if(left_cnt >= k) return kth(child[l].ff, child[r].ff, k, left, middle);
        return kth(child[l].ss, child[r].ss, k - left_cnt, middle + 1, right);
    }

    int median(int l, int r) {
        return kth(l, r, (r - l + 2) / 2);
    }

    Node queries_range(int l, int r, ll low, ll high) {
        return query((l == 0 ? 0 : t[l - 1]), t[r], get_id(low), get_id(high + 1) - 1, 0, n - 1);
    }

    Node query(int l, int r, int start, int end, int left, int right) {
        if(left > end || right < start || left > right) return Node();
        if(start <= left && right <= end) return root[r] - root[l];
        int middle = (left + right) >> 1;
        return query(child[l].ff, child[r].ff, start, end, left, middle) + query(child[l].ss, child[r].ss, start, end, middle + 1, right);
    }
};

class Solution {
public:
    vector<long long> minOperations(vector<int>& a, int k, vector<vector<int>>& queries) {
        const int n = a.size();
        vector<int> far(n);
        for(int i = n - 1; i >= 0; i--) {
            far[i] = i;
            if(i + 1 < n && a[i] % k == a[i + 1] % k) far[i] = far[i + 1];
        }
        PST pst(a);
        vector<ll> ans;
        for(auto& it : queries) {
            int l = it[0], r = it[1];
            if(far[l] < r) {
                ans.push_back(-1);
            } else {
                ll med = pst.median(l, r);
                auto low = pst.queries_range(l, r, 0, med - 1);
                auto high = pst.queries_range(l, r, med + 1, inf);
                ll now = med * low.cnt - low.sm + high.sm - med * high.cnt;
                assert(now % k == 0);
                ans.push_back(now / k);
            }
        }
        return ans;
    }
};