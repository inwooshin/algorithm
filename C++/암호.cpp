#include <iostream>

using namespace std;

int main(void){
    
    int rows, cols, count = 0;
    string input;
    
    cin >> cols >> input;
    
    rows = input.size() / cols;
    
    char** arr = new char*[rows]; //�좎뼵�섍퀬�� �섎뒗 �댁감�� 諛곗뿴�� �됱쓽 �� 留뚰겮 �숈쟻 �좊떦

    for(int i = 0; i < rows; i++) //媛곴컖�� �몃뜳�ㅼ뿉 �좎뼵�섍퀬�� �섎뒗 諛곗뿴�� �ш린留뚰겮�� 媛�瑜댄궎寃� ��.
        arr[i] = new char[cols];
    
    for(int i = 0 ; i < rows ; i++){
        if(i % 2 == 0){
            for(int j = 0 ; j < cols ; j++){
                arr[i][j] = input[count++];
            }
        }
        else{
            for(int j = cols - 1; j >= 0 ; j--){
                arr[i][j] = input[count++];
            }
        }
    }
    
    for(int i = 0; i < cols ; i++){
        for(int j = 0; j < rows ; j++){
            cout << arr[j][i];
        }
    }
    
    return 0;
}
