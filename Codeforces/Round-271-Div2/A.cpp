// Implementation
// 1
// 21-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	string a = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string b;
	char ch;
	size_t posi;
	int aux;
	cin>>ch;
	cin>>b;
	aux = ch=='L' ? 1 : -1;
	for(int i=0;i<b.size();i++){
		posi = a.find(b[i]);
		b[i] = a[posi+aux];
	}
	cout<<b<<endl;
	return(0);
}
