#include <bits/stdc++.h>
using namespace std;
char adj[110][110];
int visited[110][110];
int n;
int m;
int count1;
void dfs(int x, int y)
{
    visited[x][y]=2;
    if(x-1>=0 && visited[x-1][y]!=2 && adj[x-1][y]=='X')
    dfs(x-1,y);
    if(x+1<n && visited[x+1][y]!=2 && adj[x+1][y]=='X')
    dfs(x+1,y);
    if(y-1>=0 && visited[x][y-1]!=2 && adj[x][y-1]=='X')
    dfs(x,y-1);
    if(y+1<m && visited[x][y+1]!=2 && adj[x][y+1]=='X')
    dfs(x,y+1);
    return;
}
void sum1(int x, int y)
{
    if(adj[x][y]=='X' && visited[x][y]!=2)
    {
        count1++;
        
        dfs(x,y);
    }
    visited[x][y]=1;
    if(x-1>=0 && visited[x-1][y]!=1 && (adj[x-1][y]=='X' || adj[x-1][y]=='*'))
    sum1(x-1,y);
    if(x+1<n && visited[x+1][y]!=1 && (adj[x+1][y]=='X' || adj[x+1][y]=='*'))
    sum1(x+1,y);
    if(y-1>=0 && visited[x][y-1]!=1 && (adj[x][y-1]=='X' || adj[x][y-1]=='*'))
    sum1(x,y-1);
    if(y+1<m && visited[x][y+1]!=1 && (adj[x][y+1]=='X' || adj[x][y+1]=='*'))
    sum1(x,y+1);
    return;
}
int main()
{
    int i,j,k,a;
    int arr[100];
    k=1;
    while(true)
    {
        cin>>m>>n;
        if(m==0)
        break;
        for(i=0;i<n;i++)
        cin>>adj[i];
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        visited[i][j]=0;
        a=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if((adj[i][j]=='*' || adj[i][j]=='X') && visited[i][j]==0)
            {
                count1=0;
                sum1(i,j);
                arr[a++]=count1;
            }
        }
        sort(arr,arr+a);
        cout<<"Throw "<<k<<endl;
        cout<<arr[0];
        for(i=1;i<a;i++)
        cout<<" "<<arr[i];
        cout<<endl<<endl;
        k++;
    }
    return 0;
}
