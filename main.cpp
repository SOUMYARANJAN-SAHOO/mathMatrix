#include<bits/stdc++.h>
#include<cmath>
#include "Matrix.h"
#include "Single_M_Operations.h"
#include "Multi_M_Operations.h"
using namespace std;

Matrix* input(){
    int row,col;
    cout<<"Enter the number of rows::";
    cin>>row;
    cout<<"Enter the number of columns::";
    cin>>col;

    vector<vector<float>> arr;

    cout<<"Enter the matrix::"<<endl;

    for(int i =0;i<row;i++){
        vector<float> row;
        for(int j=0;j<col;j++){
            int element;
            cin>>element;
            row.push_back(element);
        }
        arr.push_back(row);
    }


    // for(auto i: arr){
    //     for(auto j: i ){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }

    Matrix* A = new Matrix(row, col, arr);

    return A;
}

void output(Matrix* arr){
    for (int i = 0; i < arr->row_num; i++) {
        for (int j = 0; j < arr->col_num; j++) {
            cout << arr->storage[i][j] << " ";
        }
        cout << endl;
    } 
}

int menu(){
    cout<<"====================MATH MATRIX OPERATIOR===================="<<endl;
    cout<<"==================MADE BY SOUMYARANJAN SAHOO================="<<endl;
    cout<<"Please select the required operation::"<<endl;
    cout<<"::SINGLE MATRIX OPPERATIONS::"<<endl;
    cout<<"1. Transpose of the Matrix"<<endl;
    cout<<"2. Multiply with Scalar"<<endl;
    cout<<"3. Determinant of the Matrix"<<endl;
    cout<<"4. Rank of the Matrix"<<endl;
    cout<<"5. Adjoint of the Matrix"<<endl;
    cout<<"6. Inverse of the Matrix"<<endl;
    cout<<"::DOUBLE MATRIX OPPERATIONS::"<<endl;
    cout<<"7. Addtion"<<endl;
    cout<<"8. Substraction"<<endl;
    cout<<"9. Multiplication"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Enter appropriate choice::";
    int choice;
    cin>>choice;
    cout<<"============================================================="<<endl;
    return choice;
}


int main(){
    while (true){
        int choice = menu();
        if(choice == 0){
            cout<<"==========================Thank You=========================="<<endl;
            cout<<"============================================================="<<endl;
            break;}
        switch (choice)
        {
            case 1:{
                Matrix* A = input();
                Matrix* traspose = Single_M_Operations::Transpose(A);
                cout<<"The Transpose Matrix is::"<<endl;
                output(traspose);
                break;
            }case 2:{
                Matrix* A = input();
                float scalar;
                cout<<"Enter the scalar::";
                cin>>scalar;
                Matrix* result = Single_M_Operations::Scalar_Multiplication(scalar, A);
                cout<<"The resultant matrix when we multiply with "<<scalar<<" is::"<<endl;
                output(result);
                break;
            }case 3:{
                Matrix* A = input();
                if(A->row_num == A->col_num){
                    int determinant = Single_M_Operations::Determinant(A,A->row_num);
                    cout<<"The determinant of the matrix is::"<<determinant<<endl;
                }else{
                    cout<<":: Can't find the determinant of a matrix which is not square matrix ::";
                }
                break;
            }case 4:{
                Matrix* A = input();
                int rank = Single_M_Operations::Rank(A);
                cout<<"The rank of the given matrix is ::"<<rank<<endl;
                break;
            }case 5:{
                Matrix* A = input();
                Matrix* Adjoint = Single_M_Operations::adjoint(A);
                cout<<"The Adjoint Matrix is::"<<endl;
                output(Adjoint);
                break;
            }case 6:{
                Matrix* A = input();
                if(A->row_num == A->col_num){
                    int determinant = Single_M_Operations::Determinant(A,A->row_num);
                    if(determinant != 0){
                        Matrix* Inverse = Single_M_Operations::Inverse(A,determinant);
                        cout<<"The Inerse Matrix is::"<<endl;
                        output(Inverse);
                    }else{
                        cout<<":: Can't find the inverse of a singular matrix ::";
                    }
                }else{
                    cout<<":: Can't find the inverse of a matrix which is not square matrix ::";
                }
                break;
            }case 7:{
                cout<<"Enter the details of first matrix::";
                Matrix* A = input();
                cout<<"Enter the details of secound matrix::";
                Matrix* B = input();

                if(A->col_num == B->col_num && A->row_num == B->row_num){
                    Matrix* result = Multi_M_Operations::Addition(A,B);
                    cout<<"The resultant matrix by the addition of the matrices is:: "<<endl;
                    output(result);
                }else{
                    cout<<":: Can't add two matrices when the number of rows and column of "<<endl;
                    cout<<"first matrix is not equal to the number of rows and column of the second matrix ::"<<endl;
                }
                break;
            }case 8:{
                cout<<"Enter the details of first matrix::";
                Matrix* A = input();
                cout<<"Enter the details of secound matrix::";
                Matrix* B = input();

                if(A->col_num == B->col_num && A->row_num == B->row_num){
                    Matrix* result = Multi_M_Operations::Substraction(A,B);
                    cout<<"The resultant matrix by the sum of the matrices is:: "<<endl;
                    output(result);
                }else{
                    cout<<":: Can't substract two matrices when the number of rows and column of "<<endl;
                    cout<<"first matrix is not equal to the number of rows and column of the second matrix ::"<<endl;
                }
                break;
            }case 9:{
                cout<<"Enter the details of first matrix::";
                Matrix* A = input();
                cout<<"Enter the details of secound matrix::";
                Matrix* B = input();

                if(A->col_num == B->row_num){
                    Matrix* result = Multi_M_Operations::Multiplication(A,B);
                    cout<<"The resultant matrix by the product of the matrices is:: "<<endl;
                    output(result);
                }else{
                    cout<<":: Can't multiply two matrices when the number of column of "<<endl;
                    cout<<"first matrix is not equal to the number of rows of the second matrix ::"<<endl;
                }
                break;
            }default:{
                cout<<":: Enter Valid Input ::";
            }
        }
    }
}