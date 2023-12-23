#include <gmpxx.h>
#include <iostream>

int main() {
  std::cout << "Input a positive integer to show its Collatz sequence\n";

  mpz_class collatz;

  std::cin >> collatz;

  if (std::cin.fail()) {
    std::cerr << "Must be a positive integer." << std::endl;
    return 1;
  }

  while (collatz != 1) {
    if (collatz % 2 == 0) {
      collatz = collatz / 2;
    } else {
      collatz = (collatz * 3) + 1;
    }
    std::cout << collatz << std::endl;
  }

  return 0;
}
