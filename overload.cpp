#include <iostream>
#include <conio.h>
using namespace std;

class CDrob
{
private:
    int n;
    int m;
public:
    CDrob() : n(1), m(1) // Конструктор без параметров
    { }

    CDrob(int n1, int m1) : n(n1) // Конструктор с параметрами
    {
        if (m1 == 0) // Если делитель равен нулю - ошибка
        {
            cout << "Error" << endl;
        }
        else
        {
            m = m1;
        }
    }

    CDrob operator * (CDrob temp) // Перегрузка операции *
    {
        CDrob buffer;
        buffer.m = m * temp.m;
        buffer.n = n * temp.n;
        return buffer;
    }

    CDrob operator / (CDrob temp) // Перегрузка операции /
    {
        CDrob buffer;
        buffer.m = m * temp.n;
        buffer.n = n * temp.m;
        return buffer;
    }

    CDrob operator = (CDrob& temp) // Перегрузка операции присваивания
    {
        n = temp.n;
        m = temp.m;
        return CDrob(n, m);
    }

    bool operator==(const CDrob& right) // Перегрузка операции проверки на равенство
    {
        return n * right.m == m * right.n;
    }

    friend ostream& operator << (ostream& s, CDrob& temp); // Вывод самой дроби
};

ostream& operator << (ostream& s, CDrob& temp)
{
    s << temp.n << "/" << temp.m;
    return s;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    CDrob drob1(2, 3);
    CDrob drob2(2, 3);

    if (drob1 == drob2)
        cout << "Дроби равны" << endl;
    else
        cout << "Дроби не равны" << endl;


    system("pause");
    return 0;
}