
class Multi_M_Operations
{
public:
    // Function to calculate the addition of two matrices
    static Matrix* Addition(Matrix* A, Matrix* B){
        
        //initialising the row and col numbers
        int row = A->row_num;
        int col = B->col_num;

        //initialising the result matrix with addition of matrix A and B
        vector<vector<float>> result;
        for(int result_row=0;result_row<row;result_row++){
            vector<float> temp_row;
            for(int result_col=0;result_col<col;result_col++){
                temp_row.push_back(A->storage[result_row][result_col] + B->storage[result_row][result_col]);
            }
            result.push_back(temp_row);
        }

        //Returning the result in a matrix reference
        Matrix* Result = new Matrix(row,col,result);

        return Result;
    }


    // Function to calculate the deference of two matrices
    static Matrix* Substraction(Matrix* A, Matrix* B){

        //initialising the row and col numbers
        int row = A->row_num;
        int col = B->col_num;

        //initialising the result matrix with substraction of matrix A and B
        vector<vector<float>> result;
        for(int result_row=0;result_row<row;result_row++){
            vector<float> temp_row;
            for(int result_col=0;result_col<col;result_col++){
                temp_row.push_back(A->storage[result_row][result_col] - B->storage[result_row][result_col]);
            }
            result.push_back(temp_row);
        }

        //Returning the result in a matrix reference
        Matrix* Result = new Matrix(row,col,result);

        return Result;
    }


    // Function to calculate the multiplication of two matrices
    static Matrix* Multiplication(Matrix* A, Matrix* B){


        //initialising the row and col numbers
        int n = A->row_num;
        int m = B->row_num;
        int p = B->col_num;

        //initialising the result matrix with all 0
        vector<vector<float>> c;
        for(int i=0;i<n;i++){
            vector<float> temp_row;
            for(int j=0;j<p;j++){
                temp_row.push_back(0);
            }
            c.push_back(temp_row);
        }

        //looping for the multiplication
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    c[i][j] += A->storage[i][k] * B->storage[k][j];
                }
            }
        }

        //Returning the result in a matrix reference
        Matrix* C = new Matrix(n,p,c);

        return C;
    }   

};
