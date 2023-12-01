#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int m; cin>>m;

    int line[n];
    for(int i=0;i<n;i++)
        line[i]=0;

    for(int i=0;i<m;i++)
    {
        int temp;
        cin>>temp;
        line[temp-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        cout<<line[i];
    }
}
