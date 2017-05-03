#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <string>
#include <iostream>
#include <fstream>

std::string EncryptChar(char letter);

char DecryptChar(char fst, char snd);

std::string EncryptMessage(const std::string &message);

std::string DecryptMessage(const std::string &message);

#endif //JIMP_EXERCISES_POLYBIUS_H