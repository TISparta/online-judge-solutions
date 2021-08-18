// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 19-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b,ans;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
		if(a[i] != b[i] )
			ans.push_back('1');
		else
			ans.push_back('0');
	cout<<ans<<endl;
	return(0);
}
