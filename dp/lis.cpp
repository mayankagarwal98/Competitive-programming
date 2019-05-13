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
// dp solution 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	ll a[302];
    	cin>>n;
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>a[i];
    	}
    	ll lis[400];
    	lis[0]=1;
    	for (int i = 1; i < n; ++i)
    	{
    		lis[i]=1;
    		for (int j = 0; j < i; ++j)
    		{
    			if(a[j]<a[i] && lis[i]<lis[j]+1)
    			{
    				lis[i]=lis[j]+1;
    			}
    		}
    		// cout<<lis[i]<<" ";
    	}
    	// cout<<'\n';
    	ll max=0;
    	for (int i = 0; i < n; ++i)
    	{
    		if(lis[i]>max)
    		{
    			max=lis[i];
    		}
    	}
    	cout<<max<<'\n';
    }
}



// nlog(n) solution 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[1002];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>a[i];
    	}
    	ll len=0;
    	std::vector<ll> ans;
    	ans.pb(a[0]);
    	for (int i =1; i < n; ++i)
    	{
    		if(a[i]>ans[ans.size()-1])
    		{
    			ans.pb(a[i]);
    		}
    		else
    		{
    			ll z=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
    			ans[z]=a[i];
    		}
    	}	
    	cout<<ans.size();
    	cout<<'\n';
    }

}
