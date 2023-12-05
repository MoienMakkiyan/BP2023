#include<iostream>

using namespace std;

void m_swap (int &a,int &b);

int main()
{
    int n = 10;
    int a[n] = {1,11,111,12,13,15,16,8,9,100};

    for(int j=0;j<n;j++)
        {
            for(int i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1]) m_swap(a[i],a[i+1]);
            }
        }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}

void m_swap (int &a,int &b)
{
    swap(a,b);
}
