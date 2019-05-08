#include<bits/stdc++.h>
using namespace std;

struct grammer{
    char p[10], prod[10];
}g[10];

int main(){
    int np, stack_pos=0, i=0, f, tspos;
    char temp[10], input[10], sc, stack[10];
    cout << "Enter no of prod : ";
    cin >> np;
    cout << "\nEnter prod : ";
    for (int i = 0; i < np; i++){
        cin >> temp;
        strncpy(g[i].p, temp, 1);
        strcpy(g[i].prod, &temp[3]);
    }
    cout << "\nEnter input : ";
    cin >> input;
    i=0;
    sc = input[i];
    stack[stack_pos] = sc;
    int lip = strlen(input);
    i++;
    stack_pos++;
    do{
        int r=1;
        while (r!=0){
            cout << endl;
            for (int z = 0; z < stack_pos; z++){
                cout << stack[z];
            }
            cout << "\t";
            for (int z = i; z < lip; z++){
                cout << input[z];
            }
            
            if (r==2){
                cout << "\tReduced";
            } else {
                cout << "\tShifted";
            }
            r=0;

            for (int k = 0; k < stack_pos; k++){
                f=0;
                for (int l = 0; l < 10; l++){
                    temp[l] = '\0';
                }

                tspos = 0;

                for (int l = k; l < stack_pos; l++){
                    temp[tspos] = stack[l];
                    tspos++;
                }

                for(int m=0; m < np; m++){
                    int cr = strcmp(temp, g[m].prod);
                    if (cr == 0){
                        for (int l = k; l < 10; l++){
                            stack[l]='\0';
                            stack_pos--;
                        }

                        stack_pos = k;
                        strcat(stack, g[m].p);
                        stack_pos++;
                        r=2;
                    }
                }
            }
        }
        sc = input[i];
        stack[stack_pos]=sc;
        i++;
        stack_pos++;
    } while (strlen(stack)!=1 && stack_pos != lip);

    if(strlen(stack)==1) {
        cout<<"\n String Accepted\n";
    } else {
    	cout<<"\n String Rejected\n";
	}
    
    return 0;
}