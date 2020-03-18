#include <iostream>

int main() {
  bool running = true;
  while (running) {
    std::string line;
    std::cout << "> ";
    std::cin >> line;
    if (line == "exit") {
      running = false;
    }
  }
  return 0;
}
