// Implementation
// 1
// 12-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, l, m, n, d;
	cin>>k>>l>>m>>n>>d;
	int ans = 0;
	for(int i = 1;i <= d;i++)
		if( !(i%k) || !(i%l) || !(i%m) || !(i%n) )
			ans++;
	cout<<ans<<endl;
	return(0);
}
