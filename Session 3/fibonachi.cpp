#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int temp1 = 0;
    int temp2 = 1;
    int output = 0;
    for(int i=0;i<n;i++)
    {
        if(i==0) cout<<"No = 1"<<endl;
        else{
            output = temp1+temp2;
            temp1 = temp2;
            temp2 = output;
            cout<<"No"<<i+1<<" = "<<output<<endl;
        }
    }

}
