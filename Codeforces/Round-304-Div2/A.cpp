// Tags: Math
// Difficulty: 1.0
// Priority: 3
// Date: 23-03-2016

#include <bits/stdc++.h>

using namespace std;

int k,n,w,ans;

int main(){
	cin>>k>>n>>w;
	ans = k*(w)*(w+1)/2;
	ans < n ? cout<<0<<endl : cout<<ans-n<<endl;
	return(0);
}
