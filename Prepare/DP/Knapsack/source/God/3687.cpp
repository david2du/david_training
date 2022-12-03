#include<stdio.h>
#include<bitset>
using namespace std;
const int maxn=2000000;
bitset<maxn> a;
int sum,n,ans,x;
int main(){
    scanf("%d",&n),a[0]=1;
    for(register int i=1;i<=n;i++){
        scanf("%d",&x);
        fprintf(stderr, "%d\n", x);
        a^=a<<x;
        sum+=x;
    }
    for(register int i=1;i<=sum;i++) if(a[i]) ans^=i;
    printf("%d",ans);
}
