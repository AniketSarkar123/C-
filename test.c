#include<stdio.h>

int f(int *x){
    *x+=5;
    return 2;
}


int main() {
    int x=3;
    if((x==2) && (f(&x)))
        x++;
    x=x+f(&x);
    printf("%d\n",x);
}
