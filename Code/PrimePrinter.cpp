#include "prime_printer.h"
class PrimePrinter
{
private:
    int cc,rr,m;
public:
    PrimePrinter(int cc, int rr, int m);
    void PrintToFile(std::vector<int> prime_numbers);
};

PrimePrinter::PrimePrinter(int cc, int rr, int m)
{
    cc = cc;
    rr = rr;
    m = m;
}

void PrimePrinter::PrintToFile(std::vector<int> prime_numbers){
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