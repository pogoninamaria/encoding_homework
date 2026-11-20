#pragma once
#include <string>
#include <stack>
#include "DataGenerators.h"

template <typename T>
struct DataSet
{
    std::string description;
    std::vector<T> data;
};

std::stack<DataSet<Byte>> GenerateByteDataSets()
{
    return std::stack< DataSet<Byte>>({

        //Пример для Blowfish
        //{ "Blowfish worst (random, 4 MB)", GenerateWorstDataBlowfish(4 * 1024 * 1024) },
        //{ "Blowfish normal (text, 1 MB)",  GenerateNormalDataBlowfish(1024 * 1024) },
        //{ "Blowfish best (zeros, 64 KB)",  GenerateBestDataBlowfish(64 * 1024) },

        { "Test 3: ", {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31} },
        { "Test 2: ", {'H','e','l','l','o',',',' ','W','o','r','l','d','!',0,0,0} },
        { "Test 1: ", {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} },
        });
}