#include "prime_printer.h"
#include "prime_generator.h"

void PrimePrinter::PrintToFile(int numbers) {
  PrimeGenerator generator = PrimeGenerator(kOrdMax);
  std::vector<int> prime_numbers = generator.GeneratePrime(numbers);

  int page_number = 1;
  int page_offset = 1;

  while (page_offset <= m_) {
    std::cout << "The First ";
    std::cout << m_;
    std::cout << " Prime Numbers --- Page ";
    std::cout << page_number;
    std::cout << std::endl;
    for (int row_offset = page_offset;
         row_offset <= page_offset + rr_ - 1;
         row_offset++){
          
      for (int C = 0; C <= cc_ - 1; C++) {
        if (row_offset + C * rr_ <= m_) {
          std::cout << std::setw(10) << prime_numbers[row_offset + C * rr_];
        }
      }
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    page_number++;
    page_offset += rr_ * cc_;
  }
};
