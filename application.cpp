#include <cstring>

#include "application.h"

#include "output.h"
#include "input.h"
#include "Student.h"
#include "list.h"

double highestIncome = 0.00;
double lowestGrade = 0.00;

using namespace utility::input;
using namespace utility::output;

using namespace scolarships::students;
using namespace scolarships::students::List;

Student * ReadStudent(const int & number)
{
    WriteLine("You are entering information for student #", cout, "i", number);
    Student * student = new Student;

    student->number = number;

    Write("three names delimited by space (between 10 and 50 characters) : ");
    student->name = ReadString(10, 50);
    WriteEmptyLine();

    Write("average grade (between 3.00 and 6.00) : ");
    student->averageGrade = ReadNumber(3.00, 6.00);
    WriteEmptyLine();

    Write("average family income (between 1.00 and 999.999) : ");
    student->averageIncome = ReadNumber(1.00, 999.99);
    WriteEmptyLine();
    return student;
}

void InitializeStudentList()
{
    Write("Please enter the number of students that are competing for scolarships : ");
    int numberOfStudents = ReadNumber(10, 500);
    List::Create(numberOfStudents);
    for (int i = 0; i < numberOfStudents; i++)
    {
        int number = i + 1;
        List::Add(ReadStudent(number));
    }
}

void PrintStudent(Student * student)
{
    cout << student->number << " "
    << GetAbbreviatedStudentName(student, 50) << " "
    << student->averageGrade << " "
    << student->averageIncome << endl;
}

void PrintStudentScolarshipInfo(Student * student)
{
    cout << student->name << " " << GetStudentScolarship(student, lowestGrade, highestIncome) << endl;
}

int StudentNumberComparator(Student * student1, Student * student2)
{
    if (student1->number > student2->number)
    {
        return 1;
    }
    else if (student1->number < student2->number)
    {
        return -1;
    }
    return 0;
}

int StudentComplexComparator(Student * student1, Student * student2)
{
    if (student1->averageGrade > student2->averageGrade)
    {
        return -1;
    }
    else if (student1->averageGrade < student2->averageGrade)
    {
        return 1;
    }
    else
    {
        if (student1->averageIncome > student2->averageIncome)
        {
            return 1;
        }
        else if (student1->averageIncome > student2->averageIncome)
        {
            return -1;
        }
        else
        {
            return StudentNumberComparator(student1, student2);
        }
    }
}

void DisplayStudentList()
{
    WriteLine("Student list");
    WriteEmptyLine();
    List::Sort(StudentNumberComparator);
    List::Map(PrintStudent);
}

void DisplayStudentStanding()
{
    WriteLine("Student standing");
    WriteEmptyLine();
    List::Sort(StudentComplexComparator);
    List::Map(PrintStudentScolarshipInfo);
}

void ReadScolarshipConstraints()
{
    WriteLine("Please enter some scolarship constraints");
    WriteLine("highest income (between 1.00 and 999.99) : ");
    highestIncome = ReadNumber(1.00, 999.99);
    WriteLine("lowest grade (between 3.00 and 5.49) : ");
    lowestGrade = ReadNumber(3.00, 5.49);
    WriteEmptyLine();
}

void scolarships::InitializeApp()
{
    WriteLine("Welcome to the virtual scolarship list program!");
    WriteEmptyLine();
}

void scolarships::ExitApp()
{
    WriteLine("Bye bye!");
    List::Destroy();
}

void scolarships::RunApp()
{
    InitializeApp();

    InitializeStudentList();
    DisplayStudentList();
    ReadScolarshipConstraints();
    DisplayStudentStanding();

    ExitApp();
}

void scolarships::TestApp()
{
    List::Create(10);

    List::Add(CreateStudent(1, "ivan slavov slakov", 5.00, 540.00));
    List::Add(CreateStudent(4, "liliq kareva vekova", 6.00, 450.00));
    List::Add(CreateStudent(3, "minko ivanov petrov", 4.00, 200.00));
    List::Add(CreateStudent(5, "teodora filipova velikova", 3.60, 900.00));
    List::Add(CreateStudent(2, "kiril demqnov kirkov", 5.50, 680.00));
    List::Add(CreateStudent(6, "petur blagoev sirkov", 4.20, 200.00));

    DisplayStudentList();

    highestIncome = 600.00;
    lowestGrade = 4.50;

    WriteEmptyLine();

    DisplayStudentStanding();
}
