#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

int main() {
    vector<Student> students;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "ID: "; cin >> s.id;
        cout << "Name: "; cin >> s.name;
        cout << "Age: "; cin >> s.age;

        students.push_back(s);
    }

    cout << "\nStudents:\n";
    for (auto s : students) {
        cout << s.id << " " << s.name << " " << s.age << endl;
    }

    return 0;
}