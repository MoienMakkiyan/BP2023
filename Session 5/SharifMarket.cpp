#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int good_id[n];
    for(int i=0;i<n;i++)
        cin>>good_id[i];

    bool exit = false;
    while(!exit)
    {
        int temp;
        cin>>temp;
        if(temp==0) exit=true;
        else {
            int d_id=0;
            for(int i=temp-1;i<n;i++)
            {
                int same=0;
                for(int j=i+1;j<n;j++)
                {
                    cout<<"i = "<<i<<" "<<good_id[i]<<endl;
                    cout<<"j = "<<j<<" "<<good_id[j]<<endl;
                    if(good_id[i]==good_id[j]) same++;
                    cout<<"same = "<<same<<endl;
                }
                if(same==0) d_id++;
            }
            cout<<d_id<<endl;
        }
    }
    return 0;
}
