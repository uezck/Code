#include "prime_printer.h"
#include <vector>
class PrimeGenerator {
private:
    int kMaxOrd;
public:
    PrimeGenerator(int max_ord);
    std::vector<int>GeneratePrime(int numbers);
};

PrimeGenerator::PrimeGenerator(int max_ord) {
    kMaxOrd = max_ord;
}
std::vector<int> PrimeGenerator::GeneratePrime(int numbers){
  
  std::vector<int> prime_numbers = std::vector<int>(numbers+1);
  std::vector<int> mult = std::vector<int>(kMaxOrd+1);

  int j = 1;
  int k = 1;
  int ord = 2;
  int square = 9;
  prime_numbers[1] = 2;
  
  while (k < numbers) {
    bool jprime;
    do{
      j += 2;
      if (j == square) {
        ord++;
        square = prime_numbers[ord] * prime_numbers[ord];
        mult[ord - 1] = j;
      }
      int n = 2;
      jprime = true;
      while (n < ord && jprime) {
        while (mult[n] < j) {
          mult[n] += prime_numbers[n] + prime_numbers[n];
        }
        if (mult[n] == j) {
          jprime = false;
        }
        n++;
      }
    } while (!jprime);
    k++;
    prime_numbers[k] = j;
  }
  return prime_numbers;
}



