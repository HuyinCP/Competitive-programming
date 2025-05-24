#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define mask(x) (1ll << x)
#define all(x) x.begin(), x.end()
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

vector<vector<int>> dp(75, vector<int>(1048576 - 1, -1));
int n; 
string s;

int Try(int idx, int MASK) {
    int bit1 = __builtin_popcount(MASK);
    if (idx == n) {
        return (bit1 != 0 && MASK == mask(bit1) - 1);
    }
    if (dp[idx][MASK] != -1) {
        return dp[idx][MASK];
    }
    int ans = 0; // lưu tổng số cách cắt hợp lệ từ vị trí idx trở đi với MASK hiện tại.
    int num = 0; // num số thập phân từ chuỗi nhị phân con.
    for (int j=idx; j<n; j++) {
        num = num * 2 + (s[j] - '0'); // so thap phan tao duoc tu idx, den j
        if (num == 0) continue;
        if (num > 20) break;
        ans = (ans + Try(j + 1, MASK | mask(num - 1))) % MOD;
    }
    if (bit1 != 0 && MASK == mask(bit1) - 1) {
        ans = (ans + 1) % MOD;
    }
    return dp[idx][MASK] = ans;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + Try(i, 0)) % MOD; //vet cat dau tien, bo phan truoc vet cat nay, de khong yeu
    }
    cout << ans;
    return 0;
}