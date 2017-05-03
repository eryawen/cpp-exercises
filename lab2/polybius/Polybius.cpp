#include "Polybius.h"

using ::std::string;
using ::std::to_string;

std::string EncryptChar(char c);

string EncryptMessage(const std::string &message) {
    std::string encrypted = "";
    unsigned long n = message.length();
    for (int i = 0; i < n; i++) {
        encrypted += EncryptChar(message[i]);
    }
    return encrypted;
}

std::string EncryptChar(char c) {
    if (!isalpha(c))
        return std::string("");
    int shift = tolower(c) - 'a';
    if (shift >= 9) shift--;
    int row = shift / 5 + 1;
    int col = shift % 5 + 1;
    return std::to_string(row * 10 + col);
}

std::string DecryptMessage(const std::string &message) {
    std::string decrypted = "";
    unsigned long n = message.length();
    for (int i = 0; i < n; i = i + 2) {
        decrypted += DecryptChar(message[i], message[i + 1]);
    }
    return decrypted;
}

char DecryptChar(char fst, char snd) {
    int row = (fst - '0');
    int col = (snd - '0');
    int pos = (row - 1) * 5 + col;
    int char_ascii = 'a' + pos;
    char_ascii = (char_ascii > 'j') ? char_ascii : char_ascii - 1;
    return (char) char_ascii;
}
