#include <iostream>
#include <stdlib.h>

int main() {
  char buf[256];
  size_t len;
  getenv_s(&len, buf, "SAMPLE");
  std::string sample(buf);
  std::cout << "SAMPLE: '" << sample << "'" << std::endl;
  return 0;
}
