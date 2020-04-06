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
/*
|------------------------------------------------------------------
|   -> Trie implementation -> just change below params
|------------------------------------------------------------------
*/

#define T_SZ 26
#define T_BS (char)'a'

struct TrieNode {
    char val;
    struct TrieNode* m[T_SZ];
    bool end;
};

// Make TrieNode
TrieNode* mkNode(char val) {
    TrieNode* pt = (TrieNode*)malloc(sizeof(TrieNode));
    pt->val = val;
    pt->end = false;
    for(int i = 0; i < T_SZ; i++)
        pt->m[i] = NULL;
    
    return pt;
}

// Insert value to our Trie
void insert(string str, TrieNode* root, int idx) {
    if(idx == str.size())
        return;
    
    int pos = str[idx] - T_BS;
    
    if(root->m[pos] == NULL)
        root->m[pos] = mkNode(str[idx]);
    if(idx == str.size() - 1)
        root->m[pos]->end = true;
    
    TrieNode* tp = root->m[pos];
    insert(str, tp, idx + 1);
}

// Search if element exists or not
bool search(string str, TrieNode* root, int idx) {
    int pos = str[idx] - T_BS;
    if(idx == str.size() and root->end == true)
        return true;
    if(root->m[pos] != NULL)
        return search(str, root->m[pos], idx + 1);
    
    return false;
}

// Delete a word
TrieNode* del(TrieNode* root, string str, int idx) {
    int pos = str[idx] - T_BS;
    if(idx == str.size()) {
        root->end = false;
        for(int i = 0; i < T_SZ; i++) {
            if(root->m[i] != NULL) {
                return root;
            }
        }
        delete root;
        return NULL;
    }
    if(root->m[pos] == NULL)
        return root;
    root->m[pos] = del(root->m[pos], str, idx + 1);
    
    for(int i = 0; i < T_SZ; i++) {
        if(root->m[i] != NULL) {
            return root;
        }
    }
    delete root;
    return NULL;
}


// Give suggestions
void suggs(TrieNode* root, vector<string> &ans, string &loc, string str, int idx) {
    loc += root->val;
    if(root->end)
        ans.pb(loc);
    if(idx < str.size()) {
        suggs(root->m[str[idx] - T_BS], ans, loc, str, idx + 1);
        return;
    }
    for(int i = 0; i < T_SZ; i++) {
        if(root->m[i] != NULL) {
            suggs(root->m[i], ans, loc, str, idx + 1);
        }
    }
    loc.pop_back();
}

int main() {
	
	fastio;
    TrieNode* root = mkNode('\0');
    insert("abc", root, 0);
    insert("abd", root, 0);
    insert("pqr", root, 0);
    insert("abcdpqr", root, 0);
    
    deb(search("abd", root, 0));
    
    // del(root, "abd", 0);
    
    deb(search("abd", root, 0));
    deb(search("abc", root, 0));
    deb(search("pqr", root, 0));
    
    vector<string> ans;
    string loc = "";
    suggs(root, ans, loc, "ab", 0);
    db1(ans);


	return 0;
}
