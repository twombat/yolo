#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> void hex_dump(const T &dude) {
  const unsigned char *c = reinterpret_cast<const unsigned char *>(&dude);
  for (size_t i = 0; i < sizeof(dude); ++i)
    printf("%02x ", c[i]);
  std::cout << "\n";
}

int main() {
  std::vector<int> primes;
  primes.reserve(32);
  primes.push_back(2);
  for (int i = 3; i < 50; i++) {
    bool prime = true;
    for (auto p : primes) {
      if (i % p == 0) {
        prime = false;
        break;
      } else if (p * p > i)
        break;
    }
    if (prime)
      primes.push_back(i);
  }
  for (auto p : primes)
    std::cout << p << " ";

  std::cout << "\nTotal: " << primes.size() << "\n";

  cout << "Output of begin and end: ";
  for (auto i = primes.begin(); i != primes.end(); ++i)
    cout << *i << " ";
  cout << "\n";
  cout << "Output of rbegin and rend: ";
  for (auto ir = primes.rbegin(); ir != primes.rend(); ++ir)
    cout << *ir << " ";
  cout << "\n";
  cout << "max " << primes.max_size() << " cap " << primes.capacity() << "\n";
  primes.resize(50);
  cout << "max " << primes.max_size() << " cap " << primes.capacity() << "\n";
  if (!primes.empty()) {
    primes.shrink_to_fit();
  }
  cout << "max " << primes.max_size() << " cap " << primes.capacity() << "\n";
  cout << primes.at(2) << " " << primes[3] << "\n";
  cout << primes.front() << " " << primes.back() << "\n";
  auto pos = primes.data(); // int*
  cout << "Pos +6 = " << *pos + 6 << "\n";

  // assign() – It assigns new value to the vector elements by replacing old
  // ones push_back() – It push the elements into a vector from the back
  // pop_back() – It is used to pop or remove elements from a vector from the
  // back. insert() – It inserts new elements before the element at the
  // specified position erase() – It is used to remove elements from a container
  // from the specified position or range. swap() – It is used to swap the
  // contents of one vector with another vector of same type. Sizes may differ.
  // clear() – It is used to remove all the elements of the vector container
  // emplace() – It extends the container by inserting new element at position
  // emplace_back() – It is used to insert a new element into the vector
  // container, the new element is added to the end of the vector

  // Assign vector
  vector<int> v;

  // fill the array with 10 five times
  v.assign(5, 10);

  cout << "The vector elements are: ";
  for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  // inserts 15 to the last position
  v.push_back(15);
  int n = v.size();
  cout << "\nThe last element is: " << v[n - 1];

  // removes last element
  v.pop_back();

  // prints the vector
  cout << "\nThe vector elements are: ";
  for (auto i : v)
    cout << i << " ";

  // inserts 5 at the beginning +1
  v.insert(v.begin()+1, 5);

  cout << "\nInsert: The first element is: " << v[0] << " --> ";
  for (auto i : v)
    cout << i << " ";

  // removes the first element
  v.erase(v.begin());

  cout << "\nRemove: The first element is: " << v[0] << " --> ";
  for (auto i : v)
    cout << i << " ";

  // inserts at the beginning
  v.emplace(v.begin()+3, 7);
  cout << "\nEmplace: The first element is: " << v[0] << " --> ";
  for (auto i : v)
    cout << i << " ";

  // Inserts 20 at the end
  v.emplace_back(20);
  n = v.size();
  cout << "\nThe last element is: " << v[n - 1] << " --> ";
  for (auto i : v)
    cout << i << " ";

  // erases the vector
  v.clear();
  cout << "\nVector size after erase(): " << v.size();

  // two vector to perform swap
  vector<int> v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(5);

  cout << "\n\nVector 1: ";
  for (auto i : v1)
    cout << i << " ";

  cout << "\nVector 2: ";
  for (auto i : v2)
    cout << i << " ";

  // Swaps v1 and v2
  v1.swap(v2);

  cout << "\nAfter Swap \nVector 1: ";
  for (auto i : v1)
    cout << i << " ";

  cout << "\nVector 2: ";
  for (auto i : v2)
    cout << i << " ";
  cout << "\n";

  vector<string> vs = {"kp", "junk", "zarr", "lmao", "oof", "luz", "fof", "puke"};
  sort(vs.begin(), vs.begin()+4);
  for (auto vv : vs)
    cout << vv << " ";
  cout << "\n";
  sort(vs.begin(), vs.end());
  for (auto vv : vs)
    cout << vv << " ";
  cout << "\n";
  string s = "abcdef";
  for (size_t i = 0; i < s.size(); ++i) {
  string bu = s;
  bu.erase(i,1);
  cout << bu << "\n";
  }
  return 0;
}
