#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
};

int main() {
    vector<Student> students = {
        {1, "Anna"},
        {2, "Ivan"},
        {3, "Oleg"}
    };

    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    bool found = false;

    for (auto s : students) {
        if (s.name == searchName) {
            cout << "Found: " << s.id << " " << s.name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Not found\n";
    }

    return 0;
}