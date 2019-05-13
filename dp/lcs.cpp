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
    	ll a[102][102];
    	for (int i = 0; i <=max(n,m); ++i)
    	{
    		a[i][0]=0;
    		a[0][i]=0;
    	}
    	for (int i = 1; i <=n; ++i)
    	{
    		for (int j = 1; j <=m ; ++j)
    		{
    			if(s1[i-1]==s2[j-1])
    			{
    				a[i][j]=a[i-1][j-1]+1;
    			}
    			else
    			{
    				a[i][j]=max(a[i-1][j],a[i][j-1]);
    			}
    		}
    	}
    	cout<<a[n][m]<<'\n';
    }
}
