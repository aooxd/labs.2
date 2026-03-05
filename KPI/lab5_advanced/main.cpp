#include <iostream>
#include <vector>

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
};

int main() {
    Database db;
    int choice;

    do {
        cout << "1-add 2-show 0-exit\n";
        cin >> choice;

        if (choice == 1) db.add();
        if (choice == 2) db.show();

    } while (choice != 0);

    return 0;
}