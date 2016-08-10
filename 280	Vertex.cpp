#include <iostream>
using namespace std;
int adj[110][110];
int n;
bool visited[110];
int t;
int a;
void dfs(int s)
{
    t++;
    if(t==1 && s==a);
   // cout<<"vihal"<<endl;
    else
    {
    visited[s]=true;
  //  cout<<"kumar"<<endl;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        if(!visited[i] && adj[s][i]==1)
        dfs(i);
    }
    t++;
    return;
}
int main()
{
    int i,x,y,k,s,j;
    while(true)
    {
        cin>>n;
        if(n==0)
        break;
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        adj[i][j]=0;
        for(i=0;i<=n;i++)
        visited[i]=false;
        while(true)
        {
            cin>>x;
            if(x==0)
            break;
            while(true)
            {
                cin>>y;
                if(y==0)
                break;
                adj[x][y]=1;
            }
        }
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>s;
            t=0;
            a=s;
            for(i=0;i<=n;i++)
            visited[i]=false;
            dfs(s);
            int count=0;
            for(i=1;i<=n;i++)
            {
                if(!visited[i])
                count++;
            }
            cout<<count;
            for(i=1;i<=n;i++)
            {
                if(!visited[i])
                cout<<" "<<i;
            }
            cout<<endl;
        }
    }
    return 0;
}
