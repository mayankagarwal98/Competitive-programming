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
ll a[300002];
std::vector<ll> b[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m,u;
    cin>>n>>m>>u;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    ll len=(int)sqrt(n+0.0)+1;
    for (int i = 0; i <n ; ++i)
    {
    	b[i/len].pb(a[i]);
    }
    for (int i = 0; i <=len; ++i)
    {
    	sort(b[i].begin(),b[i].end());
    }
    while(m--)
    {
    	ll l,r,v,p;
    	cin>>l>>r>>v>>p;
    	ll k=0;
    	for (int i = l-1; i <=r-1;)
    	{
    		if(len%i==0 && i+len-1<=r)
    		{

    			ll z=lower_bound(b[i/len].begin(),b[i/len].end(),v)-b[i/len].begin();
    			// cout<<z<<'\n';
    			k+=z;
    			i+=len;
    		}
    		else
    		{
    			if(a[i]<v)
    			{
    				k++;
    			}
    			i++;
    		}
    	}
    	ll aa=(k*u)/(r-l+1);
    	// cout<<k<<" "<<u<<'\n';
    	for (int i = 0; i < b[(p-1)/len].size(); ++i)
    	{
    		if(b[(p-1)/len][i]==a[p-1])
    		{
    			b[(p-1)/len].erase(b[(p-1)/len].begin()+i);
    			break;
    		}
    	}
    	b[(p-1)/len].pb(aa);
    	sort(b[(p-1)/len].begin(),b[(p-1)/len].end());
    	a[p-1]=aa;
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<a[i]<<'\n';
    	}
    }
}
