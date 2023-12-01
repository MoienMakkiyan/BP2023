#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;

    int currunt_page = 0;
    int n_day =0;

    for(int i=1;i<=n;i++)
    {
        //i stands for number of challenge
        int temp; cin>>temp;
        if(i==1) currunt_page = temp;
        if(currunt_page>=temp)
        {
            n_day++;
        }
        else if(currunt_page<temp)
        {
            currunt_page = temp;
        }


        cout<<" i = "<<i<<endl;
        cout<<" a_i = "<<temp<<endl;
        cout<<" currunt_page = "<<currunt_page<<endl;
        cout<<" n_day = "<<n_day<<endl;
    }
    cout<<n_day<<endl;
}
