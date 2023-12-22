#include <algorithm>
#include <iostream>

using namespace std;

template<typename C, typename T>
bool contains(C&& c, T e) {
    return find(begin(c), end(c), e) != end(c);
};

template<typename C, typename T>
void check(C&& c, T e) {
    cout << e << (contains(c,e) ? "" : " not") <<  " found\n";
}

int main()
{
    int test[10]={1,2,3,4,5,6,7,8,9,10};

    check(test,15);

    return 0;
}
