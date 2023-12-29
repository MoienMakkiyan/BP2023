#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
using namespace std;

int main(){
    srand(time(0));
    while (true){
        if(GetKeyState(32)) cout<<rand()<<endl;//START & END
        if(GetAsyncKeyState(27)) cout<<"##########"<<endl;// press & do
    }
    return 0;
}
