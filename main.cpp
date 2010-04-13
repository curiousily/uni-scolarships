#include "output.h"
#include "input.h"
#include "Student.h"
#include "list.h"

double m = 5.00;
double k = 500.00;


using namespace scolarships::students;

using namespace scolarships::students::List;

using namespace utility::input;
using namespace utility::output;


void InitializeStudentList()
{
    Write("Please enter the number of students that are competing for scolarships : ");
    int numberOfStudents = ReadNumber(10, 500);

    Student * student;
    for (int i = 0; i < numberOfStudents; i++)
    {
        int number = i + 1;
        WriteLine("You are entering information for student #", cout, "i", number);
        student = new Student;

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

        List::Add(student);
    }

}

void PrintStudent(Student * student)
{
    cout << student->number << " "
         << GetAbbreviatedStudentName(student, 50) << " "
         << student->averageGrade << " "
         << student->averageIncome << endl;
}

int StudentNumberComparator(Student * student1, Student * student2)
{
    if(student1->number > student2->number)
    {
        return 1;
    }
    else if(student1->number < student2->number)
    {
        return -1;
    }
    return 0;
}

int StudentComplexComparator(Student * student1, Student * student2)
{
    if(student1->averageGrade > student2->averageGrade)
    {
        return -1;
    }
    else if(student1->averageGrade < student2->averageGrade)
    {
        return 1;
    }
    else
    {
        if(student1->averageIncome > student2->averageIncome)
        {
            return 1;
        }
        else if(student1->averageIncome > student2->averageIncome)
        {
            return -1;
        }
        else
        {
            return StudentNumberComparator(student1, student2);
        }
    }
}

void PrintStudentScolarshipInfo(Student * student)
{
    cout << student->name << " " << GetStudentScolarship(student, m, k) << endl;
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

void InitializeApp()
{
    List::Create();
}

void ExitApp()
{
    List::Destroy();
}

int main()
{
    InitializeApp();

    WriteLine("Welcome to the virtual scolarship list program!");
    WriteEmptyLine();

    InitializeStudentList();
    DisplayStudentList();
    DisplayStudentStanding();

    WriteLine("Bye bye!");

    ExitApp();

    return 0;
}
