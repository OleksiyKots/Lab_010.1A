
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
    // Конструктор за замовчуванням, який ініціалізує всі змінні
    Student() : surname(""), course(0), speciality(COMPUTER_SCIENCE),
        physicsGrade(0), mathGrade(0), informaticsGrade(0) {}
};

// Функція для створення масиву студентів
void Create(Student* students, int N) {

    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":\n";
        cout << " Прізвище: "; cin >> students[i].surname;
        cout << " Курс: "; cin >> students[i].course;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> speciality;
        students[i].speciality = static_cast<Speciality>(speciality);
        cout << " Оцінка з фізики: "; cin >> students[i].physicsGrade;
        cout << " Оцінка з математики: "; cin >> students[i].mathGrade;
        cout << " Оцінка з інформатики: "; cin >> students[i].informaticsGrade;
    }
}

// Функція для виводу масиву студентів
void Print(const Student* students, int N) {
    cout << "===============================================================================================\n";
    cout << "| №  | Прізвище         | Курс | Спеціальність            | Фізика | Математика | Інформатика |\n";
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

// Функція для обчислення найбільшого середнього балу
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

// Функція для обчислення проценту студентів з оцінками 5 або 4 з фізики
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
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 для потоку вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 для потоку виводу
    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    double maxAvgGrade = MaxAverageGrade(students, N);
    cout << "Найбільший середній бал: " << fixed << setprecision(2) << maxAvgGrade << endl;

    double percentage = PercentageHighPhysicsGrades(students, N);
    cout << "Процент студентів з оцінками 5 або 4 з фізики: " << fixed << setprecision(2) << percentage << "%\n";

    delete[] students;
    return 0;
}
