#include <iostream>

using namespace std;

int main()
{
    string name;
    int age, weight;
    
    while(true){
        cin >> name;
        cin >> age >> weight;
        
        if(name == "#") break;
        
        if(age > 17 || weight >= 80)
            cout << name << " Senior" << endl;
        else
            cout << name << " Junior" << endl;
    }

    return 0;
}
