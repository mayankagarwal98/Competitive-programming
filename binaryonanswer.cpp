ll  i=0,j=n-1;
    while(i<j)
    {
    	ll mid=(i+j+1)/2;
    	if(check(mid+1))
    	{
    		i=mid;
    	}
    	else
    	{
    		j=mid-1;
    	}
    }
    cout<<j+1<<'\n';