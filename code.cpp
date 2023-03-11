#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back


using namespace __gnu_pbds;
using namespace std;

typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
//ordered_multiset s3;
//ordered_multiset :: iterator it;
const ll mod=1e9+7;
ll comb[55][55];
const ll N=1e1;
bool sive[N];
vector<ll>prime;
deque<char>v;

//long long int gcd(long long int a,long long int b)
//{
//    long long int c;
//    while(a%b!=0)
//    {
//        c=b;
//        b=a%b;
//        a=c;
//    }
//    return b;
//}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    for(i=0; i<N; i++)
    {
        sive[i]=true;
    }
    sive[0]=false;
    sive[1]=false;
    for(i=2; i*i<=N; i++)
    {
        if(sive[i])
        {
            for(j=i*i; j<N; j+=i)
            {
                sive[j]=false;
            }
        }
    }
    for(i=0; i<N; i++)
    {
        if(sive[i]==true)
            prime.pb(i);
    }
    for(i=0; i<=50; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(i==j)
                comb[i][j]=1;
            else if(j==0)
                comb[i][j]=1;
            else
                comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
        }
    }



    //start main funciton
    ll n,m,a,b,c,d,ans,mx,mn;
    cin>>n>>m;
    a=n-m+1;
    mx=(a*(a-1))/2;
    b=n/m;
    if(b*m==n)
    {
        ans=(b*(b-1))/2;
        mn=ans*m;

    }
    else{
       d=n-b*m;
       c=m-d;
       ans=0;
       ans+=(b*(b-1))/2;
       ans*=c;
       b++;
       ans+=((b*(b-1))/2)*d;
       mn=ans;
    }
    cout<<mn<<" "<<mx;







    return 0;
}
