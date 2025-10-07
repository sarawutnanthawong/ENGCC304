#include <stdio.h>

int main(){
    int n = 0;
    printf("enter ur number");
    scanf("%d", &n);
    if (n % 2 != 0){
        for (int i = 1 ; i <= 0 ; i += 2){
            printf("%d\n", i );
        }
    } else{
        for (int i = n ; i >= 0 ; i -= 2){
            printf("%d\n",i );
        }
    }

    return 0;
}
