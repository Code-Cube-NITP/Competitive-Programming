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
            int p = str[i] - 'a';
            if(temp->child[p] == NULL){
                node* n = new node();
                temp->child[p] = n;
            }
            temp = temp->child[p];
        }
        temp->count++;
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
    Trie *trie = new Trie();
    trie->insert("abc");
    trie->insert("ab");
    trie->insert("a");
    cout << trie->count(trie->head) << endl;
}
