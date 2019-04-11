#include<bits/stdc++.h>
using namespace std;
void follow(char c);
int m=0,n;
char prod[10][10],f[10];
void first(char c){
    if(!isupper(c)){
        f[m++] = c;
    }
    for(int k=0;k<n;k++){
        if(prod[k][0] == c){
            if(prod[k][2] == '$'){
                follow(prod[k][0]);
            }else if (prod[k][2]){
                f[m++] = prod[k][2];
            }else{
                first(prod[k][2]);
            }

        }
    }
}

void follow(char c){
    if(prod[0][0]==c){
        f[m++] = '$';
    }
    for(int i=0;i<n;i++){
        for(int j=2; j<strlen(prod[i]);j++){
            if (prod[i][j] == c){
                if (prod[i][j+1] != '\0'){
                    first(prod[i][j+1]);
                }
                if(prod[i][j+1]== '\0' && c!=prod[i][0]){
                    follow(prod[i][0]);
                }
                
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
        first(find);
        cout  << "First : " << f << endl;
        strcpy(f,"");
        m=0;
        follow(find);
        cout << "Follow : " << f << endl;

    }while(z==1);

    return 0;
}
