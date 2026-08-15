using ll   = long long;
using pii  = pair<int, int>;
using vi   = vector<int>;
using vl   = vector<ll>;
using vvi  = vector<vector<int>>;

#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define sz(x)     (int)(x).size()
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int inf  = 1e9;
const ll  linf = 4e18;
const int mod  = 1e9 + 7;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = sz(tasks), m = sz(shifts);
        vi res(m);
        vl tt(n+1);
        vl st(m+1);
        for(int i=0;i<n;i++)tt[i+1]=tasks[i]+tt[i];
        for(int i=0;i<m;i++)st[i+1]=shifts[i]+st[i];

        int pt=0;
        for(int i=1;i<=m;i++){
            ll curT = st[i] - st[pt];              
            int idx = upper_bound(all(tt), curT) - tt.begin() -1;
            res[i-1]=n-idx;
            if(!res[i-1])pt=i;                    
        }

        return res;
    }
};