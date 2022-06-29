#include <iostream>

using namespace std;

string generate_uuid() {
    string uuid = "";
    for (int i = 0; i < 16; i++) {
        uuid += (char)(rand() % 10 + 48);
    }
    return uuid;
  }