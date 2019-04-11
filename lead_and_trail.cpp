#include<bits/stdc++.h>
using namespace std;

int m=0,n;
char prod[10][10],f[10];

void lead(char c){
    if(!isupper(c)){
        f[m++] = c;
    }

    for(int k=0;k<n;k++){
        if(prod[k][0] == c){
            if (prod[k][2] == c && !isupper(prod[k][3])){
                f[m++] = prod[k][3];
            }else if (prod[k][2] != c){
                lead(prod[k][2]);
            } else {
                cout << "Error";
            }
        }
    }
}

void trail(char c){

    for(int k=0;k<n;k++){
        int len = strlen(prod[k]);
        
        if(prod[k][0] == c){
            if (!isupper(prod[k][len-1])){
                f[m++] = prod[k][len-1];
            }else if (isupper(prod[k][len-1])){
                if( !isupper(prod[k][len-2]) && prod[k][len-2] != '='){
                    f[m++] = prod[k][len-2];
                }
                trail(prod[k][len-1]);
            } else {
                cout << "Error";
            }
        }
    }
}

int main(){

    cout << "enter no of productions" << endl;
    int flag=0,z;
    char ch,find;
    cin >> n;
    cout << "enter productions" << endl;
    for(int i=0; i<n ;i++){
        scanf("%s%c",prod[i],&ch);
    }

    do{
        m=0;
        cout << "enter the element" << endl;
        cin >> find;
        lead(find);
        cout  << "First : " << f << endl;
        strcpy(f,"");
        m=0;
        trail(find);
        cout << "Follow : " << f << endl;

    }while(z==1);

    return 0;
}
