#include <gmpxx.h>
#include <iostream>

int main() {

  bool exit = false;

  do {
    std::cout << "Input a positive integer to show its Collatz sequence or "
                 "'exit' to quit\n";

    std::string raw_input;

    mpz_class collatz;

    std::cin >> raw_input;

    try {
      collatz = raw_input;
      while (collatz != 1) {
        if (collatz % 2 == 0) {
          collatz = collatz / 2;
        } else {
          collatz = (collatz * 3) + 1;
        }
        std::cout << collatz << std::endl;
      }
    } catch (const std::invalid_argument &e) {
      if (raw_input == "exit") {
        exit = true;
        return 0;
      } else {
        std::cerr << "Error: " << e.what() << std::endl;
      }
    }

  } while (exit == false);

  return 0;
}
