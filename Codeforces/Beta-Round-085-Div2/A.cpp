// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 10-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	char a[105];
	char b[105];
	cin>>a;
	cin>>b;
	int tam;
	tam = strlen(a);
	for(int i=0;i<tam;i++)
		a[i] = tolower(a[i]);
	for(int i=0;i<tam;i++)
		b[i] = tolower(b[i]);
	for(int i=0;i<tam;i++){
		if(a[i]<b[i]){
			cout<<-1<<endl;
			return(0);
			}
		else if(a[i]>b[i]){
			cout<<1<<endl;
			return(0);
			}
	}
	cout<<0<<endl;
	return(0);
}
