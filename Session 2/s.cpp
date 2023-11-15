#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    // 5 - 4- 3
    int ans_5, ans_4, ans_3;

    if(n%5==0) ans_5 = n/5;
    else ans_5 = n/5+1;

    if(n%4==0) ans_4 = n/4;
    else ans_4 = n/4+1;

    if(n%3==0) ans_3 = n/3;
    else ans_3 = n/3+1;

    cout<<ans_5<<endl;
    cout<<ans_4<<endl;
    cout<<ans_3<<endl;

    return 0;
}
