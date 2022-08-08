#pragma once

#include <fstream>
#include <string>
#include <map>

using namespace std;

using Data = map<string, string>;
using ItemData = pair<string, string>;

void export_to_file(const Data& data) {
    ofstream file;
    file.open("name.dat");

    if (file.is_open()) {
        for (const auto& item : data) {
            file << item.first << "=" << item.second << endl;
        }
    }

    file.close();
}

ItemData parser(const string& source, const string& delimiter) {
    int pos = source.find(delimiter);
    string key = source.substr(0, pos);
    string value = source.substr(pos + 1);

    return ItemData(key, value);
}

Data import_from_file() {
    string str;
    Data names;

    ifstream file;
    file.open("name.dat");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, str);
            if (str.empty()) continue;

            names.insert(parser(str, "="));
        }
    }

    file.close();

    return names;
}

bool file_exists() {
    ifstream file;
    file.open("name.dat");

    if (file.is_open()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}
