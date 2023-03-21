#include <iostream>

using namespace std;

int gcd(int a, int b){
    
    int q;
    int r = 1;

    if(a == b) return b;
    else{
        if(a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        while(r != 0){
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


void reduce(){
    int x = gcd(top, bottom);
    top = top/x;
    bottom = bottom/x;
}

int main(){

    int x = gcd(7984, 10654);
    cout << "gcd = " << x <<endl;
    return 0;
}