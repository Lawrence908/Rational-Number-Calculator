#include <iostream>

using namespace std;


int gcd(int a, int b){
    
    int q;
    int r = 1;

    if(a == b) return 1;
    else{
        while(r != 0){
            if(a < b){
                int temp = a;
                a = b;
                b = temp;
            }
            q = a/b;
            r = a - (q * b);
            if (r == 0){
                return b;
            }
            a = b;
            b = r;
        }
    }
    return 0;
}


int main(){

    int x = gcd(10, 100);
    cout << "gcd = " << x <<endl;
    return 0;
}