#include <bits/stdc++.h>
using namespace std;
char adj[11][16];
int n;
int m;
bool visited[11][16];
int count1;
int score1;
int count2;
void dfs(int x, int y, char c)
{
    visited[x][y]=true;
    count1++;
    if(x-1>=0 && !visited[x-1][y] && adj[x-1][y]==c)
    dfs(x-1,y,c);
    if(x+1<n && !visited[x+1][y] && adj[x+1][y]==c)
    dfs(x+1,y,c);
    if(y-1>=0 && !visited[x][y-1] && adj[x][y-1]==c)
    dfs(x,y-1,c);
    if(y+1<m && !visited[x][y+1] && adj[x][y+1]==c)
    dfs(x,y+1,c);
    return;
}
void shift_row()
{
    int i,j,k;
    for(j=0;j<15;j++)
    {
        for(i=9;i>0;i--)
        {
            if(adj[i][j]=='E')
            {
            k=i;
            while(adj[k][j]=='E' && k>0)
            k--;
            adj[i][j]=adj[k][j];
            adj[k][j]='E';
            }
        }
    }
    return;
}
bool is_empty(int j)
{
    int i;
    bool flag=true;
    for(i=0;i<10;i++)
    {
        if(adj[i][j]!='E')
        flag=false;
    }
    return flag;
}
int empty_num(int j)
{
    int sum=0;
    while(is_empty(j) &&j<15)
    {
        sum++;
        j++;
    }
    return sum;
}
void shift_column()
{
    int i,j;
    int a;
    for(j=0;j<14;j++)
    {
        a=empty_num(j);
        if(a!=0 && a+j<15)
        {
            for(i=0;i<10;i++)
            {
                adj[i][j]=adj[i][j+a];
                adj[i][j+a]='E';
            }
        }
    }
}
void erase_c(int x, int y, char c)
{
    visited[x][y]=true;
    adj[x][y]='E';
    if(x-1>=0 && adj[x-1][y]==c)
    erase_c(x-1,y,c);
    if(x+1<n &&  adj[x+1][y]==c)
    erase_c(x+1,y,c);
    if(y-1>=0 && adj[x][y-1]==c)
    erase_c(x,y-1,c);
    if(y+1<m && adj[x][y+1]==c)
    erase_c(x,y+1,c);
    return;
}
void process()
{
    int i,j,k;
    int x,y;
    int max1=1;
    count2++;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    visited[i][j]=false;
    for(j=0;j<15;j++)
    {
        for(i=9;i>=0;i--)
        {
            if(adj[i][j]!='E' && !visited[i][j])
            {
             count1=0;
             dfs(i,j,adj[i][j]);
             if(count1>max1)
             {
                 max1=count1;
                 x=i;
                 y=j;
             }
            }
        }
    }
    if(max1==1)
    return;
    printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",count2,9-x+1,y+1,max1,adj[x][y],(max1-2)*(max1-2));
    score1+=(max1-2)*(max1-2); 
    erase_c(x,y,adj[x][y]);
    shift_row();
    shift_column();
    process();
    return;
}
int count5()
{
    int i,j,sum;
    sum=0;
    for(i=0;i<10;i++)
    for(j=0;j<15;j++)
    if(adj[i][j]!='E')
    sum++;
    return sum;
}
int main()
{
    int i,j,k,t;
    string str;
    scanf("%d\n",&t);
    k=1;
    n=10;
    m=15;
    int ad=t;
    while(t--)
    {
        for(i=0;i<10;i++)
        cin>>adj[i];
        count2=0;
        cout<<"Game "<<k<<":"<<endl<<endl;
        score1=0;
        process();
        if(count5()==0)
        score1+=1000;
        cout<<"Final score: "<<score1<<", with "<<count5()<<" balls remaining."<<endl;
        if(k<ad)
        cout<<endl;
        k++;
    }
    return 0;
}
