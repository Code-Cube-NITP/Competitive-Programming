#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define mii map<int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define pt(a) cout << a << endl;
#define ptt(a, b) cout << a << " " << b << endl;
#define ptf(a) cout << a << " ";
#define rd(a) cin >> a;
#define rdd(a, b) cin >> a >> b;
#define loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define lop(n) for(int i = 0; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define lopk(n) for(int k = 0; k < n; k++)
#define vin vector<int>
#define w(flag) int tc = 1; if(flag) cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define elif else if
#define nline cout << endl;

//__________________________________😌😌SAB MOH MAYA HAI😌😌____________________________________________







int ar[1000006] = {0};
int br[1000006] = {0};
int n = 0;
int tp(0), tp1(0), tp2(0), tp3(0), tp4(0);
string str;
int len;
void pre_processing(){}
//____________________________________😋Coding just for fun😋____________________________________________





void solve()
{
    rd(n)
    vin vis(2*n, 0);
    vin num(2*n);
    lop(2*n)
        rd(num[i])
    lopk(n)
    {
        // deb(k)
        int i = 0;
        while(vis[i] == 1) i++;
        vis[i]++;
        
        int j = i+1;
        while(1)
        {
            if(num[i] == num[j] and vis[j] == 0)
                break;
            else
                j++;
        }
        vis[j]++;
        // for(auto itr : vis) cout << itr << " "; cout << endl;
        cout << num[i] << " ";
    }
    nline
}

int32_t main()
{
    fastio;
    pre_processing();
    w(true)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}