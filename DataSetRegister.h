#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Participants.h"

const int BEST_SIZE = 64 * 1024;
const int NORMAL_SIZE = 1024 * 1024;
const int WORST_SIZE = 4 * 1024 * 1024;

template <typename T>
struct DataSet
{
    std::string description;
    std::vector<T> data;
};

std::stack<DataSet<Byte>> GenerateByteDataSets();
//Здесь пишем свои входные данные
