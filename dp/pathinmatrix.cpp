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
ll n;
ll a[22][22];
ll dp[22][22];
ll pathinmatrix(ll ind,ll m)
{
	if(dp[ind][m]!=-1)
		return dp[ind][m];
	if(ind==n-1)
	{	
		dp[ind][m]=a[ind][m];
		if(m+1<n)
		{
			dp[ind][m]=max(dp[ind][m],a[ind][m+1]);
		}
		if(m>0)
		{
			dp[ind][m]=max(dp[ind][m],a[ind][m-1]);
		}
		return dp[ind][m];
	}
	ll aa=pathinmatrix(ind+1,m);
	if(m+1<n)
	{
		aa=max(aa,pathinmatrix(ind+1,m+1)+a[ind][m+1]);
	}
	if(m>0)
	{
		aa=max(aa,pathinmatrix(ind+1,m-1)+a[ind][m-1]);
	}
	dp[ind][m]=aa;
	return dp[ind][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			cin>>a[i][j];
    			dp[i][j]=-1;
    		}
    	}
    	ll ans=0;
    	for (int i = 0; i < n; ++i)
    	{
    		ans=max(ans,pathinmatrix(1,i)+a[0][i]);
    	}
    	cout<<ans<<'\n';
    }
}
