#include <bits/stdc++.h>
using namespace std;
int row[9];
int y;
int n;
int count1;
bool check1(int r, int c)
{
    if(abs(c-y)==abs(r-row[y]))
        return false;
    if(row[y]==r)
        return false;
    int i;
    for(i=1;i<c;i++)
    {
        if(abs(c-i)==abs(r-row[i]))
            return false;
        if(r==row[i])
            return false;
    }
    return true;
}
void back_track(int c)
{
    if(c==n+1)
    {
        int i;
        printf("%2d",count1);
        cout<<"     ";
        for(i=1;i<=n;i++)
            cout<<" "<<row[i];
        cout<<endl;
        count1++;
        return;
    }
    if(c==y)
    {
        back_track(c+1);
        return;
    }
    int r;
    for(r=1;r<=n;r++)
    {
        if(check1(r,c))
        {
          row[c]=r;
          back_track(c+1);
        }
    }
    return;
}
int main()
{
    n=8;
    int t;
    cin>>t;
    while(t--)
    {
    int x;
    cin>>x;
    cin>>y;
    row[y]=x;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    count1=1;
    back_track(1);
    if(t>0)
    cout<<endl;
    }
    return 0;
}
