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
#define arr_out(n, s) Loop(0, s, lout) cout << n[lout] << " ";
#define pi(x) printf("%lld ", x);
#define end printf("\n");

int32_t main(){
    fastio;
    w(t){
        int n, x;
        cin >> n >> x;
        mk_arr(arr, int, n);
        int max = n+x;
        int ans = 0;
        Loop(1, max+1, j){
            bool flag = false;
            loop(n)
                if(arr[i] == j){flag = true; break;}
            if(flag) ans++;
            else if(x) ans++, x--;
            else break;
        }        
        pi(ans); end;
    }
}