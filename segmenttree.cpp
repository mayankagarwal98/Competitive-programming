//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll b[4000002]={0};
ll a[1000002];
void constructtree(int low,int high,int pos)
{
	if (high<=low)
	{
		b[pos]=a[low];
		return ;
	}
	int mid=(low+high)/2;
	constructtree(low,mid,2*pos+1);
	constructtree(mid+1,high,2*pos+2);
	b[pos]=b[2*pos+1]+b[2*pos+2];
	
}
ll query(int low,int high,int l,int r,int pos)
{
	ll mid=(low+high)/2;
	if(low<=l && high>=r)
	{
		return a[pos];
	}
	else if(l>mid)
	{
		return query(mid+1,high,l,r,2*pos+2);
	}
	else if(r<=mid)
	{
		return query(low,mid,l,r,2*pos+1);
	}
	else
	{
		return query(low,mid,l,mid,2*pos+1)+query(mid+1,high,mid+1,r,2*pos+2);
	}
}
void update(int low,int high,int index,int value,int pos)
{	
	if (index==low && index==high)
	{
		b[pos]=value;
		return;
	}
	int mid=(low+high)/2;
	if(low<=index && mid>=index)
	{
		update(low,mid,index,value,2*pos+1);
	} 
	else
	{
		update(mid+1,high,index,value,2*pos+2);
	}
	if(flag==0)
	{
		b[pos]=b[2*pos+1]^b[2*pos+2];
	}
	else
	{
		b[pos]=b[2*pos+1]|b[2*pos+2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
}
