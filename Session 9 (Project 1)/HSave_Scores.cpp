#include <iostream>
#include <fstream>
#include<vector>
#include<string>

using namespace std;


int main()
{
    /*
    int n = 10;
    string names[n] = {"Parnia","Barbod","Mohammad","Amin","Mani","Kasra","Barsam","Arman","Hadis","Mojraba"};
    int scores[n] = {100,102,98,111,145,193,170,78,98,101};

    //ifstream input;
    ofstream output;

    //input.open(file_name.c_str(),ios::in);

    string file_name = "scores.txt";
    output.open(file_name.c_str(),ios::out);

    for(int i=0;i<n;i++)
    {
        output<<names[i]<<" : "<<scores[i]<<endl;
    }
    */

    int n = 0;

    ifstream input;
    //ofstream output;

    string file_name = "scores.txt";
    input.open(file_name.c_str(),ios::in);

    //output.open(file_name.c_str(),ios::out);

    vector<string> names;
    vector<int> scores;

    string line;
    while(getline(input,line))
    {
        int pos = line.find(":");
        //cout<<pos<<endl;
        //cout<<line.substr(0,pos-1);
        //cout<<"########";
        //cout<<line.substr(pos+2);
        //cout<<"########";
        names.push_back(line.substr(0,pos-1));
        scores.push_back(stoi(line.substr(pos+2)));
    }

    ///Print Data
    for(int i=0;i<names.size();i++)
    {
        cout<<names.at(i)<<"\t"<<scores.at(i)<<endl;
    }
}
