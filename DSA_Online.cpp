/**#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj_list(n);
    vector<int>indeg(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        indeg[v]++;
    }
    queue<int>pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it : adj_list[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                pq.push(it);
            }
        }
    }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int>pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                pq.push(it);
            }
        }
    }
}
*/

#include<bits/stdc++.h>
using namespace std;
int dp[250][250],s[250][250];
void init()
{
    for(int i=0;i<250;i++)
    {
        for(int j =0;j<250;j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
}
int MCM(int arr[],int i,int j)
{
    if(i==j)
    {
        dp[i][j]=0;
        s[i][j]  = 0;
        return dp[i][j];
    }
    else if(dp[i][j]!=INT_MAX) return dp[i][j];
    else{
        for(int k = i;k<j;k++)
        {
            int cst = dp[i][j];
            dp[i][j] = min(dp[i][j],MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
            if(dp[i][j]!=cst)
            {
                s[i][j] = k;
            }
        }
        return dp[i][j];
    }
}
int main()
{
    init();
    int arr[] = {5,4,6,2,7};

    cout<<MCM(arr,1,4)<<endl;
}




































