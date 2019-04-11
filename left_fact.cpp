#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs[10];
};

string common(string a, string b){
    string result;
    for(int i=0;i<a.length();i++){
        if(a[i] == b[i] && a[i-1] == b[i-1]){
            result += a[i];
        }
    }
    return result;
}

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
            count++;
        }
    }
    input.rhs[count].assign(temp, pos+1, temp.length()-pos-1);
    input.lhs.assign(temp,0,1);

    for(int i=1; i<=count;i++){
        string z = common(input.rhs[i-1],input.rhs[i]);
        if(alpha.compare(z)!=0){
            alpha = z;
        }

    }
    cout << "Ans : " << endl;
    cout << input.lhs << "->" << alpha << input.lhs << "'" <<endl;
    cout << input.lhs << "'->" ;
    for(int i=0;i<count+1;i++){
        cout << input.rhs[i].substr(alpha.length(), input.rhs[i].length()) << "|";
    }
    cout << endl;

    return 0;
}