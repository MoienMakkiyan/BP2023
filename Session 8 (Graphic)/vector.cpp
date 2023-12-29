/// https://www.w3schools.blog/cpp-vector

#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> xs;
    vector<int> ys;

    int x_temp;
    int y_temp;

    while(true)
    {
        cout<<"Please Enter Your X and Y : "<<endl;
        cin>>x_temp;
        cin>>y_temp;
        xs.push_back(x_temp);
        ys.push_back(y_temp);
        for(int i=0;i<xs.size();i++)
        {
            cout<<"X = "<<xs.at(i)<<endl;
            cout<<"Y = "<<ys.at(i)<<endl;
        }
    }
    return 0;
}
