#include<bits/stdc++.h>
using namespace std;

bool isKeyword(char buffer[]){
    char keywords[2][10]={"main","break"};
    for(int i=0;i<2;i++){
        if(strcmp(keywords[i],buffer)==0){
            return true;
        }
    }
    return false;
}

int main(){
    char operators[] = "+-/*";
    char special[] = "$#@!";
    ifstream fin;
    char ch,buffer[15];
    fin.open("a.txt");
    int j=0;

    while(fin){
        ch = fin.get();
        for(int i=0;i<4;i++){
            if(ch == operators[i]){
                cout << ch << "is a operator" << endl;
                break;
            }
            if(ch == special[i]){
                cout << ch << "is a special character" << endl;
                break;
            }
        }
        if(isalnum(ch)){
            buffer[j++] = ch;
        } else if ((ch == ' ')||(ch == '\0')&&(j!=0)) {
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer)){
                cout << buffer << " is a keyword" << endl;
            } else {
                cout << buffer << " is a identifier" << endl;
            }
        }
    }
    fin.close();
    return 0;
}