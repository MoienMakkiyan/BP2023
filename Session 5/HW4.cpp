#include <iostream>

using namespace std;

int main()
{
    long int n;
    cin>>n;
    long int m; cin>>m;
    long long int good_id[n];
    for(int i=0;i<n;i++)
        cin>>good_id[i];

    for(int l=0;l<m;l++)
    {
        long int temp;
        cin>>temp;
            int d_id=0;
            for(int i=temp-1;i<n;i++)
            {
                int same=0;
                for(int j=i+1;j<n;j++)
                {
                    //cout<<"i = "<<i<<" "<<good_id[i]<<endl;
                    //cout<<"j = "<<j<<" "<<good_id[j]<<endl;
                    if(good_id[i]==good_id[j]) same++;
                    //cout<<"same = "<<same<<endl;
                }
                if(same==0) d_id++;
            }
            cout<<d_id<<endl;
    }
    return 0;
}
