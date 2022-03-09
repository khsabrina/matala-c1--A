#include <iostream>
#include <stdexcept>
using namespace std;
#include "mat.hpp"
#include <vector>

namespace ariel{
    string mat(int col, int row, char a , char b){
        if (col%2 == 0 || row%2 == 0){
            throw invalid_argument{"Mat size is always odd"};
        }
        if (col< 0 || row< 0){
            throw invalid_argument{"The size of the mat can't be negative"};
        }
        if (a == ' ' || b == ' ' || a == '\t' || b == '\t' || a == '\n'|| b == '\n' || a == '\r' || b == '\r'){
            throw invalid_argument{"Invalid input of char"};
        }
        string mat_str;
        vector<vector<char>> mat(row, vector<char>(col));
        int mat_num =0;
        if (col<row){
             mat_num = col / 2 +1;
        }
        else {mat_num = row /2 +1;}
        for (int i = 0; i< mat_num; i++){
            if (i % 2 == 0){
                for(int j = i; j<col-i;j++){
                    mat[i][j] = a;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][i] = a;
                }
                for(int j = i; j<col -i;j++){
                    mat[row-i-1][j] = a;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][col-i-1] = a;
                }
            }
            else{
                for(int j = i; j<col-i;j++){
                    mat[i][j] = b;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][i] = b;
                }
                for(int j = i; j<col-i;j++){
                    mat[row-i-1][j] = b;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][col-i-1] = b;
                }
            }
        }
        for (int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                mat_str += mat[i][j];
            }
            mat_str +=  "\n";
        }
        return mat_str;
    }

}

