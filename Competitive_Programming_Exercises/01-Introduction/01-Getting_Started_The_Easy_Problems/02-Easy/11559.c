#include <stdio.h>
#define max(a,b) ( a >= b ? a : b )
#define min(a,b) ( a <= b ? a : b )

int main(){
    int N, B, H, W, p, ans, cap, i, j, x;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4){
        ans = B + 1;
        for(i = 0; i < H; i++){
            scanf("%d", &p);
            cap = 0;
            for(j = 0, x; j < W; j++){
                scanf("%d",&x);
                cap = max(cap,x);
            }
            if(cap >= N) ans = min(ans, N * p);
        }
        if(ans == B + 1) printf("stay home\n");
        else printf("%d\n", ans);
    }
    return(0);
}
