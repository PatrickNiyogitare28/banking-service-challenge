#include <iostream>

using namespace std;

string generate_uuid() {
    // generate uniqui uuid 16 bytes
    string uuid = "";
    for (int i = 0; i < 16; i++) {
        uuid += to_string(rand() % 10);
    }
    return uuid;
}