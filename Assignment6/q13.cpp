#include <bits/stdc++.h>
using namespace std;

int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];
void check(){
	strcpy(ac,"REDUCE TO S -> ");
	for(z = 0; z < c; z++){
		if(stk[z] == 'd'){
			printf("%sd", ac);
			stk[z] = 'S';
			stk[z + 1] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
		}
	}
	for(z = 0; z < c - 2; z++){
		if(stk[z] == 'S' && stk[z + 1] == '+' && stk[z + 2] == 'S'){
			printf("%sS+S", ac);
			stk[z] = 'S';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
		
	}
		
	for(z = 0; z < c - 2; z++){
		if(stk[z] == 'S' && stk[z + 1] == '*' && stk[z + 2] == 'S'){
			printf("%sS*S", ac);
			stk[z]='S';
			stk[z + 1]='\0';
			stk[z + 2]='\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
	}
	return ; 
}
int main(){
	printf("GRAMMAR:\n1. S->S+S \n2. S->S*S \n3. S->d\n");	
	cout << "\nEnter the string: ";
	cin >> a;
	c=strlen(a);
	cout<<"------------------------------------" << endl;
	cout<<"Shift reduce parsing for "<<a<<endl;
	cout<<"------------------------------------" << endl;
	strcpy(act,"SHIFT");
	printf("\nstack \t input \t action");
	printf("\n$\t%s$\t", a);
	
	for(i = 0; j < c; i++, j++){
		printf("%s", act);
		stk[i] = a[j];	
		stk[i + 1] = '\0';
		a[j]=' ';
		printf("\n$%s\t%s$\t", stk, a);
		check();
	}
	check();
	if(stk[0] == 'S' && stk[1] == '\0')printf("Accept\n");
	else printf("Reject\n");
	return 0;
}