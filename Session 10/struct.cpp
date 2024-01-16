#include<iostream>

using namespace std;

struct Point test(struct Point a);

struct Point {
    int x, y;
};

int main()
{
    struct Point b;
    b.x = 10;
    b.y = 12;
    b = test(b);
    cout<<b.x<<endl<<b.y;
    return 0;
}


struct Point test(struct Point a){
    a.x = a.x/2;
    a.y = a.y/2;

    return a;
}
