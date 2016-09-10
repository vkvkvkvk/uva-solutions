#include <bits/stdc++.h>
using namespace std;
int table[30][30];
int arr[10];
int n;
int m;
int s;
int max1;
void back_track(int i, int fair, int total)
{
    if(i==s)
    {
        if(fair>max1)
        max1=fair;
        return;
    }
    int j,k;
    k=0;
    int set1[30];
    for(j=0;j<m;j++)
    {
        if(table[j][1]==i)
        {
            set1[k++]=j;
        }
    }
    int a,b,x,y;
    for(a=0;a<(1<<k);a++)
    {
        x=total;
        for(b=0;b<k;b++)
        {
            if((a & (1<<b)))
            {
              x+=table[set1[b]][3];  
            }
        }
        x-=arr[i];
        y=0;
        if(x<=n)
        {
         for(b=0;b<k;b++)
         {
            if((a&(1<<b)))
            {
                arr[table[set1[b]][2]]+=table[set1[b]][3];
                y+=table[set1[b]][3]*(table[set1[b]][2]-table[set1[b]][1]);
            }
         }
         back_track(i+1,fair+y,x);
         for(b=0;b<k;b++)
         {
         if((a&(1<<b)))
            {
                arr[table[set1[b]][2]]-=table[set1[b]][3];
            }
         }
        }
    }
    return;
}
int main()
{
    int i;
    while(true)
    {
        cin>>n>>s>>m;
        if(n==0)
        break;
        s=s+1;
        for(i=0;i<m;i++)
        {
            cin>>table[i][1];
            cin>>table[i][2];
            cin>>table[i][3];
        }
        max1=0;
        back_track(0,0,0);
        cout<<max1<<endl;
    }
    return 0;
}
