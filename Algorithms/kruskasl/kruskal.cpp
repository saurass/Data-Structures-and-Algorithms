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

struct DsuNode {
    int weight;
    int parent;
};

DsuNode mkSet(int val) {
    DsuNode tp;
    tp.weight = 0;
    tp.parent = val;
    
    return tp;
}

bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[2] < v2[2];
}

int find_set(int x, map<int, DsuNode> &sets) {
    if(sets[x].parent == x)
        return x;
    return sets[x].parent = find_set(sets[x].parent, sets);
}

void union_set(int a, int b, map<int, DsuNode> &sets) {
    int x = find_set(a, sets);
    int y = find_set(b, sets);
    if(x == y)
        return;
    sets[x].parent = y;
    sets[y].weight += sets[x].weight;
}

void kruskal(vector<vector<int> > &edges, map<int, DsuNode> &sets) {
    for(int i = 0; i < edges.size(); i++) {
        int x = find_set(edges[i][0]);
        int y = find_set(edges[i][1]);
        
        if(x != y) {
            union_set(edges[i][0], edges[i][1], sets);
        }
    }
}

int main() {
	
	fastio;
	
	map<int, DsuNode> sets;
	vector<vector<int> > edges;
	
	

	return 0;
}
