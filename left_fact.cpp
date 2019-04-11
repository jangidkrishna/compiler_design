#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs[10];
};

int main(){
    string temp, alpha, adash;
    cout << "Enter the production : ";
    getline(cin, temp);
    cout << "Input : " << temp << endl;
    lang input;
    int count=0,pos=2;
    for(int i=0; i < temp.length(); i++){
        if(temp[i] == '|'){
            input.rhs[count].assign(temp,pos+1,i-pos-1);
            pos = i;
            cout << "RHS : " << input.rhs[count] << endl;
            count++;
        }
    }
    input.rhs[count].assign(temp, pos+1, temp.length()-pos-1);
    cout << "RHS : " << input.rhs[count] << endl;
    input.lhs.assign(temp,0,1);
    cout << "LHS : " << input.lhs << endl;
}