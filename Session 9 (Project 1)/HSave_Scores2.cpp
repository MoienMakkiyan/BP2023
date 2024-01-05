#include <iostream>
#include <fstream>
#include<vector>
#include<string>

using namespace std;


int main()
{
    ///Read Data
    ifstream input;

    string file_name = "scores.txt";
    input.open(file_name.c_str(),ios::in);

    vector<string> names;
    vector<int> scores;

    string line;
    while(getline(input,line))
    {
        int pos = line.find(":");
        names.push_back(line.substr(0,pos-1));
        scores.push_back(stoi(line.substr(pos+2)));
    }

    ///Print Data
    cout<<"First Data :"<<endl;
    for(int i=0;i<names.size();i++)
    {
        cout<<names.at(i)<<"\t"<<scores.at(i)<<endl;
    }

    ///Sort Data
    for(int i=0;i<scores.size();i++)
    {
        for(int j=0;j<scores.size();j++)
        {
            if(scores.at(i)>scores.at(j))
            {
                swap(scores[i],scores[j]);
                swap(names[i],names[j]);
            }
        }
    }

    ///Print Data
    cout<<"Second Data :"<<endl;
    for(int i=0;i<names.size();i++)
    {
        cout<<names.at(i)<<"\t"<<scores.at(i)<<endl;
    }

    ///Save Data

    ofstream output;
    string file_name2 = "scores_sorted.txt";
    output.open(file_name2.c_str(),ios::out);

    for(int i=0;i<names.size();i++)
    {
        output<<names[i]<<" : "<<scores[i]<<endl;
    }
}

