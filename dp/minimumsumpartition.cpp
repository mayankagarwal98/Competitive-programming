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
ll a[100];
ll sumtotal=0;
ll dp[53][2502];
ll setpartition(ll ind,ll sum)
{
	if(dp[ind][sum]!=-1)
		return dp[ind][sum];
	if(ind==0)
	{
		dp[ind][sum]=abs(sumtotal-2*sum);
	}
	else
		dp[ind][sum]=min(setpartition(ind-1,sum+a[ind-1]),setpartition(ind-1,sum));
	return dp[ind][sum];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	sumtotal=0;
    	ll n;
    	cin>>n;
    	for (int i = 0; i <=n; ++i)
    	{
    		for (int j = 0; j <=2500 ; ++j)
    		{
    			dp[i][j]=-1;
    		}
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>a[i];
    		sumtotal+=a[i];
    	}
    	cout<<min(setpartition(n-1,a[n-1]),setpartition(n-1,0))<<'\n';
    }
}
