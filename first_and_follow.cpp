#include<bits/stdc++.h>
using namespace std;

struct lang{
    string lhs, rhs[5], first, follow;
    int no = 0;
};

int main(){

    string temp,temp_lhs;
    cout << "enter no of productions" << endl;
    int n;
    cin >> n;
    lang prod[10];
    for(int j=0;j<n;j++){
        cout << "Enter the production : ";
        getline(cin, temp);
        temp_lhs.assign(temp,0,1);
        for(int i=0;i<n;i++){
            if(prod[i].lhs.compare(temp_lhs)==0){
                prod[i].rhs[prod[i].no].assign(temp,2,temp.length()-2);
                prod[i].no++;
            } else {
                prod[j].lhs.assign(temp,0,1);
                prod[j].rhs[prod[j].no].assign(temp,2,temp.length()-2);
                prod[j].no++;
            }
        }

    }
    for (int i = 0; i < n; i++){
        for (int z = 0; z < prod[i].no; z++){
            cout << prod[i].lhs << " =>  " << prod[i].rhs[z] << endl;
        }
        
    }
    
    return 0;

}
