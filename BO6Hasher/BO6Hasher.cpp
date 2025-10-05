#include <iostream>
#include <Windows.h>

const uint64_t Hash64A(const char* str, uint64_t start, uint64_t iv) {
    uint64_t hash = start;

    for (const char* data = str; *data; data++) {
        if (*data >= 'A' && *data <= 'Z') {
            hash = hash ^ (uint8_t)('a' + (*data - (byte)'A'));
        }
        else if (*data == '\\') {
            hash = hash ^ '/';
        }
        else {
            hash = hash ^ *data;
        }

        hash *= iv;
    }

    return hash;
}

const std::uint64_t hash_64a(const std::string& str, std::uint64_t start, std::uint64_t iv) {
    std::uint64_t hash = start;

    for (const char* data = str.data(); *data; data++) {
        if (*data >= 'A' && *data <= 'Z') {
            hash = hash ^ (std::uint8_t)('a' + (*data - (std::uint8_t)'A'));
        }
        else if (*data == '\\') {
            hash = hash ^ '/';
        }
        else {
            hash = hash ^ *data;
        }

        hash *= iv;
    }

    return hash;
}

const std::uint64_t hash_scr_dvar(const std::string& str) {
    std::uint64_t hash = 0;
    switch (str.at(0)) {
    case 0:
        hash = 0;
        break;
    case 'a': case 'A':
        hash = hash_64a(str, 0xE4A68FF7D4912FD2, 0x10000000233);
        break;
    case 'b': case 'B':
        hash = hash_64a(str, 0x35EC9BBDCBCE1C0E, 0x10000000233);
        break;
    case 'c': case 'C':
        hash = hash_64a(str, 0xDA27710BE4CE51A, 0x10000000233);
        break;
    case 'd': case 'D':
        hash = hash_64a(str, 0x7238A5E2001AEB8E, 0x10000000233);
        break;
    case 'f': case 'F':
        hash = hash_64a(str, 0xAF25952FD142C84E, 0x10000000233);
        break;
    case 'g': case 'G':
        hash = hash_64a(str, 0xDF9B64790A1B6DB2, 0x10000000233);
        break;
    case 'h': case 'H':
        hash = hash_64a(str, 0xF74A6B45EC63764E, 0x10000000233);
        break;
    case 'l': case 'L':
        hash = hash_64a(str, 0xBFF2A0737EB2B2BE, 0x10000000233);
        break;
    case 'm': case 'M':
        hash = hash_64a(str, 0xFBE5EB20A0DF848A, 0x10000000233);
        break;
    case 'o': case 'O':
        hash = hash_64a(str, 0xE81A3159054FF1F2, 0x10000000233);
        break;
    case 'p': case 'P':
        hash = hash_64a(str, 0xA3BF3E5BFC4CB65E, 0x10000000233);
        break;
    case 'r': case 'R':
        hash = hash_64a(str, 0x251C962D8AB28AE, 0x10000000233);
        break;
    case 's': case 'S':
        hash = hash_64a(str, 0x8913204B4A9FE29A, 0x10000000233);
        break;
    case 'u': case 'U':
        hash = hash_64a(str, 0x5221A5281FDEAC5A, 0x10000000233);
        break;
    case 'w': case 'W':
        hash = hash_64a(str, 0x62C0087A686DCC32, 0x10000000233);
        break;
    default:
        hash = 0;
        break;
    }

    std::cout << "Dvar: " << str << " => Hash: 0x" << std::hex << hash << std::dec << std::endl;
    return hash;
}

int main()
{
    SetConsoleTitleA("Cod Dvar Hasher");
    std::string input;
    std::cout << "Example: ui_is_magma_gamemode -> 0xb5d05c0cbfa8bdc1\n";
    std::cout << "If you wanna use this with cbuf, just take away 0x and replace it with #x3, 0xb5d05c0cbfa8bdc1 -> #x30xb5d05c0cbfa8bdc1\n";
    while (true) {
        std::cin >> input;

        if (!input.empty()) {
            hash_scr_dvar(input);
        }
        else
            continue;
    }

    return 0;
}