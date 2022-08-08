#include <iostream>

#include "file_config.h"

using namespace std;

int main() {
    Data names;

    if (file_exists()) {
        names = import_from_file();
    } else {
        string first_name;
        string last_name;

        cout << "Enter first name: ";
        cin >> first_name;

        cout << "Enter last name: ";
        cin >> last_name;

        names.insert(ItemData("last_name", last_name));
        names.insert(ItemData("first_name", first_name));

        export_to_file(names);
    }

    for (auto item : names) {
        cout << item.first << " -> " << item.second << endl;
    }

    return 0;
}
