

class Single_M_Operations
{
public:
    // Function to calculate the transpose of a matrix
    static Matrix* Transpose(Matrix* matrix){
        int row = matrix->row_num;
        int col = matrix->col_num;
        vector<vector<float>> trans;

        // Intialising trans with all zeroes
        for(int i =0;i<row;i++){
            vector<float> row;
            for(int j=0;j<col;j++){
                row.push_back(0);
            }
            trans.push_back(row);
        }
    

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                trans[i][j] = matrix->storage[j][i];
            }
        }
        Matrix* transpose = new Matrix(row, col, trans);
        return transpose;
    }

    // Function to calculate the multiplication of a scalar with a matrix
    static Matrix* Scalar_Multiplication(float scalar,Matrix* matrix){
        int row = matrix->row_num;
        int col = matrix->col_num;
        vector<vector<float>> multi;

        // Intialising multi with all zeroes
        for(int i =0;i<row;i++){
            vector<float> row;
            for(int j=0;j<col;j++){
                row.push_back(0);
            }
            multi.push_back(row);
        }

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                multi[i][j] = matrix->storage[i][j] * scalar;
            }
        }
        Matrix* scalarMulti = new Matrix(row, col, multi);
        return scalarMulti;
    }


    // Function to calculate the determinant of a matrix
    static double Determinant(Matrix* matrix, int n) {
        if (n == 1) {
            return matrix->storage[0][0];
        } else if (n == 2) {
            return matrix->storage[0][0] * matrix->storage[1][1] - matrix->storage[0][1] * matrix->storage[1][0];
        } else {
            double det = 0;
            //Iterating through the col
            for (int col = 0; col < n; col++) {

                //initializing the sub matrix
                vector<vector<float>> sub_matrix;
                for(int sub_row=1;sub_row<n;sub_row++){
                    vector<float> row_vec;
                    for(int sub_col=0;sub_col<n;sub_col++ ){
                        if(sub_col!=col){
                            row_vec.push_back(matrix->storage[sub_row][sub_col]);
                        }
                    }
                    sub_matrix.push_back(row_vec);
                }

                Matrix* sub_Matrix = new Matrix(n-1,n-1,sub_matrix);
                
                //adding the result to the det variable
                det += pow(-1, (col+2)) * matrix->storage[0][col] * Determinant(sub_Matrix, n-1);

                delete sub_Matrix;
            }
            return det;
        }
    }

    // Function to calculate the rank of a matrix
    static int Rank(Matrix* A) {
        int row = A->row_num;
        int col = A->col_num;

        double EPS = 1e-9;

        int rank = 0;
        vector<bool> row_selected(row, false);

        for (int i = 0; i < col; i++) {
            int j;
            for (j = 0; j < row; j++) {
                if (!row_selected[j] && abs(A->storage[j][i]) > EPS) {
                    break;
                }
            }
            if (j != row) {
                rank++;
                row_selected[j] = true;
                for (int p = i + 1; p < col; p++) {
                    A->storage[j][p] /= A->storage[j][i];
                }
                for (int k = 0; k < row; k++) {
                    if (k != j && abs(A->storage[k][i]) > EPS) {
                        for (int p = i + 1; p < col; p++) {
                            A->storage[k][p] -= A->storage[j][p] * A->storage[k][i];
                        }
                    }
                }
            }
        }

        return rank;
    }

    // Function to calculate the adjoint of a matrix
    static Matrix* adjoint(Matrix* A) {
        int row = A->row_num;
        vector<vector<float>> adj(row, vector<float>(row, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                // Calculate the cofactor of A[i][j]
                vector<vector<float>> cofactor(row - 1, vector<float>(row - 1));
                int p = 0, q = 0;
                for (int k = 0; k < row; k++) {
                    if (k != i) {
                        q = 0;
                        for (int l = 0; l < row; l++) {
                            if (l != j) {
                                cofactor[p][q] = A->storage[k][l];
                                q++;
                            }
                        }
                        p++;
                    }
                }

                // Calculate the sign of the cofactor
                int sign = ((i + j) % 2 == 0) ? 1 : -1;

                // Calculate the determinant of the cofactor
                Matrix* Cofactor = new Matrix(A->row_num-1,A->col_num-1,cofactor);
                double det = Determinant(Cofactor,A->row_num-1);
                delete Cofactor;

                // Calculate the (i,j)th element of the adjoint
                adj[j][i] = sign * det;
            }
        }
        Matrix* Adjoint = new Matrix(A->row_num,A->col_num,adj);
        return Adjoint;
    }

    // Function to calculate the inverse of a matrix
    static Matrix* Inverse(Matrix* A, int det) {
        int row = A->row_num;
        int col = A->col_num;

        Matrix* inverse = adjoint(A);

        for (int i = 0; i < row; i++)
        {
            for(int j=0;j<col;j++){
                A->storage[i][j] /= det;
            }
        }

        return inverse;
        
    }

};
