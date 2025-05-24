#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define mask(x) (1ll << x)
#define all(x) x.begin(), x.end()
#define int long long
/* FUNCTIONS */
void mimi(int & a, int b) { a = min(a, b); }
void lulu(int & a, int b) { a = max(a, b); }
int gcd(int a, int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a, int b) { return a/gcd(a,b)*b; }
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\e}"; }

const double PI = acos(-1);
const int MOD = 1e9 + 7;

struct x {
    int w, h, idx;
};

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, w, h; cin >> n >> w >> h;
    vector<x> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].w >> v[i].h;
        v[i].idx = i + 1;
    }
    sort(all(v), [&](x x1, x x2)->bool{
        if (x1.w == x2.w) return x1.h > x2.h;
        return x1.w > x2.w;
    });
    vector<int> dp(n, 1), prev(n, -1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (v[j].w > v[i].w && v[j].h > v[i].h && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int mx = 0;
    int mx_pos = -1;
    for (int i = 0; i < n; i++) {
        if (h < v[i].h && w < v[i].w) {
            if (dp[i] > mx) {
                mx = dp[i];
                mx_pos = i;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (h < v[i].h && w < v[i].w) {
            if (mx < dp[i]) {
                mx = dp[i];
                mx_pos = i;
            }
        }
    }
    cout << mx << endl;
    vector<int> ans;
    if (mx_pos != -1) {
        int i = mx_pos;
        while(true) {
            if (i == -1) {
                break;
            }
            ans.push_back(v[i].idx);
            i = prev[i];
        }
        for (auto x : ans) {
            cout << x << ' ';
        }
    }
    return 0;
}