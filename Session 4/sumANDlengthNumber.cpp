#include <iostream>

using namespace std;

int num_length(int n);
int sum_number (int n);

int main()
{
    int n;
    cin>>n;

    cout<<"length = "<<num_length(n)<<endl<<endl;
    cout<<"SUM = "<<sum_number(n)<<endl<<endl;

    return 0;
}

int num_length(int n)
{
    int length=0;
    while (n>0)
    {
        cout<<n<<endl;
        n/=10;
        length++;
    }
    return length;
}

int sum_number (int n)
{
    int sum=0;
    while (n>0)
    {
        cout<<n<<endl;
        sum+=n%10;
        n/=10;
    }
    return sum;
}

