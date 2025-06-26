#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
/*

    Input: Array/String of letters.
    Output: Calculate formulaic sum.
    To-do: Make letterDist faster via closed form solution.
           Add single sum solution using partitioning.
*/

using namespace std;
using namespace chrono;

long long newLetterDist(string sCase){
    
    int n = sCase.size();
    //Single-sum iteration computes regardless of duplicates
    //Now, I compute the total sum and take the difference between the sum that accounts for the duplicates.
    long long sum = 0;
    for (int i = 0 ; i < n ; i++){
        sum += (n-i)*pow(i,2);
    }
    return sum;
}

/*
int letterDist(string sCase){
    int sum = 0;
    int n = sCase.size();
    for (int i = 0 ; i < n ; i++){
        for (int j = i ; j < n; j++){
            sum += (pow(j-i,2)) * ((sCase[i] != sCase[j]) ? 1 : 0);
        }
    }
    
    return sum % 1000000007;

}
*/

int main(){

    cout << newLetterDist("ICPC") << endl;
    cout << newLetterDist("SOCAL") << endl;

    return 0;
}
