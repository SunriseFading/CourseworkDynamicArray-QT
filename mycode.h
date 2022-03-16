#ifndef MYCODE_H
#define MYCODE_H


#include <QString>
#include "takeput.h"
#include "tabshow.h"
class myclass
{
public:
    myclass();
    void obr(int num);
    void write(QString filename);
    void read(QString filename);
    takeput *sa;
    tabshow *sh;

private:
};
class Employee
{
    QString type;
    QString full_name;
    QString school;
    QString gender;
    QString salary;

public:
    Employee() : full_name("Qwer A.D."), school("5"), gender("M"), salary("50000") {}
    Employee(QString type1, QString full_name1, QString school1, QString gender1, QString salary1) : type(type1), full_name(full_name1), school(school1), gender(gender1), salary(salary1) {}
    void gettype(QString &A) { A = type; }
    void setInfo(QString &A, QString &B, QString &C, QString &D)
    {
        A = full_name;
        B = school;
        C = gender;
        D = salary;
    }
    void getfull_name(QString &A) { A = full_name; }
    void getschool(QString &A) { A = school; }
    void getgender(QString &A) { A = gender; }
    void getsalary(QString &A) { A = salary; }
};
class director : public Employee
{
    QString experience_as_director;

public:
    director() : Employee(), experience_as_director("22") {}
    director(QString type1, QString full_name1, QString school1, QString gender1, QString salary1, QString experience_as_director1) : Employee(type1, full_name1, school1, gender1, salary1), experience_as_director(experience_as_director1) {}
    void Setdirector(QString &A) { A = experience_as_director; }
};
class teacher : public Employee
{
    QString subject;
    QString hours_per_week;
    QString experience_as_teacher;

public:
    teacher() : Employee(), subject("Math"), hours_per_week("20"), experience_as_teacher("20") {}
    teacher(QString type1, QString full_name1, QString school1, QString gender1, QString salary1, QString subject1, QString hours_per_week1, QString experience_as_teacher1) : Employee(type1, full_name1, school1, gender1, salary1), subject(subject1), hours_per_week(hours_per_week1), experience_as_teacher(experience_as_teacher1) {}
    void Setteacher(QString &A, QString &B, QString &C)
    {
        A = subject;
        B = hours_per_week;
        C = experience_as_teacher;
    }
};
class guard : public Employee
{
    QString days_per_week;
    QString experience_as_guard;

public:
    guard() : Employee(), days_per_week("3"), experience_as_guard("10") {}
    guard(QString type1, QString full_name1, QString school1, QString gender1, QString salary1, QString days_per_week1, QString experience_as_guard1) : Employee(type1, full_name1, school1, gender1, salary1), days_per_week(days_per_week1), experience_as_guard(experience_as_guard1) {}
    void Setguard(QString &A, QString &B)
    {
        A = days_per_week;
        B = experience_as_guard;
    }
};

#endif
