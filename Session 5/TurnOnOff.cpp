#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int m; cin>>m;

    int lamp_stat[n];
    for(int i=0;i<n;i++)
        lamp_stat[i]=1;

    int lamp_key[n];
    for(int i=0;i<n;i++)
        lamp_key[i]=0;

    for(int i=0;i<m;i++)
    {
        int temp; cin>>temp;
        for(int j=temp-1;j<n;j++)
        {
            if(lamp_stat[j]==1)
            {
                lamp_stat[j]=0;
                lamp_key[j]=temp;
            }
            for(int k:lamp_stat)
                cout<<k;
            cout<<endl;
            for(int k:lamp_key)
                cout<<k;
            cout<<endl;
        }
    }
}
