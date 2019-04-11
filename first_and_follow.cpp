#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs[5], first, follow;
    int no;
};

int main(){

    string temp,temp_lhs;
    cout << "enter no of productions" << endl;
    int n,flag=0;
    cin >> n;
    lang prod[10];
    getline(cin ,temp);
    for(int i=0;i<n;i++){
        cout << "Enter the production : "<< endl;
        getline(cin ,temp);
        temp_lhs.assign(temp,0,1);
        cout << "TEmp lhs : " << temp_lhs<< endl;
        for(int j=0;j<n;j++){
            cout << i;
            if(prod[j].lhs.compare(temp_lhs)==0){
                flag = j;
                cout << "Flag :" <<flag << endl;
            }
        } 
        cout <<endl;
        if(flag == i){
            prod[flag].rhs[prod[flag].no].assign(temp,2,temp.length()-2);
            prod[flag].no++;
        }else{
            prod[i].lhs.assign(temp,0,1);
            prod[i].rhs[0].assign(temp,2,temp.length()-2);
            prod[i].no = 1;
        }
            
    }

    /*for(int i=0;i<n;i++){
        cout << prod[i].no ;
    }*/
    cout << prod[0].lhs.compare(prod[1].lhs);

    return 0;

}
