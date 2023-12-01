#include <iostream>

using namespace std;

void fib(int n);

int main() {
  int myNumbers[5] = {10, 20, 30, 40, 50};
  for(int i:myNumbers)
    fib(i);
  return 0;
}


void fib(int n)
{
    int temp1 = 0;
    int temp2 = 1;
    int output = 0;
    for(int i=0;i<n;i++)
    {
        if(i==0) cout<<"No = 1"<<endl;
        else{
            output = temp1+temp2;
            temp1 = temp2;
            temp2 = output;
            cout<<"No"<<i+1<<" = "<<output<<endl;
        }
    }

}
