#include "prime_printer.h"
#include <vector>

std::vector<int> GenereatePrime(int numbers){
  
  std::vector<int> prime_numbers = std::vector<int>(numbers+1);
  
  int j = 1;
  int k = 1;
  bool jprime;
  int ord = 2;
  int square = 9;
  int n = 0;
  int mult[kOrdMax + 1];
  
  prime_numbers[1] = 2;
  
  while (k < numbers){
    do{
      j += 2;
      if (j == square){
        ord++;
        square = prime_numbers[ord] * prime_numbers[ord];
        mult[ord - 1] = j;
      }
      n = 2;
      jprime = true;
      while (n < ord && jprime){
        while (mult[n] < j){
          mult[n] += prime_numbers[n] + prime_numbers[n];
        }
        if (mult[n] == j){
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

void PrintToFile(int cc, int rr, int m,std::vector<int> prime_numbers){
  int page_number = 1;
  int page_offset = 1;
  
  while (page_offset <= m){
    std::cout << "The First ";
    std::cout << m;
    std::cout << " Prime Numbers --- Page ";
    std::cout << page_number;
    std::cout << std::endl;
    for (int row_offset = page_offset; 
      row_offset <= page_offset + rr - 1; 
      row_offset++){
      for (int C = 0; C <= cc - 1; C++){
        if (row_offset + C * rr <= m){
          std::cout << std::setw(10) << prime_numbers[row_offset + C * rr];
        }       
      }
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    page_number++;
    page_offset += rr * cc;
  }
}

void PrintPrimeNumbersToFile(int numbers, int cc, int rr, int m){

  std::vector<int> primes = GenereatePrime(numbers);
  PrintToFile(cc,rr,m,primes);

  
}