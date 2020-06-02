#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<pair<ll,ll>> win,draws,lose;
ll count_empty(string s[])
{
    ll x=0,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        if(s[i][j]=='_')
        x++;
    }
    return x;
}
ll check(string s[])
{
    ll i,j;
    if(s[0][0]==s[0][1]&&s[0][0]==s[0][2]&&s[0][0]=='x')
    return 1;
    if(s[1][0]==s[1][1]&&s[1][0]==s[1][2]&&s[1][0]=='x')
    return 1;
    if(s[2][0]==s[2][1]&&s[2][0]==s[2][2]&&s[2][0]=='x')
    return 1;
    if(s[0][0]==s[1][0]&&s[0][0]==s[2][0]&&s[0][0]=='x')
    return 1;
    if(s[0][1]==s[1][1]&&s[0][1]==s[2][1]&&s[0][1]=='x')
    return 1;
    if(s[0][2]==s[1][2]&&s[0][2]==s[2][2]&&s[0][2]=='x')
    return 1;
    if(s[0][0]==s[1][1]&&s[0][0]==s[2][2]&&s[0][0]=='x')
    return 1;
    if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[1][1]=='x')
    return 1;

    if(s[0][0]==s[0][1]&&s[0][0]==s[0][2]&&s[0][0]=='o')
    {
        //cout<<" see1\n";
    return 0;
    }
    if(s[1][0]==s[1][1]&&s[1][0]==s[1][2]&&s[1][0]=='o')
    {
       // cout<<"see2\n";
    return 0;
    }
    if(s[2][0]==s[2][1]&&s[2][0]==s[2][2]&&s[2][0]=='o')
    return 0;
    if(s[0][0]==s[1][0]&&s[0][0]==s[2][0]&&s[0][0]=='o')
    return 0;
    if(s[0][1]==s[1][1]&&s[0][1]==s[2][1]&&s[0][1]=='o')
    return 0;
    if(s[0][2]==s[1][2]&&s[0][2]==s[2][2]&&s[0][2]=='o')
    return 0;
    if(s[0][0]==s[1][1]&&s[0][0]==s[2][2]&&s[0][0]=='o')
    return 0;
    if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[1][1]=='o')
    return 0;
    return 2;
}
ll solve(string s[],ll player,ll move)
{
    ll i,j,val,o=0,x=0,draw=0;
    if((val=check(s))<2)
    {
        return val;
    }
    if(count_empty(s)==0)
    return 2;
    if(player==1)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(s[i][j]=='_')
                {
                    s[i][j]='x';
                    ll player_to_win=solve(s,player^1,move+1);
                    if(player_to_win==player)
                    {
                        x++;
                        if(move==1)
                        {
                            win.insert({i,j});
                        }
                    }
                    else if(player_to_win==0)
                    {
                        o++;
                        if(move==1)
                        {
                            lose.insert({i,j});
                        }
                    }
                    else
                    {
                        draw++;
                        if(move==1)
                        {
                            draws.insert({i,j});
                        }
                    }
                    //
                    s[i][j]='_';
                }
            }
        }
        if(x>=1)
        {
            return 1;
        }
        else if(draw>=1)
        {
            return 2;
        } 
        else 
        {
            return 0;
        }
    }
    else 
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(s[i][j]=='_')
                {
                    s[i][j]='o';
                    //Here main part comes 
                    ll player_to_win=solve(s,player^1,move+1);
                    if(player_to_win==player)
                    {
                        o++;
                    }
                    else if(player_to_win==1)
                    {
                        x++;
                    }
                    else
                    {
                        draw++;
                    }
                    //
                    s[i][j]='_';
                }
            }
        }
        if(o>=1)
        {
            return 0;
        }
        else if(draw>=1)
        {
            return 2;
        } 
        else 
        {
            return 1;
        }
    }
    return 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,t,x,i,j,k,l,p,q;
    cin>>t;
    
    while(t--)
    {
        win.clear();draws.clear();lose.clear();
        string s[3];char c;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>c;
                s[i]+=c;
            }
        }
        solve(s,1,1);
        if(win.size()>=1)
        {
            //cout<<"win\n";
            cout<<(*(win.begin())).first<<" "<<(*(win.begin())).second;
        }
        else if(draws.size()>=1)
        {
            //cout<<"draw\n";
            cout<<(*(draws.begin())).first<<" "<<(*(draws.begin())).second;
        }
        else 
        {
           // cout<<"lose\n";
            cout<<(*(lose.begin())).first<<" "<<(*(lose.begin())).second;
        }
        cout<<endl;
    }
    return 0;
}
