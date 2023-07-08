#include<bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    int row_num;
    int col_num;
    vector<vector<float>> storage;

    Matrix(int row, int col, vector<vector<float>> arr){
        
        row_num = row;
        col_num = col;

        storage = arr;
    }

};
