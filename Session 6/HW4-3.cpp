#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m; cin>>m;
    int good_id[n];
    for(int i=0;i<n;i++)
        cin>>good_id[i];

    int temp;
    int d_id=0;
    int same=0;

    for(int l=0;l<m;l++)
    {
        cin>>temp;
            d_id=0;
            for(int i=temp-1;i<n;i++)
            {
                same=0;
                for(int j=i+1;j<n;j++)
                {
                    if(good_id[i]==good_id[j])
                    {
                        same++;
                        break;
                    }
                }
                if(same==0) d_id++;
            }
            cout<<d_id<<endl;
    }
    return 0;
}
