#include<iostream>
#include<stdio.h>  
#include<string.h>
using namespace std;  
int main()  
  {  
       char gram[20];  
       int i,j=0,k,l=0,pos=3,pos2=-1,temp2=0;  
       printf("Enter Production : ");  
       scanf("%s",gram);
       int count=0;
       char fp[30],sp[30];
       for(i=0;gram[i]!='\0';i++)
       {
       	if(gram[i]=='|')
       	   count++;
	   }
	   fp[0]=gram[0];
	   fp[1]='\0';
	   strcat(fp,"->");
	   char parts[count+1][20];
	   while(l<count+1)
	   {
	      for(i=pos,k=0;gram[i]!='|'&&gram[i]!='\0';i++,k++)  
            {
			parts[j][k]=gram[i];
			}
		  parts[j][k]='\0';
		  j++;
		  pos=i+1;
		  l++;
       }
       for(i=0;i<count;i++)
        {
        	for(j=0;j<strlen(parts[i])||j<strlen(parts[i+1]);j++)
        	{
        		if(parts[i][j]==parts[i+1][j])
        		{
        			pos2=j+1;
				}
				else
				{
					break;
				}
			}
		}
		if(pos2==-1)
			cout<<"Not in left factorization form";
		else
		{
		for(i=0;i<pos2;i++)
		{
			fp[i+3]=gram[i+3];
		}
		char newgram[25];
		newgram[0]=gram[0];
		newgram[1]='\0';
		strcat(newgram,"'");
		strcat(fp,newgram);
		strcat(sp,newgram);
		strcat(sp,"->");
		k=4;
		for(i=0;i<count+1;i++)
		{
			for(j=pos2;j<strlen(parts[i]);j++)
			{
				sp[k]=parts[i][j];
				k++;
			}
			sp[k]='|';
			k++;
		}
		sp[k-1]='\0';
		cout<<fp<<endl;
		cout<<sp<<endl;
	}
	   return 0;
  }


/*#include<bits/stdc++.h>
using namespace std;

int main(){
    char temp[30],lhs,alpha[10];
    cout << "Enter the production : ";
    cin >> temp;
    cout << "Input : " << temp << endl;
    int count=0,pos=2, pos1 =-1;
    for(int i=0; i < strlen(temp); i++){
        if(temp[i] == '|'){
            count++;
        }
    }
    lhs = temp[0];
    char parts[count+1][10];
    for(int i =0; i<count+1; i++){
        for( int j =pos; gram[i]!='|')
    }


    return 0;
}