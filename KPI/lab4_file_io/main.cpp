#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
};

int main() {
    vector<Student> students = {
        {1, "Anna"},
        {2, "Ivan"}
    };

    ofstream out("students.txt");

    for (auto s : students) {
        out << s.id << " " << s.name << endl;
    }

    out.close();

    cout << "Data saved to file.\n";

    return 0;
}