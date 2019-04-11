#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs1, rhs2;
};

int main(){
    string temp, alpha, beta, adash;
    cout << "Enter the production : ";
    getline(cin, temp);
    cout << "Input : " << temp << endl;
    lang input;
    int n = temp.length();
    int flag;
    for(int i=0;i<n;i++){
        if(temp[i]== '|' ){
            flag = i;
        }
    }
    input.lhs.assign(temp,0,1);
    input.rhs1.assign(temp,2,flag-2);
    alpha.assign(temp, 3, flag-3);
    beta.assign(temp,flag+1,n-flag+1);
    input.rhs2.assign(beta);
    adash.assign(input.lhs);
    adash += "'";
    cout << "Ans:" << endl;
    cout << input.lhs << "->" << beta << adash << endl;
    cout << input.lhs << "->" << alpha << adash << "| E" << endl;
    return 0;
}