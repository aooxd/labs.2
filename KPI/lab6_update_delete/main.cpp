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
        cout << "Enter id and name: ";
        cin >> s.id >> s.name;
        data.push_back(s);
    }

    void show() {
        for (auto s : data) {
            cout << s.id << " " << s.name << endl;
        }
    }

    void remove(int id) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                data.erase(data.begin() + i);
                cout << "Deleted\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void update(int id) {
        for (auto &s : data) {
            if (s.id == id) {
                cout << "New name: ";
                cin >> s.name;
                cout << "Updated\n";
                return;
            }
        }
        cout << "Not found\n";
    }
};

int main() {
    Database db;
    int choice;

    do {
        cout << "\n1-add 2-show 3-delete 4-update 0-exit\n";
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

    } while (choice != 0);

    return 0;
}