#include <iostream>
#include <unordered_map>

using namespace std;

bool solution(std::string st) {
  unordered_map<char, bool> hash;
  for (char c:st) {
    if (hash.count(c) > 0) {
      return false;
    }
    hash[c] = true;
  }
  return true;
}

int main() {
  string st = "abfcdefg";
  cout << solution(st) << endl;
}
