#include <iostream>

using namespace std;

void reverse(char* str) {
  // Find the end first
  char* end = str;
  if (!str) return;
  while (*end != '\n') {
    ++end;
  }
  --end;  // We don't need to swap the '\n'
  char tmp;
  while (str < end) {
    tmp = *str;
    *str++ = *end;
    *end-- = tmp;
  }
}

int main() {
  char str[] = "This is a string, and it reverses!\n";
  cout << str << endl;
  reverse(str);
  cout << str << endl;
}

