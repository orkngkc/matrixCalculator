#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayOP(){
    
    cout<<"Pick a choice from the list:"<<endl;
    cout<<"1- Addition Operation"<<endl;
    cout<<"2- Multiplication Operation"<<endl;
    cout<<"3- Power Operation"<<endl;
    cout<<"4- Transpose Operation"<<endl;
    cout<<"5- Exit"<<endl;
    
}


void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}

int input(){
    
    int op;
    
    cin>>op;
    return op;
    
}



vector<vector<int>> matrixIn(int row, int col){
    
    vector<vector<int>> matrix(row,vector<int>(col));
    
    for (int i = 0; i < row; i++) {
        cout<<"Enter the numbers for row #"<<i+1<<": ";
        for (int j = 0; j < col; j++) {
                
                cin >> matrix[i][j];
            }
        }
    
    return matrix;
}

void matrixAddition(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    if (rows == matrix2.size() || cols == matrix2[0].size()) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printMatrix(result);
    }
   
    
}

vector<vector<int>> matrixMultiplication(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();
    vector<vector<int>> result(rows1, vector<int>(cols2));
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return(result);
}

void matrixTranspose(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows, 0)); // Initialize result matrix with default value of 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Swap row and column indices
        }
    }
    printMatrix(result);
}





int main(){
    int a,c;
    int b,d;
    int choice = 0;
    
    while(choice != 5){
        
        displayOP();
        cout<<"Choice: ";
        choice = input();
        cout<<endl;
        if (choice == 1){
            
            cout<<"Please enter the dimensions of the first matrix: ";
            cin>>a>>b;
            cout<<"Please enter the dimensions of the second matrix: ";
            cin>>c>>d;
            if (a==c&&b==d){
                cout<<"The two matrices have the same dimensions. Addition can be performed."<<endl<<endl;;
                cout<<"Please enter the numbers for the first matrix."<<endl;
                vector<vector<int>>matrix1 = matrixIn(a, b);
                cout<<"The first matrix is: "<<endl;
                printMatrix(matrix1);
                cout<<endl;
                cout<<"Please enter the numbers for the second matrix."<<endl;
                vector<vector<int>>matrix2= matrixIn(c, d);
                cout<<"The second matrix is: "<<endl;
                printMatrix(matrix2);
                cout<<endl;
                cout<<"Result of the Sum Operation: "<<endl;
                matrixAddition(matrix1, matrix2);
                cout<<endl;
            }else{
                cout<<"The two matrices do not have the same dimensions. Addition cannot be performed."<<endl;
            }
            
        }
        if (choice == 2){
            
            cout<<"Please enter the dimensions of the first matrix: ";
            cin>>a>>b;
            cout<<"Please enter the dimensions of the second matrix: ";
            cin>>c>>d;
            
            if (b==c){
                cout<<"The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed."<<endl;
                
                cout<<"Please enter the numbers for the first matrix."<<endl;
                vector<vector<int>>matrix1 = matrixIn(a, b);
                cout<<"The first matrix is: "<<endl;
                printMatrix(matrix1);
                cout<<endl;
                cout<<"Please enter the numbers for the second matrix."<<endl;
                vector<vector<int>>matrix2= matrixIn(c, d);
                cout<<"The second matrix is: "<<endl;;
                printMatrix(matrix2);
                cout<<endl;
                cout<<"Result of the Multiplication Operation: "<<endl;
                vector<vector<int>> result = matrixMultiplication(matrix1, matrix2);
                printMatrix(result);
                cout<<endl;
            }else{
                cout<<"The number of columns in the first matrix must be equal to the number of rows in the second matrix." <<endl<<"Multiplication cannot be performed."<<endl;
            }
            
        }
        
        if (choice == 4){
            
            cout<<"Please enter the dimensions of the matrix: ";
            cin>>a>>b;
            cout<<"Please enter the numbers for the matrix."<<endl;
            vector<vector<int>>matrix1 = matrixIn(a, b);
            cout<<"The matrix is: "<<endl;
            printMatrix(matrix1);
            cout<<endl;
            cout<<"Result of the Transpose Operation: "<<endl;
            matrixTranspose(matrix1);
            cout<<endl;
            
        }
        
        if (choice == 3){
            
           
                
                int power;
                cout<<"Please enter the dimensions of the matrix: ";
                cin>>a>>b;
                
            if (a==b){
                cout<<"The matrix has the same number of rows as columns. Power can be performed."<<endl<<endl;
                cout<<"Please enter the numbers for the matrix."<<endl;
                vector<vector<int>>matrix1 = matrixIn(a, b);
                cout<<"The matrix is: "<<endl;
                printMatrix(matrix1);
                cout<<endl;
                cout<<"Please enter the power: ";
                cin>>power;
                cout<<"Result of the Power Operation: "<<endl;
                vector<vector<int>>result;
                
                result = matrix1;
                for (int i = 0; i<power-1;i++){
                    vector<vector<int>>temp(a, vector<int>(b, 0));
                    temp = matrixMultiplication(result, matrix1);
                    result = temp;
                    
                    
                }
                printMatrix(result);
                cout<<endl;
                
            }else{
                
                cout<<"The matrix does not have the same number of rows as columns. ";
                cout<<"Power cannot be performed."<<endl<<endl;
                
            }
            
        }
    }
    
    
   
    return 0;
    
}
