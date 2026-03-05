#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    vector<Student> students = {
        {"Anna", 85.5},
        {"Ivan", 72.3},
        {"Oleg", 90.1}
    };

    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.grade > b.grade;
        });

    cout << "Sorted by grade:\n";
    for (auto s : students) {
        cout << s.name << " " << s.grade << endl;
    }

    return 0;
}