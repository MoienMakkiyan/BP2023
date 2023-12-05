#include<iostream>
#include<time.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int m; cin>>m;

    for(int i=0;i<n;i++)
    {
        //srand(time(0));
        cout<<rand()%(m+1)<<endl;
    }

    return 0;
}
