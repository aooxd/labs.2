#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
    double grade;
};

class Database {
private:
    vector<Student> data;

public:
    void add() {
        Student s;
        cin >> s.name >> s.age >> s.grade;
        data.push_back(s);
    }

    void show() {
        for (auto s : data) {
            cout << s.name << " " << s.age << " " << s.grade << endl;
        }
    }

    void filterByGrade(double minGrade) {
        for (auto s : data) {
            if (s.grade >= minGrade) {
                cout << s.name << " " << s.grade << endl;
            }
        }
    }

    void sortByAge() {
        sort(data.begin(), data.end(),
            [](Student a, Student b) {
                return a.age < b.age;
            });
    }
};

int main() {
    Database db;
    int choice;

    do {
        cout << "\n1-add 2-show 3-filter 4-sort 0-exit\n";
        cin >> choice;

        if (choice == 1) db.add();
        if (choice == 2) db.show();
        if (choice == 3) {
            double g;
            cin >> g;
            db.filterByGrade(g);
        }
        if (choice == 4) db.sortByAge();

    } while (choice != 0);

    return 0;
}