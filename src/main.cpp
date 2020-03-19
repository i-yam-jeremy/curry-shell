#include <iostream>

std::string parseId(std::string source, int& pos) {
  skipWhitespace(source, pos);
  std::string id = "";
  if (('a' <= source[pos] && source[pos] <= 'z') ||
      ('A' <= source[pos] && source[pos] <= 'Z')) {
    id += source[pos];
    pos++;
    while (('a' <= source[pos] && source[pos] <= 'z') ||
           ('A' <= source[pos] && source[pos] <= 'Z') ||
           ('0' <= source[pos] && source[pos] <= '9')) {
      id += source[pos];
      pos++;
    }
  }
  return id;
}

 parseApplication(std::string source, int& pos) {
  skipWhitespace(source, pos);
  if (source == "0")
}

int main() {
  bool running = true;
  while (running) {
    std::string line;
    std::cout << "> ";
    std::cin >> line;
    if (line == "exit") {
      running = false;
    }
    else {
      int pos = 0;
      std::string id = parseId(line, pos);
      std::cout << "Id: " << id << std::endl;
    }
  }
  return 0;
}
