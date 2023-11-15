//https://quera.org/course/assignments/22949/problems

#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int zn = 0;
    double output = n;
    while(output>10)
    {
        output/=10.0;
        zn++;
    }
    cout<<output<<"e"<<zn<<endl;
    return 0;
}
