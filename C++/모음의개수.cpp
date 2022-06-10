#include <iostream>

using namespace std;

int main(void){

    string in;

    

    while(getline(cin, in)){

        int count = 0;

        

        if (in == "#") break;

        

        for(int i = 0 ; i < in.size() ; i++){

            if(in[i] == 'a' || in[i] == 'A') count++;

            if(in[i] == 'e' || in[i] == 'E') count++;

            if(in[i] == 'i' || in[i] == 'I') count++;

            if(in[i] == 'o' || in[i] == 'O') count++;

            if(in[i] == 'u' || in[i] == 'U') count++;

        }

        

        cout << count << endl;

    }

    

    return 0;

}
