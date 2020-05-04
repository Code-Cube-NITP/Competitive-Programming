#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define mii map<int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define Loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define loop(n) for(int i = 0; i < n; i++)
#define vin vector<int>
#define w(t) int tc; cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()

long long dp[105];

int find(int n, int k){
    if(k == 0) return 0;
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] == -1){
        long long ans = 0;
        Loop(1, k+1, i){
            ans = (ans%mod + find(n-i, k)%mod)%mod;
        }
        dp[n] = ans%mod;
    }
    return dp[n]%mod;
}

int32_t main(){
    long long n, k, d;
    scanf("%lld", &n);
    scanf("%lld", &k);
    scanf("%lld", &d);
    memset(dp, -1, sizeof(dp));
    int ans = find(n, k);
    memset(dp, -1, sizeof(dp));
    int ans1 = find(n, d-1);
    // deb(ans);
    // deb(ans1);
    ans = (ans - ans1 + mod)%mod;
    
    cout << ans << endl;
}