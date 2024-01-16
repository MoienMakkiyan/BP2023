#include <iostream>

using namespace std;

int main()
{
    int n, cnt=0;
    cin>>n;
    int numbers[n];
    for(int i=0; i<n; i++)
        cin>>numbers[i];
    for(int i=1; i<n-1; i++){
        if(numbers[i]>numbers[i-1] && numbers[i]>numbers[i+1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
