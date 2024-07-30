#include <stdio.h>
int fib(int);
int main (){
    int x = 15;
    fib(x);
}
int fib(int x){
    if(x < 2){
        return 1;
    }
    return fib(x-1) + fib(x-2);
}