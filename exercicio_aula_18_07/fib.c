#include <stdio.h>

int f(int);

int f(int n){
    int x;
    if(n == 0){
        return 1;
    }
    x = f(n-1);
    return x + 1/x;
    //return f(n-1) + 1/f(n-1);
}

int main(){
    f(20);
}