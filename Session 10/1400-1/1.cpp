#include <iostream>

using namespace std;

int main()
{
    int n , i , j , k;
    cin>>n;
    k=2*n*n-1;
    int arr[n][n];
    for(i=0 ; i<n ; i++)
    {
        for(j=n-1 ; j>=0 ; j--)
        {
            arr[j][i]=k;
            k-=2;
        }
    }
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}
