#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long int ll;
typedef long double ld;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Nos                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fo(i,n) for(ll i=0;i<(n);i++)
#define rfo(i,n) for(ll i = (n);i >= 0;i--)
#define rfosn(i, s, n) for(ll i = (n); i >= (s); i--)
#define PI 3.141592654
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fosn(i, s, n) for(int i = s;i < n;i ++)
 
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define ln '\n'
#define pii pair<int,int>
#define vpi vector<pii>
// #define unordered_set(T) unordered_set<T, custom_hash>
// #define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define f first
#define se second
#define out2(a1,a2) cout << a1 << " " << a2 << endl  

const ll md = 1e9 + 7; //998244353 ;
//ll hash_prime = 31;
// const ll md = 998244353; // 1e9+7;
long long exp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res%m;
}

ll C(ll n, ll k) {
    if(n < k) return 0;
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        {res *= i; res %= md;}
    for (int i = 2; i <= k; ++i)
        {res *= exp(i, md-2, md); res %= md;}
    return res;
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
const int N = 5e5+3;
// const int M = 1e5+5;

ll n, m, D, P;
struct dem {
    ll sc, tr, sr, na;
    vector<ll> a;
    dem(){}
};
ll s, smx, t, d;
struct dem dems[N];
vector<int> ans;
double psum[N];

bool cmpdems(int &i, int &j) {
    // return dems[i].sr - dems[i].sc > dems[j].sr - dems[j].sc;
    return 100*(dems[i].sr - dems[i].sc) + psum[i]  > 100*(dems[j].sr - dems[j].sc) + psum[j] ;
    // return d1.sr - d1.sc > d2.sr - d2.sc;
}

void go1() {
    cin >> s >> smx >> t >> d;
    ans.assign(d,-1);
    fo(i,d) {
        ll sc, tr, sr, na;cin >> sc >> tr >> sr >> na;
        vector<ll> a(na);
        fo(j, na) {
            cin >> a[j];
            psum[i]+=a[j];
        }
        struct dem dm;
        dm.a = a;
        dm.na = na;
        dm.sc = sc;
        dm.tr = tr;
        dm.sr = sr;
        dems[i] = dm;
    }

    fo(i,d) ans[i] = i;
    sort(all(ans), cmpdems);
    ll scur = s;
    set<pair<ll, ll> > s;
    vector<int> res;
    vector<int> diff(t, 0);
    int demj = 0;
    fo(i, t) {
        scur += diff[i];
        if(!s.empty() and scur >= (*s.begin()).first ) {
            int y = (*s.begin()).second;
            res.pb(y);
            if(i + dems[y].tr < t) diff[i+dems[y].tr];
            scur -= dems[y].sc;
            s.erase(s.begin());
            continue;
        }
        while(demj < d) {
            int u = ans[demj];
            if(dems[u].na == 0) {
                demj++;
                s.insert({1e14, u});
                continue;
            }
            if(scur >= dems[u].sc) {
                scur -= dems[u].sc;
                res.pb(u);
                if(i + dems[u].tr < t) diff[i + dems[u].tr];
                demj++;
                break;
            }
            s.insert({dems[u].sc, u});
            demj++;
        }
    }
    while(!s.empty() and res.size() < t) {
        res.pb((*s.begin()).second);
        s.erase(s.begin());
    }
    // random_shuffle(all(ans));
    fo(i, res.size() ) cout << res[i] << ln;
}
int main(){   

    Nos;
    // freopen("00.txt", "r", stdin);
    // freopen("b_dream.txt", "r", stdin);
    // freopen("03.txt", "r", stdin);
    // freopen("d_maelstrom.txt", "r", stdin);
    // freopen("e_igloos.txt", "r", stdin);
    // freopen("f_glitch.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    // cout << fixed << setprecision(25);
    int t=1;
    // cin>>t;
    int t_=t;

    while(t--){
        // cout << "Case #"<<t_-t<<": ";
        go1();
    }
    return 0;
}