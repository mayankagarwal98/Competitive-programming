//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
   		ll n,m;
   		cin>>n>>m;
   		string s1,s2;
   		cin>>s1>>s2;
   		ll dp[102][102];
   		for (int i = 0; i <=max(n,m); ++i)
   		{
   			dp[i][0]=i;
   			dp[0][i]=i;
   		}
   		for (int i = 1; i <=n; ++i)
   		{
   			for (int j = 1; j <=m; j++)
   			{
   				if(s1[i-1]==s2[j-1])
   				{
   					dp[i][j]=dp[i-1][j-1];
   				}
   				else
   				{
   					dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
   				}
   			}
   		}
   		cout<<dp[n][m]<<'\n';
   }
}
