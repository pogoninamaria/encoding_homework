#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "DataSetRegister.h"
#include "Participants.h"
#include <regex>

using namespace std;

string ParseName(string& method_name)
{
    transform(method_name.begin(), method_name.end(), method_name.begin(),
        [](unsigned char c) { return std::tolower(c); });

    auto res = regex_replace(method_name, std::regex("_by_"), "\t");
    if (res.length() == method_name.length())
    {
        res = regex_replace(res, std::regex("by"), "\t");
        if (res.length() == method_name.length())
            res = regex_replace(res, std::regex("_"), "\t");
    }
    return res;
}
#define RUN(x) {                             \
    Run(#x, x##_encrypt, x##_decrypt, data); \
}

static string team = "";
static string dataset = "";
static vector<string> logs;
static void Log(const string& method_name, const string& operation, size_t size, long long time, bool ok)
{
    string name = method_name + "_" + operation;
    ostringstream oss{};
    oss << "\"" << dataset << "\"\t"
        << size << "\t"
        << team << "\t"
        << ParseName(name) << "\t"
        << (ok ? to_string(time) : "-1");
    logs.push_back(oss.str());
}
template <typename T>
void Run(string method_name, Participant<T> encrypt, Participant<T> decrypt, vector<T> data)
{
    auto start = chrono::system_clock::now();
    vector<T> res = encrypt(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    ostringstream oss{};
    oss << "\"" << dataset << "\"\t"
        << data.size() << "\t"
        << team << "\t"
        << ParseName(method_name) << "\t"
        << "encrypt\t"
        << ((data.size() == res.size() && res != data) ? to_string(time) : "-1");
    logs.push_back(oss.str());

    start = chrono::system_clock::now();
    vector<T> res2 = decrypt(res);
    stop = chrono::system_clock::now();
    time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    ostringstream oss2{};
    oss2 << "\"" << dataset << "\"\t"
        << data.size() << "\t"
        << team << "\t"
        << ParseName(method_name) << "\t"
        << "decrypt\t"
        << ((res2 == data) ? to_string(time) : "-1");
    logs.push_back(oss2.str());
}

int main()
{
    {
        cout << endl << "**************BLOCK CIPHER RACE**************" << endl << endl;

        auto byteDataSets = GenerateByteDataSets();
        while (!byteDataSets.empty())
        {
            auto& ds = byteDataSets.top();
            dataset = ds.description;
            auto& data = ds.data;
            //team = "";
            //RUN(Название метода);

            byteDataSets.pop();
        }
    }

    {
        ofstream fout("release.txt");
        for (auto& s : logs)
        {
            fout << s << endl;
            cout << s << endl;
        }
    }
}