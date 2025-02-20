#include<stdio.h>

double power(float a, int n){
    
    if (n==0){
        return 1;
    }
    if (n%2==0){
        return (power(a,n/2)*power(a,n/2));
    }
    else{
        return (power(a, n/2) * power(a, n/2) * a);
        
    }
}

int main(){
    printf("%.4f\n", power(2, 3));
    return 0;
}