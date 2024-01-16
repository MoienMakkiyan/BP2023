#include <iostream>

using namespace std;

int main()
{
    long long int f=0;
    long long int m,n; cin>>m>>n;
    int d[m][n];
    for(long long int i=0;i<m;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            cin>>d[i][j];
        }
    }
    for(long long int i=0;i<m;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            long long int a1=0,a2=0,a3=0,a4=0;
            if(d[i][j]==1)
            {
                for(long long int q=j+1;q<n;q++)
                    if(d[i][q]==1) a1++;
                for(long long int q=i+1;q<m;q++)
                    if(d[q][j]==1) a2++;
                for(long long int q=j-1;q>-1;q--)
                    if(d[i][q]==1) a3++;
                for(long long int q=i-1;q>-1;q--)
                    if(d[q][j]==1) a4++;
            }
            f+=((a1*a2)+(a2*a3)+(a3*a4)+(a4*a1));
        }
    }
    cout<<f;
    return 0;
}
