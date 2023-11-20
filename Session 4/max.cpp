#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int sum = 0;

    while(true)
    {
        int temp = 0;
        cin>>temp;
        if(temp==-1) break;
        sum+=temp;
        number++;
    }
    cout<<sum/number<<endl;
    return 0;
}
