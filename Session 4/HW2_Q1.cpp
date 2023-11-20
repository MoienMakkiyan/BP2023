#include <iostream>
#include <math.h>

using namespace std;

int num_length(int n);
int sum_number (int n);

int main()
{
    int m ; cin>>m;
    int s ; cin>>s;

    //int isFound = 0;
    bool isFound = false;

    ///INT_MAX is maximum value of integer & INT_MIN is minimum value of integer!

    int min_num = INT_MAX;
    int max_num = INT_MIN;

    for(int i=1;i<pow(10,m);i++)
    {
        if(num_length(i)==m&&sum_number(i)==s)
        {
            //isFound++;
            isFound = true;
            if(i>max_num) max_num = i;
            if(i<min_num) min_num = i;
        }
    }

    //if(isFound!=0)
    if(isFound)
        cout<<min_num<<" "<<max_num<<endl;
    else cout<<"-1 -1"<<endl;
    return 0;
}

int num_length(int n)
{
    int length=0;
    while (n>0)
    {
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
        sum+=n%10;
        n/=10;
    }
    return sum;
}
