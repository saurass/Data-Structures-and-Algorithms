#include<bits/stdc++.h>
using namespace std;
 
#define DEBUG

typedef long long int ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define MOD (ll)(1e9 + 7)
#define vi vector<int>
#define vii vector<vector<int> >
#define vl vector<ll>
#define vll vector<vector<ll> >
#define vc(T, nm) vector<T> nm
#define pb push_back
#define popb pop_back
#define si set<int>
#define sl set<ll>
#define F first
#define S second
#define pii pair<int, int>
#define mp make_pair
#define ins insert
#define ers erase
#define endl "\n"
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define adr(a, b) ((a % MOD) + (b % MOD)) % MOD
#define FORA(x, s, e, inc) for(ll x = s; x != e; x += inc)
#define ROFA(x, s, e, inc) for(ll x = s; x != e; x -= inc)
#define FOR(x, s, e) FORA(x, s, e, 1)
#define ROF(x, s, e) ROFA(x, s, e, 1)
#define loop(x, n) FOR(x, 0, n)
#define rd1(t, a) 					t a; cin >> a;
#define rd2(t, a, b) 				rd1(t, a); rd1(t, b); 
#define rd3(t, a, b, c) 			rd2(t, a, b); rd1(t, c);
#define rd4(t, a, b, c, d) 			rd3(t, a, b, c); rd1(t, d);
#define rd5(t, a, b, c, d, e) 		rd4(t, a, b, c, d); rd1(t, e);
#define rd6(t, a, b, c, d, e, f) 	rd5(t, a, b, c, d, e); rd1(t, f);
#define rdA(t, nm, len)				t nm[len]; loop(i, len) {cin >> nm[i];}
#ifdef DEBUG
	#define deb(v) cout << endl << #v << ": " << v << endl
	#define db1(v) cout << endl << #v << ": " << "[ "; for(auto x: v) {cout << x << " ";}; cout << "]" << endl;
	#define db2(v) cout << endl << #v << ": " << endl; for(auto r: v) {cout << "[ "; for(auto x: r) {cout << x << " ";}; cout << "]" << endl;};
	#define dbl cout << "-------------------------------" << endl
#else
	#define deb(v)
	#define db1(v)
	#define db2(v)
	#define dbl
#endif

struct Range {
    ll diff;
    pair<ll, ll> p;
};

Range mkr(ll l, ll rl) {
    Range r;
    r.diff = rl - l + 1;
    r.p = make_pair(l, rl);
    
    return r;
};

struct cmp{
    bool operator()(Range const& r1, Range const& r2) { 
        if(r1.diff != r2.diff)
            return r1.diff < r2.diff;
        else
            return r1.p.first > r2.p.first;
    } 
};

void solve() {
	
    rd1(ll, n);
//    ll n = 4;
    vector<ll> ans(n + 1, 0);

    priority_queue<Range, vector<Range>, cmp> q;
    q.push(mkr(1, n));
    
    ll ct = 1;
    while(!q.empty()) {
        Range tp = q.top();
        ll lf = tp.p.F;
        ll rt = tp.p.S;
        q.pop();
        
        if(lf < 1 or rt > n or tp.diff < 1) {
        	q.pop();
        	continue;
		}
        
        // cout << lf << " " << rt << " " << tp.diff << endl;
        if((lf + rt) % 2 == 0) {
            ll mid = (lf + rt) / 2;
            ans[mid] = ct++;
            
            // cout << mid << endl;
            // dbl;
            if(lf <= mid - 1)
            	q.push(mkr(lf, mid - 1));
            if(mid + 1 <= rt)
            	q.push(mkr(mid + 1, rt));
                
        } else {
            ll mid = (lf + rt - 1) / 2;
            ans[mid] = ct++;
            
            // cout << mid << endl;
            // dbl;
            
            if(lf <= mid - 1)
            	q.push(mkr(lf, mid - 1));
            if(mid + 1 <= rt)
            	q.push(mkr(mid + 1, rt));
            
        }
    }
    
    FOR(i, 1, n + 1)
        cout << ans[i] << " ";
    cout << endl;
       
}

int main() {
	
	fastio;

	rd1(ll, t);
// 	ll t = 1;

    while(t--) {
        solve();
    }
    
	return 0;
}