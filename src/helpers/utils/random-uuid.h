#include <iostream>

using namespace std;

string generate_uuid() {
       UUID uuid;
    RPC_CSTR  uuid_str;
    std::string uuid_out;

    if (UuidCreate(&uuid) != RPC_S_OK)
        std::cout << "couldn't create uuid\nError code" << GetLastError() << std::endl;

    if (UuidToStringA(&uuid, &uuid_str) != RPC_S_OK)
        std::cout << "couldn't convert uuid to string\nError code" << GetLastError() << std::endl;

    uuid_out = (char*)uuid_str;
    RpcStringFreeA(&uuid_str);
    return uuid_out;
}