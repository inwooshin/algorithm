#include <iostream>

using namespace std;

int compare(string& input_msg, char in_ch, char start_ch){
    int is_valid = 0;
    
    for(int i = 0 ; i < input_msg.size() ; i++){
        if(input_msg[i] == in_ch){
            is_valid = 1;
            break;
        }
    }
    
    if(is_valid){
        for(int i = 0 ; i < input_msg.size() ; i++){
            if(start_ch <= input_msg[i] && input_msg[i] <= 'F' && input_msg[i] != 'E'){
                input_msg[i] = in_ch;
            }
        }
    }

    return is_valid;    
}

int main()
{
    string input_msg;
    
    cin >> input_msg;
    
    if(compare(input_msg, 'A', 'B')) ;
    else if(compare(input_msg, 'B', 'C')) ;
    else if(compare(input_msg, 'C', 'D')) ;
    else{
        for(int i = 0 ; i < input_msg.size() ; i++){
            cout << 'A';
        }
        
        return 0;
    }
    
    cout << input_msg;
    
    return 0;
}
