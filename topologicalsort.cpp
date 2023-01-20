#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
void dfs(int **arr,int v,bool *visited,stack<int>&s)
{
    visited[v]=true;
    for(int i=0;i<v;i++)
    {
        if(arr[v][i]==1)
        {
            if(!visited[i])
        {
            dfs(arr,i,visited,s);
        }
    }
    }
  s.push(v);
}
void bfs(int **arr,int v,bool *visited,int *indegree)
{
    queue<int>q;
    vector<int>k;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        k.push_back(p);
        for(int i=0;i<v;i++)
        {

    if(!visited[i]&&arr[p][i]==1)
        {
            if(--indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
    }
    for(int i=0;i<k.size();i++)
    {
        cout<<k[i]<<" ";
    }
}


int main()
{
    int v,e;
    cout<<"enter vertices"<<endl;
    cin>>v;
    cout<<"enter edge"<<endl;
    cin>>e;
    int **arr=new int*[v];

    for(int i=0;i<v;i++)
    {
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }
    int indegree[v]={0};
    for(int i=0;i<e;i++)
    {
        int u,p;
        cin>>u;
        cin>>p;
        arr[u][p]=1;
        indegree[p]++;
    }
    //cout<<indegree[2]<<endl;
    /*for(int i=0;i<v;i++)
    {

        for(int j=0;j<v;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    /*
    stack<int>s;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            dfs(arr,i,visited,s);
      for(int i=0; i<v; i++)
    {
        cout<<s.top();
         s.pop();


    }
    cout<<endl;
    */
bfs(arr,v,visited,indegree);
}
