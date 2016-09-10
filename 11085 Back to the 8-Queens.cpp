#include <bits/stdc++.h>
using namespace std;
int arr[10];
int n;
int row;
int ld;
int rd;
int min1;
void back_track(int c, int value)
{
    if(c==n+1)
    {
        if(value<min1)
        min1=value;
        return;
    }
    int r;
    for(r=1;r<=n;r++)
    {
        if((row & (1<<r))==0 && (ld & (1<<r-c+n-1))==0 && (rd & (1<<r+c))==0)
        {
            row=(row |(1<<r));
            ld=(ld | (1<<r-c+n-1));
            rd=(rd | (1<<r+c));
            if(arr[c]==r)
            back_track(c+1,value);
            else
            back_track(c+1,value+1);
            row=(row & (~(1<<r)));
            ld=(ld  &(~(1<<r-c+n-1)));
            rd=(rd &(~(1<<r+c)));
        }
    }
    return;
}
int main()
{
    n=8;
    int i,j;
    j=1;
    while(scanf("%d",&arr[1])!=EOF)
    {
        for(i=2;i<=n;i++)
        cin>>arr[i];
        min1=1000;
        back_track(1,0);
        cout<<"Case "<<j<<": ";
        cout<<min1<<endl;
        j++;
    }
    return 0;
}
