#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string number;
    cin>>number;
    bool beauty = false;
    int cnt=0, index[number.length()], i, j=0;
    for(i=0; i<number.length(); i++){
        if(number[i]=='?'){
            cnt++;
            index[j] = i;
            j++;
        }
    }
    int k;
    for(i=0; i<pow(2,cnt) && !beauty; i++){
        j = i;
        k = 0;
        while(k < cnt){
            number[index[k]] = j%2 + 48;
            k++;
            j /= 2;
        }

        beauty = true;
        for(j=1; j<number.length()-1; j++){
            if(number[j]==number[j-1] || number[j]==number[j+1]){
                beauty = false;
                break;
            }
        }
    }
    if(beauty)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
