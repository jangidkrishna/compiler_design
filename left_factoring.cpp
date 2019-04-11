#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs1, rhs2;
};


int main(){
    string temp, alpha, beta;
    cout << "Enter the production : ";
    getline(cin, temp);
    cout << "Input : " << temp << endl;
    lang input;
    int n = temp.length();
    int flag;
    for(int i=0;i<n;i++){
        if(temp[i]== '|' ){
            flag = i;
            cout << "Flag :" << flag <<endl;
        }
    }
    alpha.assign(temp, 3, flag-3);
    cout << "Alpha : " << alpha << endl;
    beta.assign(temp,flag+1,n-flag+1);
    cout << "Beta : " <<  beta << endl;
    return 0;
}