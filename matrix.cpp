#include <iostream>
#include <fstream>
using namespace std;
const int n =3, m =3;

void printM(int matrix[n][m]){
    for(int i =0; i <n; i++){
        for(int j=0; j<n; j++){
            cout <<matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"\n";

}

void addM(int matrix1[n][m], int matrix2[n][m], int matrix3[n][m]){
    for (int  i =0; i < n; i++){
        for (int j =0; j < n; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout<<"add"<<"\n";
    printM(matrix3);
}

void multM(int matrix1[n][m], int matrix2[n][m], int matrix3[n][m]){
    for (int  i =0; i < n; i++){
        for (int j =0; j < m; j++){
            matrix3[i][j]=0;
            for (int k =0; k < n; k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            
        }
    }
    cout<<"mulitply"<<"\n";
    printM(matrix3);

}

void repM(int matrix1[n][m], int newVal, int row, int col){
    matrix1[row-1][col-1] = newVal;
    cout<<"replace"<<"\n";
    printM(matrix1);
}

void subM(int matrix1[n][m], int matrix2[n][m], int matrix3[n][m]){
    for (int  i =0; i < n; i++){
        for (int j =0; j < n; j++){
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    cout<<"subtract"<<"\n";
    printM(matrix3);
}

void maxVal(int matrix[n][m]){
    int temp[n*m];
    int count = 0;
    for (int  i =0; i < n; i++){
        for (int j =0; j < m; j++){
            temp[count] = matrix[i][j];
            count ++;
        }
    }
    int max;
    for (int x = 0; x < n*m; x++){
        if (x == 0){

            max = 0;
        }else{

            if(temp[x] > temp[max]){
                max = x;
            }
        }
    }
    cout<<"Max Value of Matrix is: "<< temp[max]<<"\n";
    cout<<"\n";
}

void transM(int matrix1[n][m]){
    int temp[n][m];
    for (int  i =0; i < n; i++){
        for (int j =0; j < n; j++){
            temp[i][j] = matrix1[i][j];
        }
    }
    for (int  i =0; i < n; i++){
        for (int j =0; j < n; j++){
            matrix1[i][j] = temp[j][i];
        }
    }
    
    cout<<"transpose"<<"\n";
    printM(matrix1);
}



int main(){
    int line = 0;
    int N;
    fstream input;
    input.open("matrix_input.txt",ios::in);
    input >> N;
    int matrix1[n][m];
    int matrix2[n][m];
    int matrix3[n][m];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            input >> matrix1[i][j];
        }
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            input >> matrix2[i][j];
        }
    }
    cout <<"Matrix1"<<"\n";
    printM(matrix1);
    cout <<"Matrix2"<<"\n";
    printM(matrix2);
    addM(matrix1,matrix2,matrix3);
    multM(matrix1,matrix2,matrix3);
    subM(matrix1,matrix2,matrix3);
    
    int replace;
    int row;
    int col;
    cout <<"Type the replacement number: ";
    cin>> replace;
    cout <<"Type the row: ";
    cin >> row;

    if (row > n || row < 1){
        cout<<"Row is invalid. Operation will be skipped"<<"\n";
    }else{
        cout <<"Type the column: ";
        cin >> col;
        

        if (col > n || col < 1){
            cout<<"Column is invalid. Operation will be skipped"<<"\n";
        }else{
            repM(matrix1,replace,row,col);
            cout<<"\n";
        }
    }

    maxVal(matrix1);
    transM(matrix1);

    





    input.close();
}