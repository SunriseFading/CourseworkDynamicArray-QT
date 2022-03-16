#include "mycode.h"
#include "adddirector.h"
#include "addteacher.h"
#include "addguard.h"
#include "delemployee.h"
#include "editdirector.h"
#include "editguard.h"
#include "search_employee.h"
#include "takeput.h"
#include "editteacher.h"
#include "editguard.h"
#include "mainwindow.h"
#include <locale.h>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
using namespace std;
myclass::myclass()
{
}
int n = 0, directors = 0, teachers = 0, guards = 0;
QString sohr = "", otkr = "";
Employee **mas = new Employee *[0];
void myclass::write(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        for (int i = 0; i < n; i++)
        {
            QString type;
            mas[i]->gettype(type);
            if (type == "D")
            {
                QString A, B, C, D, E;
                mas[i]->setInfo(A, B, C, D);
                ((director *)mas[i])->Setdirector(E);
                out << type << endl;
                out << A << endl;
                out << B << endl;
                out << C << endl;
                out << D << endl;
                out << E << endl;
            }
            else if (type == "T")
            {
                QString A, B, C, D, E1, E2, E3;
                mas[i]->setInfo(A, B, C, D);
                ((teacher *)mas[i])->Setteacher(E1, E2, E3);
                out << type << endl;
                out << A << endl;
                out << B << endl;
                out << C << endl;
                out << D << endl;
                out << E1 << endl;
                out << E2 << endl;
                out << E3 << endl;
            }
            else
            {
                QString A, B, C, D, E, E1;
                mas[i]->setInfo(A, B, C, D);
                ((guard *)mas[i])->Setguard(E, E1);
                out << type << endl;
                out << A << endl;
                out << B << endl;
                out << C << endl;
                out << D << endl;
                out << E << endl;
                out << E1 << endl;
            }
        }
    }
    else
        qWarning("Не удалось открыть файл");
    file.close();
}
void myclass::read(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString type = in.readLine();
            if (type == "D")
            {
                QString A, B, C, D, E;
                A = in.readLine();
                B = in.readLine();
                C = in.readLine();
                D = in.readLine();
                E = in.readLine();
                n++;
                directors++;
                Employee **P = new Employee *[n];
                for (int i = 0; i < n; i++)
                {
                    P[i] = mas[i];
                }
                delete[] mas;
                mas = P;
                mas[n - 1] = new director(type, A, B, C, D, E);
            }
            else if (type == "T")
            {
                QString A, B, C, D, E1, E2, E3;
                A = in.readLine();
                B = in.readLine();
                C = in.readLine();
                D = in.readLine();
                E1 = in.readLine();
                E2 = in.readLine();
                E3 = in.readLine();
                n++;
                teachers++;
                Employee **P = new Employee *[n];
                for (int i = 0; i < n; i++)
                {
                    P[i] = mas[i];
                }
                delete[] mas;
                mas = P;
                mas[n - 1] = new teacher(type, A, B, C, D, E1, E2, E3);
            }
            else
            {
                QString A, B, C, D, E, E1;
                A = in.readLine();
                B = in.readLine();
                C = in.readLine();
                D = in.readLine();
                E = in.readLine();
                E1 = in.readLine();
                n++;
                guards++;
                Employee **P = new Employee *[n];
                for (int i = 0; i < n; i++)
                {
                    P[i] = mas[i];
                }
                delete[] mas;
                mas = P;
                mas[n - 1] = new guard(type, A, B, C, D, E, E1);
            }
        }
        file.close();
    }
    else
        qWarning("Невозможно открыть файл для чтения!");
}
void myclass::obr(int number)
{
    int key = number;
    setlocale(LC_ALL, "RUS");
    switch (key)
    {
    case 1:
    {
        QString full_name, school, gender, salary, experience_as_director;
        QString type;
        adddirector q;
        q.exec();
        q.takedirector(full_name, school, gender, salary, experience_as_director);
        for (int i = 0; i < n; i++)
        {
            QString A, B, C, D, E, T;
            mas[i]->gettype(T);
            if (T == "D")
            {
                mas[i]->setInfo(A, B, C, D);
                ((director *)mas[i])->Setdirector(E);
            }
        }
        n++;
        directors++;
        Employee **P = new Employee *[n];
        for (int i = 0; i < n; i++)
        {
            P[i] = mas[i];
        }
        delete[] mas;
        mas = P;
        type = "D";
        mas[n - 1] = new director(type, full_name, school, gender, salary, experience_as_director);
        break;
    }
    case 2:
    {
        delemployee q;
        QString A, B, C, F;
        q.exec();
        q.deldirector(A, F);
        q.delteacher(B, F);
        q.delguard(C, F);
        int res = 0;
        int num1 = A.toInt() - 1, num2 = B.toInt() - 1, num3 = C.toInt() - 1;
        if (n > 0)
        {
            if (F == ".")
            {
                if (A != "")
                {
                    if (num1 < directors)
                    {
                        for (int i = 0; i < n - 1; i++)
                        {
                            mas[i]->gettype(A);
                            if (A == "D")
                            {
                                if (res == num1)
                                {
                                    for (int j = i; j < n - 1; j++)
                                    {
                                        mas[j] = mas[j + 1];
                                        res += 3;
                                    }
                                }
                                else
                                    res++;
                            }
                        }
                        n--;
                        directors--;
                        Employee **P = new Employee *[n];
                        for (int i = 0; i < n; i++)
                        {
                            P[i] = mas[i];
                        }
                        delete[] mas;
                        mas = P;
                    }
                }
            }
            else if (F == "..")
            {
                if (B != "")
                {
                    if (num2 < teachers)
                    {
                        for (int i = 0; i < n - 1; i++)
                        {
                            mas[i]->gettype(A);
                            if (A == "T")
                            {
                                if (res == num2)
                                {
                                    for (int j = i; j < n - 1; j++)
                                    {
                                        mas[j] = mas[j + 1];
                                        res += 3;
                                    }
                                }
                                else res++;
                            }
                        }
                        n--;
                        teachers--;
                        Employee **P = new Employee *[n];
                        for (int i = 0; i < n; i++)
                        {
                            P[i] = mas[i];
                        }
                        delete[] mas;
                        mas = P;
                    }
                }
            }
            else
            {
                if (C != "")
                {
                    if (num3 < guards)
                    {
                        for (int i = 0; i < n - 1; i++)
                        {
                            mas[i]->gettype(A);
                            if (A == "G")
                            {
                                if (res == num3)
                                {
                                    for (int j = i; j < n - 1; j++)
                                    {
                                        mas[j] = mas[j + 1];
                                        res += 3;
                                    }
                                }
                                else
                                    res++;
                            }
                        }
                        n--;
                        guards--;
                        Employee **P = new Employee *[n];
                        for (int i = 0; i < n; i++)
                        {
                            P[i] = mas[i];
                        }
                        delete[] mas;
                        mas = P;
                    }
                }
            }
        }
        break;
    }
    case 3:
    {
        editdirector e;
        QString G1;
        QString full_name, school, gender, salary, experience_as_director, num;
        e.exec();
        int res = 0;
        e.takeeditdirector(full_name, school, gender, salary,experience_as_director, num);
        int num1 = num.toInt() - 1;
        if (n > 0)
            {
                if (num1 < directors)
                {
                    for (int i = 0; i < n; i++)
                    {
                        mas[i]->gettype(G1);
                        if (G1 == "D")
                        {
                            if (res == num1)
                            {
                                mas[i] = new director(G1, full_name, school, gender, salary, experience_as_director);
                                res = 999;
                            }
                            else
                                res++;
                        }
                    }
                }
            }
        break;
    }
    case 4:
    {
        sh = new tabshow();
        QString type;
        for (int i = 0; i < n; i++)
        {
            mas[i]->gettype(type);
            if (type == "D")
            {
                QString A, B, C, D, E;
                mas[i]->setInfo(A, B, C, D);
                ((director *)mas[i])->Setdirector(E);
                sh->settab1(A, B, C, D, E);
            }
            else if (type == "T")
            {
                QString A1, B1, C1, D1, E, E1, E2;
                mas[i]->setInfo(A1, B1, C1, D1);
                ((teacher *)mas[i])->Setteacher(E, E1, E2);
                sh->settab2(A1, B1, C1, D1, E, E1, E2);
            }
            else
            {
                QString A2, B2, C2, D2, E2, E1;
                mas[i]->setInfo(A2, B2, C2, D2);
                ((guard *)mas[i])->Setguard(E2, E1);
                sh->settab3(A2, B2, C2, D2, E2, E1);
            }
        }
        sh->exec();
        sh->reset();
        break;
    }
    case 5:
    {
        search_employee q;
        sh = new tabshow();
        QString type;
        QString A, B, C, F;
        q.exec();
        q.search_get_director(A, F);
        q.search_get_teacher(B, F);
        q.search_get_guard(C, F);
        if (F == ".")
        {
            for (int i = 0; i < n; i++)
            {
                QString gender;
                mas[i]->getgender(gender);
                if (gender == A)
                {
                    mas[i]->gettype(type);
                    if (type == "D")
                    {
                        QString A, B, C, D, E;
                        mas[i]->setInfo(A, B, C, D);
                        ((director *)mas[i])->Setdirector(E);
                        sh->settab1(A, B, C, D, E);
                    }
                    else if (type == "T")
                    {
                        QString A, B, C, D, E1, E2, E3;
                        mas[i]->setInfo(A, B, C, D);
                        ((teacher *)mas[i])->Setteacher(E1, E2, E3);
                        sh->settab2(A, B, C, D, E1, E2, E3);
                    }
                    else
                    {
                        QString A, B, C, D, E, E1;
                        mas[i]->setInfo(A, B, C, D);
                        ((guard *)mas[i])->Setguard(E, E1);
                        sh->settab3(A, B, C, D, E, E1);
                    }
                }
            }
            sh->exec();
            sh->reset();
        }
        else if (F == "..")
        {
            for (int i = 0; i < n; i++)
            {
                QString school;
                mas[i]->getschool(school);
                if (school == B)
                {
                    mas[i]->gettype(type);
                    if (type == "D")
                    {
                        QString A, B, C, D, E;
                        mas[i]->setInfo(A, B, C, D);
                        ((director *)mas[i])->Setdirector(E);
                        sh->settab1(A, B, C, D, E);
                    }
                    else if (type == "T")
                    {
                        QString A, B, C, D, E1, E2, E3;
                        mas[i]->setInfo(A, B, C, D);
                        ((teacher *)mas[i])->Setteacher(E1, E2, E3);
                        sh->settab2(A, B, C, D, E1, E2, E3);
                    }
                    else
                    {
                        QString A, B, C, D, E, E1;
                        mas[i]->setInfo(A, B, C, D);
                        ((guard *)mas[i])->Setguard(E, E1);
                        sh->settab3(A, B, C, D, E, E1);
                    }
                }
            }
            sh->exec();
            sh->reset();
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                QString salary;
                mas[i]->getsalary(salary);
                if (salary == C)
                {
                    mas[i]->gettype(type);
                    if (type == "D")
                    {
                        QString A, B, C, D, E;
                        mas[i]->setInfo(A, B, C, D);
                        ((director *)mas[i])->Setdirector(E);
                        sh->settab1(A, B, C, D, E);
                    }
                    else if (type == "T")
                    {
                        QString A, B, C, D, E1, E2, E3;
                        mas[i]->setInfo(A, B, C, D);
                        ((teacher *)mas[i])->Setteacher(E1, E2, E3);
                        sh->settab2(A, B, C, D, E1, E2, E3);
                    }
                    else
                    {
                        QString A, B, C, D, E, E1;
                        mas[i]->setInfo(A, B, C, D);
                        ((guard *)mas[i])->Setguard(E, E1);
                        sh->settab3(A, B, C, D, E, E1);
                    }
                }
            }
            sh->exec();
            sh->reset();
        }
        break;
    }
    case 6:
    {
        delete[] mas;
        n = 0;
        directors = 0;
        teachers = 0;
        guards = 0;
        sohr = "";
        otkr = "";
        break;
    }
    case 7:
    {
        sa = new takeput();
        sa->exec();
        sa->taker(sohr);
        write(sohr);
        break;
    }
    case 8:
    {
        Employee **P = new Employee *[0];
        mas = P;
        n = 0;
        directors = 0;
        teachers = 0;
        guards = 0;
        sohr = "";
        otkr = "";
        sa = new takeput();
        sa->exec();
        sa->taker(otkr);
        read(otkr);
        sohr = "";
        break;
    }
    case 9:
    {
        sa = new takeput();
        if (sohr != "" || otkr != "")
        {
            if (sohr != "")
            {
                write(sohr);
            }
            else if (otkr != "")
                write(otkr);
        }
        else
        {
            sa->exec();
            sa->taker(sohr);
            write(sohr);
        }
        break;
    }

    case 13:
    {
        QString type2;
        QString full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher;
        addteacher q;
        q.exec();
        q.taketeacher(full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher);
        for (int i = 0; i < n; i++)
        {
            QString A, B, C, D, E, E1, E2, T;
            mas[i]->gettype(T);
            if (T == "T")
            {
                mas[i]->setInfo(A, B, C, D);
                ((teacher *)mas[i])->Setteacher(E, E1, E2);
            }
        }
        n++;
        teachers++;
        Employee **P = new Employee *[n];
        for (int i = 0; i < n; i++)
        {
            P[i] = mas[i];
        }
        delete[] mas;
        mas = P;
        type2 = "T";
        mas[n - 1] = new teacher(type2, full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher);
        break;
    }
    case 14:
    {
        QString type3;
        QString full_name, school, gender, salary, days_per_week, experience_as_guard;
        addguard q;
        q.exec();
        q.takeguard(full_name, school, gender, salary, days_per_week, experience_as_guard);
        for (int i = 0; i < n; i++)
        {
            QString A, B, C, D, E, E1, T;
            mas[i]->gettype(T);
            if (T == "G")
            {
                mas[i]->setInfo(A, B, C, D);
                ((guard *)mas[i])->Setguard(E, E1);
            }
        }
        n++;
        guards++;
        Employee **P = new Employee *[n];
        for (int i = 0; i < n; i++)
        {
            P[i] = mas[i];
        }
        delete[] mas;
        mas = P;
        type3 = "G";
        mas[n - 1] = new guard(type3, full_name, school, gender, salary, days_per_week, experience_as_guard);
        break;
    }
    case 15:
    {
        editteacher e;
        QString full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher, num;
        QString G1;
        e.exec();
        int res = 0;
        e.takeeditteacher(full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher, num);
        int num2 = num.toInt() - 1;
        if (n > 0)
        {
            if (num2 < teachers)
            {
                for (int i = 0; i < n; i++)
                {
                    mas[i]->gettype(G1);
                    if (G1 == "T")
                    {
                        if (res == num2)
                        {
                            mas[i] = new teacher(G1, full_name, school, gender, salary, subject, hours_per_week, experience_as_teacher);
                            res = 999;
                        }
                        else
                            res++;
                    }
                }
            }
        }
        break;
    }
    case 16:
    {
        editguard e;
        QString G1;
        QString full_name, school, gender, salary,  days_per_week, experience_as_guard, num;
        e.exec();
        int res = 0;
        e.takeeditguard(full_name, school, gender, salary, days_per_week, experience_as_guard, num);
        int num3 = num.toInt() - 1;
        if (n > 0)
        {
            if (num3 < guards)
            {
                for (int i = 0; i < n; i++)
                {
                    mas[i]->gettype(G1);
                    if (G1 == "G")
                    {
                        if (res == num3)
                        {
                            mas[i] = new guard(G1, full_name, school, gender,salary, days_per_week, experience_as_guard);
                            res = 999;
                        }
                        else
                            res++;
                    }
                }
            }
        }
        break;
    }
    }
}
