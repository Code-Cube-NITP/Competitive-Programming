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

class Trie{
public:
    struct node{
        node *child[26];
        int count;
        node(){
            loop(26) child[i] = NULL;
            count = 0;
        }
    };
    
    node *head;
    Trie(){
        node *temp = new node();
        head = temp;
    }
    
    void insert(string str){
        int len = str.length();
        node* temp = head;
        loop(len){
            // deb(str[i]);
            int p = str[i] - 'a';
            if(temp->child[p] == NULL){
                node* n = new node();
                temp->child[p] = n;
            }
            temp = temp->child[p];
            temp->count++;
        }
        // cout << endl;
    }

    int count(node* hd){
        int ans = 0;
        if(hd->count != 0) ans++; // to count distinct strings
        //ans += hd->count;       // uncomment this line to count total strings (and comment just above line)
        loop(26){
            if(hd->child[i] != NULL){
                ans += count(hd->child[i]);
            }
        }
        return ans;
    }

};


int32_t main(){
    string str, c;
    vin count(26);
    int k;
    cin >> str;
    cin >> c;
    cin >> k;
    for(int i = 0; i < 26; i++) count[i] = 1 - (c[i] - '0');


    Trie *trie = new Trie(); 
    int len = str.length();
    for(int i = 0; i < len; i++){
        int bc = 0;
        string temp = "";
        for(int j = i; j < len; j++){
            bc += count[str[j] - 'a'];
            if(bc > k) break;
            else temp += str[j];
        }
        trie->insert(temp);
    }
    cout << trie->count(trie->head) << endl;
    
}