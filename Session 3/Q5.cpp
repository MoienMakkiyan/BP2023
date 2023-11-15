//https://quera.org/course/assignments/22942/problems

#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int m_max1 = 0;
    int m_max2 = 0;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        if(m_max1<temp)
        {
            m_max2 = m_max1;
            m_max1 = temp;
        }
        else if(m_max2<temp) m_max2 = temp;
    }
    if(m_max1==m_max2) cout<<"Error!"<<endl;
    else cout<<m_max2<<endl;
}
