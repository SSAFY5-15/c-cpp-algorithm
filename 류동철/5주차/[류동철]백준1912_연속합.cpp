#include<cstdio>
#include<algorithm>
using namespace std;

int main(void){
    int n; int ans=-1e9, dp=-1e9;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int t; scanf("%d",&t);
        if(i==0) dp = max(t, dp);
        else dp = max(dp+t, t);
        ans = max(ans, dp);
    }

    printf("%d",ans);
    return 0;
}