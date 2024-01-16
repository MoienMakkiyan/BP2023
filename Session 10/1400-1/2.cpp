#include <iostream>

using namespace std;

int main()
{
   string s;
   int i,j;
   getline(cin,s);
   int l=s.size();
   for(i=97;i<=122;i++){
    for(j=0;j<l;j++){
        if(s[j]==i || s[j]==i-32){
            break;
        }
    }
    if(j==l){
        cout<<"NO";
        return 0;
    }
   }
   cout<<"YES";
   return 0;
}
