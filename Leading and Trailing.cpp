#include<bits/stdc++.h>
#define ll long long
// program to find the leading and trailing three digits x^y
// Question Link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970

using namespace std;

void binpow(ll x,ll y,ll n){
    //this is a function for fast modular exponentiation
x%=n;
ll res=1;
while(y>0){
    if(y&1)
        res=res*x%n;
    x=x*x%n;
    y>>=1;


}
printf("%03lld\n",res);



}

int frontzero(ll x,ll n){

double a=n*log10(x);
return floor(pow(10, a - floor(a) + 3 - 1) ) ;//returns front 3 digits
}
int main(){
    int t;
    cin>>t;//input test cases
    while(t--){

        ll x,n;
        cin>>x>>n;// for x^n
        cout<<frontzero(x,n)<<"...";
        binpow(x,n,1000);


    }


    return 0;


}

