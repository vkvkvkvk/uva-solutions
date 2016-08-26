#include <bits/stdc++.h>
using namespace std;
bool arr1[110][110];
bool arr2[110][110];
bool arr3[110][110];
bool arr4[110][110];
bool visited[110][110];
bool ser[101][101][510];
int dist[110][110];
int n;
int m;
typedef pair<int, pair<int, int> > ppi;
priority_queue <ppi, vector <ppi>, greater <ppi>> q;
void bfs(int x, int y, int d)
{
    visited[x][y]=true;
    dist[x][y]=d;
    int i,j,k;
    q.push(make_pair(0,make_pair(x,y)));
    while(!q.empty())
    {
        d=q.top().first;
        x=q.top().second.first;
        y=q.top().second.second;
        q.pop();
      //  cout<<"vishal"<<endl;
        if(arr1[x][y] && !visited[x-1][y])
        {
            visited[x-1][y]=true;
            dist[x-1][y]=dist[x][y]+1;
            if(ser[x-1][y][dist[x-1][y]])
            {
            i=x;
            j=y;
            while(ser[i-1][j][dist[i-1][j]])
                dist[i-1][j]++;
            }
            q.push(make_pair(dist[x-1][y],make_pair(x-1,y)));
        }
        if(arr2[x][y] && !visited[x+1][y])
        {
            visited[x+1][y]=true;
            dist[x+1][y]=dist[x][y]+1;
            if(ser[x+1][y][dist[x+1][y]])
            {
            i=x;
            j=y;
            while(ser[i+1][j][dist[i+1][j]])
                dist[i+1][j]++;
            }
            q.push(make_pair(dist[x+1][y],make_pair(x+1,y)));
        }
        if(arr3[x][y] && !visited[x][y-1])
        {
            visited[x][y-1]=true;
            dist[x][y-1]=dist[x][y]+1;
            if(ser[x][y-1][dist[x][y-1]])
            {
            i=x;
            j=y;
            while(ser[i][j-1][dist[i][j-1]])
                dist[i][j-1]++;
            }
            q.push(make_pair(dist[x][y-1],make_pair(x,y-1)));
        }
         if(arr4[x][y] && !visited[x][y+1])
        {
            visited[x][y+1]=true;
            dist[x][y+1]=dist[x][y]+1;
            if(ser[x][y+1][dist[x][y+1]])
            {
            i=x;
            j=y;
            while(ser[i][j+1][dist[i][j+1]])
                dist[i][j+1]++;
            }
            q.push(make_pair(dist[x][y+1],make_pair(x,y+1)));
        }
    }
}
int main()
{
    int i,j,k,r,p;
    int x,y,a,b,z;
    while(scanf("%d",&m)!=EOF)
    {
       cin>>n;
       cin>>r;
       for(i=0;i<=n;i++)
       {
           for(j=0;j<=m;j++)
           {
               arr1[i][j]=true;
               arr2[i][j]=true;
               arr3[i][j]=true;
               arr4[i][j]=true;
               visited[i][j]=false;
               dist[i][j]=0;
           }
       }
       for(i=0;i<=m;i++)
        arr1[0][i]=false;
       for(i=0;i<=m;i++)
        arr2[n-1][i]=false;
       for(i=0;i<=n;i++)
        arr3[i][0]=false;
       for(i=0;i<=n;i++)
        arr4[i][m-1]=false;
       for(i=1;i<=r;i++)
       {
           cin>>y>>x>>b>>a;
           if(x==a)
           {
              if(y>b)
              {
                  arr3[x][y]=false;
              }
              else
               arr4[x][y]=false;
           }
          else if(y==b)
           {
              if(x>a)
              {
                  arr1[x][y]=false;
              }
              else
                arr2[x][y]=false;

           }
       }
       for(i=0;i<101;i++)
       for(j=0;j<101;j++)
       for(k=0;k<501;k++)
       ser[i][j][k]=false;
       cin>>p;
       for(i=1;i<=p;i++)
       {
           cin>>z;
           cin>>y>>x;
           ser[x][y][z]=true;
       }
       bfs(0,0,0);
       cout<<dist[n-1][m-1]<<endl;
       }
       return 0;
}
