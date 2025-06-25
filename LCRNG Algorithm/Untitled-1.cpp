#include <iostream>
#include <map>
#include <limits> // For numeric_limits if you want to verify USHRT_MAX

// Recommended to put LCG in a class for proper state management
class LCG_Generator {
private:
    // IMPORTANT: Use const long long and LL suffix for these constants
    // This ensures intermediate multiplication does not overflow a 32-bit int
    static const long long a = 25173LL; // Multiplier
    static const long long b = 13849LL; // Increment
    static const long long m = 65536LL; // Modulus (2^16)

    unsigned short current_rVal; // The current state of the generator

public:
    // Constructor to seed the generator
    LCG_Generator(unsigned int Xseed = 1) {
        // Ensure initial seed is within [0, m-1]
        // Adding m_ll ensures positive result before modulo, then cast
        current_rVal = static_cast<unsigned short>( (Xseed % m + m) % m );
    }

    // Function to generate the next random number
    unsigned short genRand() {
        // LCG formula: X_n+1 = (a * X_n + b) % m
        // Cast current_rVal to long long before multiplication to prevent overflow
        current_rVal = static_cast<unsigned short>((a * current_rVal + b) % m);
        return current_rVal;
    }
};

int main() {
    LCG_Generator my_rand_gen(1); // Create an instance, seeding with 1

    int rNum_iterations = 65536; // We expect m unique numbers for a full period
    std::map<unsigned short, int> unique_counts;

    std::cout << "Generating " << rNum_iterations << " random numbers..." << std::endl;

    for (int i = 0 ; i < rNum_iterations ; ++i){
        unsigned short generated_val = my_rand_gen.genRand();
        unique_counts[generated_val]++; // Count occurrences of each unique number
    }

    std::cout << "Finished generation." << std::endl;
    std::cout << "Total generated: " << rNum_iterations << std::endl;
    std::cout << "Unique values found: " << unique_counts.size() << std::endl;

    return 0;
}