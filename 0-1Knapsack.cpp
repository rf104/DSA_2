#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int c,n;
int p[2005],w[2005];
int knapscak(int i,int j)
{
    if(i<=0||j<=0) return dp[i][j] = 0;
    else if(dp[i][j]!=-1) return dp[i][j];
    int v1 = knapscak(i-1,j);
    int v2 = -1;
    if(w[i]<=j) v2 = p[i-1]+knapscak(i-1,j-w[i-1]);
    return dp[i][j] = max(v1,v2);
}
int main()
{
    cin>>c>>n;
    int i,j;
    for(int i=0;i<n;i++) cin>>w[i]>>p[i];
    for(int i=0;i<2005;i++)
    {
        for(int j = 0;j<2005;j++)
        {
            dp[i][j] = -1;
        }
    }
    int k = knapscak(n-1,c);
    cout<<k<<endl;
}