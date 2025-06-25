#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;
/*
    To-do: Write a random number function "randSum25(default param){return unsigned short 0 < x < 2^16-1}"
           Using the linear congruency formula. Pick a, b, and m such that it generates a truly random number sequence. Use a hash map.

*/
bool isPrime(int num){
    //0, 1 and negative numbers are never prime.
    if (num <= 1){
        return false;
    }
    for (int i = 2 ; i <= sqrt(num) ; i++){
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}  

unsigned short genRand(unsigned int Xseed = 1){
    static unsigned int a = 5;
    static unsigned int b = 1;
    static unsigned int m = 65536;
    static unsigned short rVal = Xseed % m;
    //Find values of a and b to get optimal values.
    rVal = (((a * rVal) % m + b) % m);
    return rVal;
}

int main(){
    int rNum = 65536;
    unsigned short linArr[rNum];
    map<unsigned short, int> u;
    /*
    for (int i = 2 ; i <= 65536 ; i++){
        string isP = isPrime(i) ? "Prime" : "Not prime";
        cout << i << " is: " << isP << endl;
    }
    */
   for (int i = 0 ; i < rNum ; i++){
    linArr[i] = genRand();
    u[linArr[i]]++;
    cout << linArr[i] << endl;
   }
   cout << "Unique objects: " << u.size() << endl;
    return 0;
}
