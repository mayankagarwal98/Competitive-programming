std::vector<pair<ll,ll>> v[500002];
int visited[500002];
ll minimumlength=0;
void minimunspanningtree(int x)
{
	priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>  pp;
	for (int i = 0; i < v[x].size(); ++i)
	{
		pp.push(mp(v[x][i].second,v[x][i].first));
	}
	visited[x]=1;
	while(!pp.empty())
	{
		pair<ll,ll> z=pp.top();
		pp.pop();
        int vertex=z.second;
        int weight=z.first;
        if(visited[vertex]==0)
        {
            minimumlength+=weight;
			for (int i = 0; i < v[vertex].size(); ++i)
			{
				if(visited[v[vertex][i].first]==0)
					pp.push(mp(v[vertex][i].second,v[vertex][i].first));
			}
		}
		visited[vertex]=1;
	}

} 