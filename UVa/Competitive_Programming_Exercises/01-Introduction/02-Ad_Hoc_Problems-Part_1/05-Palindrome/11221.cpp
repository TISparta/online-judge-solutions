#include <bits/stdc++.h>

using namespace std;

int ch, tc, t, tmp, k;
string a;
vector <bool> p(10001);
bool ind;

void perfect_square(){
	for(int i = 1; i <= 100; i++)
		p[i * i] = true;
	return;	
}

int main(){
	perfect_square();
	scanf("%d\n", &tc);
	while(tc--){
		printf("Case #%d:\n", ++t);
		while( ( ch = getchar() ) != '\n' )
			if(isalpha(ch))
				a += ch;
		if(not p[a.size()])
			printf("No magic :(\n");
		else{
			tmp = sqrt(a.size());
			ind = true;
			k = a.size();
			for(int i = 0; i < a.size() / 2; i++)
				if(a[i] != a[--k])
					ind = false;
			k = a.size() - 1;
			for(int i = 0; i < tmp; i++, k--)
				for(int j = 0; j < tmp; j++)
					if(a[i + j * tmp] != a[k - j * tmp])
						ind = false;
			if(ind)
				printf("%d\n", tmp);
			else
				printf("No magic :(\n");
		}	
		a.clear();
	}
	return(0);
}
