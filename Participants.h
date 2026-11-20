#pragma once
#include <vector>

typedef unsigned char  Byte;
typedef unsigned short word16;
typedef unsigned int   word32;

const int BLOCK_SIZE = 8;

const int KEY_LEN = 16;
const Byte KEY[KEY_LEN] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,
                            0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };

template <typename T>
using Participant = std::vector<T>(*)(std::vector<T>);

//Пример для Blowfish
//--------------------Blowfish (Фамилия)---------------------------
//std::vector<Byte> blowfish_encrypt(std::vector<Byte> data);
//std::vector<Byte> blowfish_decrypt(std::vector<Byte> data);

