#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/* Класс для подготовки данных для записи в базу данных (саму БД писать не нужно) информационной системы ВУЗа.
 * Рассмотреть наличие следующих категорий: обучающийся, сотрудник, преподаватель, выпускник с соответсвующей необходимой информацией
 * (для обучающихся — оценки, преподаватель — ученое звание, выпускник — год выпуска, сотрудник — подразделение (лабы, охрана, АХК, администрация),
 * и т. п. - насколько фантазии хватит). Учесть что список в дальнейшем может быть расширяемым*/

class Human
{
private:
    string name;
    string surname;
    string last_name;
    int age;
public:
    Human(string Name, string Surname, string LastName, int Age)
    {
        name = Name;
        surname = Surname;
        last_name = LastName;
        age = Age;
    }
    string main_information()
    {
        stringstream ss;
        ss << age;
        string age_str = ss.str();
        string output = "main information: " + surname + " " + name + " " + last_name + " " + age_str + " years\n";
        return output;
    }
    string full_information()
    {
        return main_information();
    }
};

class Student: public Human
{
private:
    vector<int> scores;
    int course;
    int group;
    string direction;
public:
    Student(string surname, string name, string last_name, int age, vector<int> Scores, int Course, int Group, string Direction):
        Human(surname, name, last_name, age)
    {
        scores = Scores;
        course = Course;
        group = Group;
        direction = Direction;
    }

    float GPA()
    {
        int score_sum = 0;
        for (unsigned int i = 0; i < scores.size(); ++i)
            score_sum += scores[i];
        return float(score_sum)/float(scores.size());
    }
    string student_information()
    {
        stringstream ss;
        ss << course << "th course, " << group << "group, direction: " << direction << ", GPA: " << GPA() << "\n";
        return ss.str();
    }
    string full_information()
    {
        return main_information() + student_information();
    }
};

class Employee: public Human
{
private:
    string profession;
    int experience;
    int salary;
public:
    Employee(string surname, string name, string last_name, int age, string Profession, int Experience, int Salary):
        Human(surname, name, last_name, age)
    {
        experience = Experience;
        salary = Salary;
        profession = Profession;
    }
    string employee_information()
    {
        stringstream ss, pp;
        ss << experience;
        pp << salary;
        string output = "profession: " + profession + ", experience: " + ss.str() + " years, salary: " + pp.str() + " convertional units\n";
        return output;
    }
    string full_information()
    {
        return main_information() + employee_information();
    }
};

class Teacher: public Employee
{
private:
    string department;
    string academic_status;
public:
    Teacher(string surname, string name, string last_name, int age, int experience, int salary, string profession, string Department, string AcademicStatus):
        Employee(surname, name, last_name, age, profession, experience, salary)
    {
        department = Department;
        academic_status = AcademicStatus;
    }
    string teacher_information()
    {
        string output = "department: " + department + ", academic status: " + academic_status + "\n";
        return output;
    }
    string full_information()
    {
        return Employee::full_information() + teacher_information();
    }
};

class Graduate: public Human
{
private:
    int year_graduate;
    bool participation;
public:
    Graduate(string surname, string name, string last_name, int age, int Year, bool Part):
        Human(surname, name, last_name, age)
    {
        year_graduate = Year;
        participation = Part;
    }
    string graduate_information()
    {
        string partic;
        if (participation)
            partic = "participates in university life";
        else
            partic = "does not participate in university life";
        stringstream ss;
        ss << year_graduate;
        string output = "year of graduation: " + ss.str() + ", " + partic + "\n";
        return output;
    }
    string full_information()
    {
        return main_information() + graduate_information();
    }
};

int main()
{
    vector<int> grads = {8,7,10,6,6,9,9,6,10,6,8,9};
    Student Me = Student("Ksenia", "Varlamova", "Dmitrievna", 20, grads, 3, 13, "CSE");
    cout << Me.main_information() << Me.student_information();

    Teacher Best = Teacher("Sergey", "Zhivotov", "Dmitrievich", 47, 20, 1000000, "teacher", "Higher Maths", "Candidate of Ph_M Sciences");
    cout << Best.full_information();
    return 0;
}
