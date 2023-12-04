#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>edge;
map<map<int,int>,int>ans;
int c;

bool isSafe(map<int,int>color,int x,int c){
    if(color[x]){
        return false;
    }
    for(auto it:edge[x]){
        if(color[it]==c){
            return false;
        }
    }
    return true;
}

void dfs(int x,map<int,int>color){
    if(edge.size()==color.size()){
        ans[color]++;
    }
    for(int i=1;i<=c;++i){
        if(isSafe(color,x,i)){
            color[x]=i;
            for(auto it:edge[x]){
                dfs(it,color);
            }
            color.erase(x);
        }
    }
}

void graph_col(int x){
    map<int,int>color;
    dfs(x,color);
}
int main(){
    int e;
    cin>>e;
    int x,y;
    for(int i=0;i<e;++i){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cin>>c;
    graph_col(x);
    cout<<ans.size()<<"\n";
    for(auto it:ans){
        for(auto it1:it.first){
            cout<<it1.first<<"->"<<it1.second;
        }
        cout<<".........................\n";
    }
    return 0;
}
/**
#pragma GCC optimize("03")
#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>edge;
map<map<int,int>,int>ans;
int c;
bool isSafe(int v, int col, map<int,int>color){
    for(auto it : edge[v]){
        if(color[it]==col)
            return false;
    }
    return true;
}

void graph_col1(map<int,int>color,int i){
    if(color.size()==edge.size()){
        ans[color]++;
        return;
    }
    for(int j=1;j<=c;++j){
        if(isSafe(i,j,color)){
            color[i]=j;
            graph_col1(color,i+1);
            color.erase(i);
        }
    }
}
void graph_col(){
    map<int,int>color;
    graph_col1(color,0);
}

int main(){
    int e;
    cin>>e;
    int x,y;
    for(int i=1;i<=e;++i){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cout<<"VERTEX SIZE:"<<edge.size()<<endl;
    cin>>c;
    graph_col();

    cout<<"Master, i found "<<ans.size()<<" solutions after searching as per your order...."<<endl;
    for(auto it : ans){
        cout<<it.second<<"\n";
        for(auto it1 : it.first){
            cout<<it1.first<<"----->"<<it1.second<<"\n";
        }
        cout<<"--------------------------------\n";
    }
    return 0;
}




*/
