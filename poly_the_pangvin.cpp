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
#define mk_arr(n, t, s) t* n = new t[s]; loop(s) cin >> n[i]; 
#define mi_arr(n, s) int* n = new int[s]; loop(s) cin >> n[i]; 
#define arr_out(n, s) Loop(0, s, lout) cout << n[lout] << " ";
#define pi(x) printf("%lld ", x);

int n, m, d;
int ans = INT_MAX;
int arr[105][105];

void check(int a){
    int ta = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        int diff = abs(arr[i][j] - a);
        ta += diff/d;
        if(ta > ans) break;
    }
    ans = min(ta, ans);
}


int32_t main(){
    scanf("%lld", &n);
    scanf("%lld", &m);
    scanf("%lld", &d);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%lld", &arr[i][j]);
    bool flag = true;
    int temp = arr[0][0];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        int diff = abs(temp-arr[i][j]);
        if((diff%d)){flag = false; break;}
    }
    if(flag){
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            check(arr[i][j]);
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << '\n';
    }
}