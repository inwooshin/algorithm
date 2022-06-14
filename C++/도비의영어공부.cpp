#include <iostream>

using namespace std;

int main()
{
    char alpha;
    string sentence;
    
    while(cin >> alpha){
        if(alpha == '#') break;
        
        getline(cin, sentence);
        
        alpha = tolower(alpha);
        int count = 0;
        
        for(int i = 0 ; i < sentence.size() ; i++){
            if(alpha == tolower(sentence[i])) count++;
        }
        
        cout << alpha << " " << count << endl;
    }
    

    return 0;
}
