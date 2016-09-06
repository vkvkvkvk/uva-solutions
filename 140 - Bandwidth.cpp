#include <bits/stdc++.h>
using namespace std;
bool adj[27][27];
int str[10];
bool hash1[27];
int n;
int max1;
int ans[10];
void add_edge(int x, int y)
{
    adj[x][y]=true;
    adj[y][x]=true;
    return;
}
void swap1(int i, int j)
{
    int c=str[j];
    int k;
    for(k=j-1;k>=i;k--)
    {
     str[k+1]=str[k];
   //  hash1[k]++;
    }
    str[i]=c;
  //  hash1[c]=i;
    return;
}
void swap2(int i, int j)
{
    int c=str[i];
    int k;
    for(k=i;k<j;k++)
    {
        str[k]=str[k+1];
   //     hash1[k+1]--;
    }
    str[j]=c;
   // hash1[c]=j;
    return;
}
int find_index(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(str[i]==x)
        return i;
    }
}
void check1()
{
    int i,j,x;
    int max2=0;
    for(i=1;i<=n;i++)
    {
     x=str[i];   
       for(j=0;j<26;j++)
       {
           if(adj[x][j])
           {
               if(abs(find_index(j)-i)>max2)
               max2=abs(find_index(j)-i);
           }
       }
    }
    if(max2<max1)
    {
        max1=max2;
        for(i=1;i<=n;i++)
        ans[i]=str[i];
    }
}
void permute(int i)
{
    if(i==n)
    {
        check1();
    }
    int j=i;
    while(j<=n)
    {
        swap1(i,j);
        permute(i+1);
        swap2(i,j);
        j++;
    }
    return;
}
int main()
{
    int i,j,x,y;
    string str1;
    while(true)
    {
    cin>>str1;
    if(str1[0]=='#')
    break;
    for(i=0;i<27;i++)
    hash1[i]=false;
    for(i=0;i<27;i++)
    for(j=0;j<27;j++)
    adj[i][j]=false;
    for(i=0;i<str1.length();i++)
    {
        if(str1[i]!=':' && str1[i]!=';')
        hash1[str1[i]-'A']=true;
    }
    j=1;
    for(i=0;i<26;i++)
    {
        if(hash1[i])
        str[j++]=i;
    }
    n=j-1;
    sort(str,str+n);
    i=0;
    while(i<str1.length())
    {
        x=str1[i]-'A';
        i=i+2;
        while(i<str1.length() && str1[i]!=';')
        {
            y=str1[i]-'A';
            add_edge(x,y);
            i++;
        }
        i++;
    }
    max1=10000;
    permute(1);
    for(i=1;i<=n;i++)
    {
        printf("%c ",ans[i]+'A');
    }
    cout<<"-> "<<max1<<endl;
    }
    return 0;
}
