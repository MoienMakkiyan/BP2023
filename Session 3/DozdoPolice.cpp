#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int n_police = 0;
    int n_crime = 0;

    for(int i=0; i<n ; i++)
    {
        int temp; cin>>temp;
        if(temp<0&&n_police<1) n_crime+=temp;
        else if(temp<0&&n_police>0) n_police    +=temp;
            else n_police+=temp;
    }
    cout<<n_crime*-1<<endl;

    return 0;
}
