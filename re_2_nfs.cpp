#include<bits/stdc++.h>
using namespace std;

int main(){
    
    char table[10][10], re[10];
    int third_char=0, n, top=0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            table[i][j] = ' ';
        }
    }

    cout << "Enter RE : ";
    cin >> re;
    n = strlen(re);
    for (int i = 0; i < n; i++){
        switch (re[i]){
            case '|':
                table[top][top+1] = 'E';
                table[top+1][top+2] = re[i-1];
                table[top+2][top+5] = 'E';
                table[top+4][top+5] = 'E';
                table[top][top+3] = 'E';
                table[top+3][top+4] = re[i+1];
                top+=5;
                break;
                i++;
                third_char=1;
            case '*':
                table[top][top+1] = 'E';
                table[top][top+3] = 'E';
                table[top+1][top+2] = re[i-1];
                table[top+2][top+3] = 'E';
                table[top+2][top+1] = 'E';
                top+=3;
                break;
            case '.':
                table[top][top+1] = re[i-1];
                table[top+1][top+2] = 'E';
                table[top+2][top+3] = re[i+1];
                top+=3;
                break;
           
            /*default:{   
                    if (third_char == 0){                    
                    }
                }

                break;
            */
        }
    }
    cout << "\t";
    for (int i = 0; i < top+1; i++){
        cout << i << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < top+1; i++){
        cout << i << "\t" ;
        for (int j = 0; j < top+1; j++){
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}