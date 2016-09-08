#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
int ans[10];
int n;
int length;
bool visited[10];
bool flag;
void back_track(int s, int count1)
{
    visited[s]=true;
    ans[count1]=s;
    if(count1==length)
    {
       int i;
       cout<<"("<<ans[0]+1;
       for(i=1;i<=length;i++)
       cout<<","<<ans[i]+1;
       cout<<")"<<endl;
       visited[s]=false;
       flag=true;
       return;
    }
    int i;
    for(i=0;i<n;i++)
    {
        if(!visited[i] && arr[s][i]==1)
        {
            back_track(i,count1+1);
        }
    }
    visited[s]=false;
}
int main()
{
    int i,j,d;
    while(true)
    {
    cin>>n;
    cin>>length;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>arr[i][j];
    flag=false;
    back_track(0,0);
    if(!flag)
    printf("no walk of length %d\n",length);
    if(scanf("%d",&d)==EOF)
    break;
    else
    cout<<endl;
    }
    return 0;
}
