#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student {
    int id;
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
        cout << "Enter id name age grade: ";
        cin >> s.id >> s.name >> s.age >> s.grade;
        data.push_back(s);
    }

    void show() {
        cout << "\n--- Students ---\n";
        for (auto s : data) {
            cout << s.id << " "
                 << s.name << " "
                 << s.age << " "
                 << s.grade << endl;
        }
    }

    void remove(int id) {
        data.erase(
            remove_if(data.begin(), data.end(),
                [id](Student s) { return s.id == id; }),
            data.end()
        );
    }

    void update(int id) {
        for (auto &s : data) {
            if (s.id == id) {
                cout << "New name: ";
                cin >> s.name;
                cout << "New age: ";
                cin >> s.age;
                cout << "New grade: ";
                cin >> s.grade;
                return;
            }
        }
        cout << "Not found\n";
    }

    void findByName(string name) {
        for (auto s : data) {
            if (s.name == name) {
                cout << s.id << " " << s.name << endl;
            }
        }
    }

    void sortByGrade() {
        sort(data.begin(), data.end(),
            [](Student a, Student b) {
                return a.grade > b.grade;
            });
    }

    void save() {
        ofstream file("db.txt");
        for (auto s : data) {
            file << s.id << " "
                 << s.name << " "
                 << s.age << " "
                 << s.grade << endl;
        }
    }

    void load() {
        ifstream file("db.txt");
        Student s;
        while (file >> s.id >> s.name >> s.age >> s.grade) {
            data.push_back(s);
        }
    }
};

int main() {
    Database db;
    int choice;

    do {
        cout << "\n1-add\n2-show\n3-delete\n4-update\n5-find\n6-sort\n7-save\n8-load\n0-exit\n";
        cin >> choice;

        if (choice == 1) db.add();
        if (choice == 2) db.show();

        if (choice == 3) {
            int id;
            cin >> id;
            db.remove(id);
        }

        if (choice == 4) {
            int id;
            cin >> id;
            db.update(id);
        }

        if (choice == 5) {
            string name;
            cin >> name;
            db.findByName(name);
        }

        if (choice == 6) db.sortByGrade();
        if (choice == 7) db.save();
        if (choice == 8) db.load();

    } while (choice != 0);

    return 0;
}