#include<vector>
#include<iostream>
#include<fstream>
#include "object.cpp"

using namespace std;
class map : object
{
    //用于读取文件,要套trycatch
    vector<vector<int>> readin(string r)
    {
        vector<vector<int>> t;
        int a, b;
        ifstream rd(r);
        rd >> a >> b;
        vector<int> s;
        for (int i = 0; i <= b+1;i++)
        {
            s.push_back(0);
        }
        t.push_back(s);
        for (int i = 1; i <= a; i++)
        {
            vector<int> s;
            s.push_back(0);
            for (int j = 1; j <= b; j++)
            {
                int k;
                rd >> k;
                s.push_back(k);
            }
            s.push_back(0);
            t.push_back(s);
        }
        t.push_back(s);
        return t;
    
    }
//在上下左右各加了一行0防止溢出
    void store(string r,vector<vector<int>> t)
    {
        string k = ".wld";
        r += k;
        ofstream wt(r);
        wt << t.size() << " " << t[1].size() << "\n";
        for (int i = 1; i <= t.size();i++)
        {
            for (int j = 1; j <= t[1].size();j++)
            {
                wt << t[i][j] << " ";
            }
            wt << "\n";
        }
    }
};