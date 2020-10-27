#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void hex_dump(const T& dude) {
  const unsigned char * c = reinterpret_cast <const unsigned char *>(&dude);
  for (size_t i = 0; i < sizeof(dude); ++i)
    printf("%02x ", c[i]);
  std::cout << "\n";
}

int main() {
  // ex 1.
  std::string name;
  int age;
  std::cout << "Enter Name Age: ";
  std::cin >> name >> age;
  std::cout << "Hello " << name << " you are " << age << "\n";

  int x = 24;
  int y = 31;
  for (int i = 0; i < 20; i = i + 2) {
    std::cout << x + i << " * " << y - i << " = " << (x + i) * (y - i) << "\n";
  }
  // ex 2.
  int vv[8] = {2,2,3,3,4,4,5,5};
  for (auto n:vv) // n copied, not ref
    n = n+2;
  for (auto a:vv)
    std::cout << a << " ";
  std::cout << "\n";

  for (auto& n:vv) // use ref and mod the array
    n = n+2;
  for (auto a:vv)
    std::cout << a << " ";
  std::cout << "\n";

  std::string lol = "12345";
  std::cout << "lol size " << lol.size() << "\n";
  std::cout << "lol length " << lol.length() << "\n";
  std::cout << "lol sozeof " << sizeof(lol) << "\n";
  hex_dump<std::string>(lol);
  lol += "my little experiment to grow you 8899 aabbccdd";
  std::cout << "lol size " << lol.size() << "\n";
  std::cout << "lol length " << lol.length() << "\n";
  std::cout << "lol sozeof " << sizeof(lol) << "\n";
  hex_dump<std::string>(lol);

  return 0;
}
