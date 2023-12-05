#include<iostream>
#include<math.h> //or cmath

using namespace std;

int main()
{
    //ax^2+bx+c=0
    double a;
    double b;
    double c;
    cin>>a>>b>>c;

    double delta = b*b-(4*a*c);
    //double delta = pow(b,2)-(4*a*c);

    if(delta>=0)
    {
        double answer1 = ((-1*b)+sqrt(delta))/(2*a);
        double answer2 = ((-1*b)-sqrt(delta))/(2*a);

        if(answer1==answer2) cout<<answer1<<endl;
        else {
            cout<<answer1<<endl;
            cout<<answer2<<endl;
        }
    }
    else cout<<"This eq. has no real ans!!!"<<endl;
    return 0;
}
