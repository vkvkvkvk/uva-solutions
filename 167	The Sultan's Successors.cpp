#include <bits/stdc++.h>
using namespace std;
int n;
int row;
int ld;
int rd;
int count1;
int max1;
int arr[10][10];
void back_track(int c)
{
    if(c==n+1)
    {
       if(count1>max1)
       max1=count1;
       return;
    }
    int r;
    for(r=1;r<=n;r++)
    {
        if(((row &(1<<r))==0) && ((rd &(1<<r+c))==0) && (ld&(1<<r-c+n-1))==0)
        {
          row=(row | (1<<r));
          rd=(rd | (1<<r+c));
          ld=(ld | (1<<r-c+n-1));
          count1+=arr[r][c];
          back_track(c+1);
          row=(row & ~(1<<r));
          rd=(rd & ~(1<<r+c));
          ld=(ld & ~(1<<r-c+n-1));
          count1-=arr[r][c];
        }
    }
    return;
}
int main()
{
    int i,j,t;
    n=8;
    cin>>t;
    while(t--)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        cin>>arr[i][j];
        max1=0;
        count1=0;
        back_track(1);
        printf("%5d\n",max1);
    }
    return 0;
}
