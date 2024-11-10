
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
    // ����������� �� �������������, ���� �������� �� ����
    Student() : surname(""), course(0), speciality(COMPUTER_SCIENCE),
        physicsGrade(0), mathGrade(0), informaticsGrade(0) {}
};

// ������� ��� ��������� ������ ��������
void Create(Student* students, int N) {

    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":\n";
        cout << " �������: "; cin >> students[i].surname;
        cout << " ����: "; cin >> students[i].course;
        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> speciality;
        students[i].speciality = static_cast<Speciality>(speciality);
        cout << " ������ � ������: "; cin >> students[i].physicsGrade;
        cout << " ������ � ����������: "; cin >> students[i].mathGrade;
        cout << " ������ � �����������: "; cin >> students[i].informaticsGrade;
    }
}

// ������� ��� ������ ������ ��������
void Print(const Student* students, int N) {
    cout << "===============================================================================================\n";
    cout << "| �  | �������         | ���� | ������������            | Գ���� | ���������� | ����������� |\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << left << "| " << setw(3) << i + 1 << "| " << setw(17) << left << students[i].surname
            << "| " << setw(4) << students[i].course
            << " | " << setw(24) << specialityStr[students[i].speciality]
            << " | " << setw(6) << students[i].physicsGrade
            << " | " << setw(10) << students[i].mathGrade
            << " | " << setw(11) << students[i].informaticsGrade << " |\n";
    }
    cout << "===============================================================================================\n";
}

// ������� ��� ���������� ���������� ���������� ����
double MaxAverageGrade(const Student* students, int N) {
    double maxAvg = 0.0;
    for (int i = 0; i < N; i++) {
        double avg = (students[i].physicsGrade + students[i].mathGrade + students[i].informaticsGrade) / 3.0;
        if (avg > maxAvg) {
            maxAvg = avg;
        }
    }
    return maxAvg;
}

// ������� ��� ���������� �������� �������� � �������� 5 ��� 4 � ������
double PercentageHighPhysicsGrades(const Student* students, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].physicsGrade == 4 || students[i].physicsGrade == 5) {
            count++;
        }
    }
    return (static_cast<double>(count) / N) * 100;
}

int main() {
    SetConsoleCP(1251); // ������������ ������� win-cp1251 ��� ������ �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 ��� ������ ������
    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    double maxAvgGrade = MaxAverageGrade(students, N);
    cout << "��������� ������� ���: " << fixed << setprecision(2) << maxAvgGrade << endl;

    double percentage = PercentageHighPhysicsGrades(students, N);
    cout << "������� �������� � �������� 5 ��� 4 � ������: " << fixed << setprecision(2) << percentage << "%\n";

    delete[] students;
    return 0;
}
