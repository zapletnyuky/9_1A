#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Spec { KN, IN, ME, FI, TR };
enum Curs { FIRST, SECOND, THIRD, FOURTH };
string cursStr[] = { "I", "II", "III", "IV" };
string specStr[] = { "КомпНауки", "Інформ", "Мат+Ек", "Фіз+Інф", "ТрудНавч" };
    struct Student
    {
        string prizv;
     // enum Spec x, y;
        int kurs;
        Spec spec;
        int fiz;
        int mat;
        int inf;
    };
void Create(Student *p, const int N);
void Print(Student *p, const int N);
void DisplayAverageGrades(Student *p, const int N);
double Procenti(Student *p, const int N);
int main()
{
    int N;
    cout << "кількість студентів: "; cin >> N;
    Student *p = new Student[N];
    Create(p, N);
    Print(p, N);
    DisplayAverageGrades(p, N);
   // double sum = Seredniy(p, N);
    //cout << "1. Прізвище студента + його середній бал: " << endl;
    double proc = Procenti(p, N);
    cout << "2. Процент студентів, які отримали 4/5 з фізики: " << proc << "%" << endl;
    //endl;
    // << cout << proc << "%" << endl;
return 0;
}
void Create(Student* p, const int N)
{
    int spec;
    //int kurs;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
        cout << " Прізвище: ";
        getline(cin, p[i].prizv);
        cout << " Курс : "; cin >> p[i].kurs;
        cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> spec;
        cout << " Оцінка з фізики : "; cin >> p[i].fiz;
        cout << " Оцінка з математики : "; cin >> p[i].mat;
        cout << " Оцінка з інформатики : "; cin >> p[i].inf;
        p[i].spec = (Spec)spec;
    }
}

void Print(Student* p, const int N)
{
    cout << "======================================================================================================="
        << endl;
    cout << "| № | Прізвище | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з інформатики |"
        << endl;
    cout << "-------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << i + 1;
        cout << "| " << setw(9) << p[i].prizv;
        cout << "| " << setw(5) << p[i].kurs;
        cout << "| " << setw(14) << specStr[p[i].spec];
        cout << "| " << setw(16) << p[i].fiz;
        cout << "| " << setw(20) << p[i].mat;
        cout << "| " << setw(21) << p[i].inf << "|";
        cout << endl;
    }
    cout << "======================================================================================================="
        << endl;
    cout << endl;
}

void DisplayAverageGrades(Student *p, const int N)
{
   // int sum = 0;
    for (int i = 0; i < N; i++)
    {
        float grade = static_cast<float>(p[i].fiz + p[i].mat + p[i].inf) / 3;
        
        cout << "1. Прізвище студента: " << p[i].prizv << ";" << " середній бал: " << grade << endl;
    }
}
double Procenti(Student *p, const int N) {
//    cout << "Прізвища студентів, які отримали з фізики 4/5:" << endl;
    int k=0;
    for (int i=0; i<N; i++)
    {
        if (p[i].fiz == 4 || p[i].fiz == 5)
        {
            k++;
//            cout << setw(3) << right << k
//            << " " << p[i].prizv << endl;
        }

    }
  return 100.0*k/N;
}
