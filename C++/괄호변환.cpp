#include <string>
#include <stack>

using namespace std;


bool check(string p){
    stack <char> count;
    
    for(int i = 0 ; i < p.size(); i++){
        switch(p[i]){
            case '(' :
                count.push(p[i]);
                break;
            case ')' :
                if(count.empty()) return false;
                count.pop();
                break;
        }
    }
    
    if(count.empty()) return true;
    else return false;
}

string split(string p){
    if(check(p)) return p;
    string u = "", v = "";
    int open = 0, close = 0, i;
    for(i = 0 ; i < p.size() ; i++){
        u += p[i];
        switch(p[i]){
            case '(' :
                open++;
                break;
            case ')' :
                close++;
                break;
        }
        if(open != 0 && open == close){i++; break;}
    }
    for(; i < p.size() ; i++){
        v += p[i];
    }
    
    if(check(u)){
        u += split(v);
    }
    else{
        string newstr = "";
        u = u.substr(1, u.length() - 2);
        for(int j = 0 ; j < u.length() ; j++){
            if(u[j] == '(') u[j] = ')';
            else u[j] = '(';
        }
        newstr = '(' + split(v) + ')' + u;
        return newstr;
    }
    
    return u;
}

string solution(string p) {
    
    return split(p);
}
