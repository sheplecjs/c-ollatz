#include <gmpxx.h>
#include <iostream>

int main() {

  // condition for ending execution loop
  bool exit = false;

  do {
    std::cout << "Input a positive integer to show its Collatz sequence or "
                 "'exit' to quit\n";

    std::string raw_input;

    mpz_class collatz;

    std::cin >> raw_input;

    // attempt to interpret the input as a GMP integer class
    try {
      collatz = raw_input;

      // print the sequence
      while (collatz != 1) {
        if (collatz % 2 == 0) {
          collatz = collatz / 2;
        } else {
          collatz = (collatz * 3) + 1;
        }
        std::cout << collatz << std::endl;
      }
    }
    // if not an integer, check for reserved words
    catch (const std::invalid_argument &e) {
      if (raw_input == "exit") {
        exit = true;
        return 0;
      } else {
        std::cerr << "Error: " + raw_input + " - input not an integer"
                  << std::endl;
      }
    }
    // if outside of GMP range
    catch (const std::out_of_range &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }

  } while (exit == false);

  return 0;
}
