// https://quera.org/course/assignments/22810/problems

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
     double  x1,y1,x2,y2,x3,y3;
     double S,s1,s2,s3,s4;
     cin >>x1>>y1>>x2>>y2>>x3>>y3;
       s1=(x3-x1)*(y1-y2);
       s2=((x2-x1)*(y1-y2))/2;
       s3=((x3-x1)*(y1-y3))/2;
       s4=((x3-x2)*(y3-y2))/2;
       s1=fabs(s1);
       s2=fabs(s2);
       s3=fabs(s3);
       s4=fabs(s4);
       S=s1-(s2+s3+s4);
       S=s1-(s2+s3+s4);
       S=fabs(S);
     cout<<S<<endl;
     return 0;
}
