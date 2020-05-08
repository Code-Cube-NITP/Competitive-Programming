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

int32_t main(){
    fastio;
    w(t){
		map<pair<pair<int, int>, pair<int, int>>, int> m;
		string s; cin >> s;
		int x = 0, y = 0;
		int ans = 0;
		for (char c : s) {
			int x0=x, y0=y;
			if (c == 'N') y++;
			else if (c == 'S') y--;
			else if (c == 'E') x++;
			else if (c == 'W') x--;
			pair<int,int> a={x0,y0};
			pair<int,int> b={x,y};
			if (a>b) swap(a, b);
			if (!m[{a,b}])  ans += 5;
			else ans++;
			m[{a,b}] = 1;
		}
		cout << ans << endl;
    }
}