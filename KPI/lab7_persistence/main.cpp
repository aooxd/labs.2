#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    int id;
    string name;
};

class Database {
private:
    vector<Student> data;

public:
    void add() {
        Student s;
        cin >> s.id >> s.name;
        data.push_back(s);
    }

    void show() {
        for (auto s : data) {
            cout << s.id << " " << s.name << endl;
        }
    }

    void save() {
        ofstream file("db.txt");
        for (auto s : data) {
            file << s.id << " " << s.name << endl;
        }
        cout << "Saved\n";
    }

    void load() {
        ifstream file("db.txt");
        Student s;

        while (file >> s.id >> s.name) {
            data.push_back(s);
        }

        cout << "Loaded\n";
    }
};

int main() {
    Database db;
    int choice;

    do {
        cout << "\n1-add 2-show 3-save 4-load 0-exit\n";
        cin >> choice;

        if (choice == 1) db.add();
        if (choice == 2) db.show();
        if (choice == 3) db.save();
        if (choice == 4) db.load();

    } while (choice != 0);

    return 0;
}