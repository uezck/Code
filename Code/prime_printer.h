#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

const int kOrdMax = 30;

// void PrintPrimeNumbersToFile(int numbers, int cc, int rr, int m);

class PrimePrinter {
private:
    int cc_, rr_, m_;

public:
    PrimePrinter(int cc, int rr, int m) {
        cc_ = cc;
        rr_ = rr;
        m_ = m;
    }
    void PrintToFile(int prime_numbers);
};
