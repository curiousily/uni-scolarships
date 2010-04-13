#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

double m = 5.00;
double k = 500.00;

namespace utility
{
    namespace output
    {

        void Write(const char * line, ostream & outputStream)
        {
            outputStream << line;
        }

        void Write(const char * line)
        {
            Write(line, cout);
        }

        void WriteLine(const char * line, ostream & outputStream, const char * format = "", ...)
        {
            Write(line, outputStream);
            va_list argumentList;
            va_start(argumentList, format);
            for (int i = 0; format[i] != '\0'; i++)
            {
                if (format[i] == 'i')
                {
                    cout << va_arg(argumentList, int);
                }
                else if (format[i] == 's')
                {
                    cout << va_arg(argumentList, char *);
                }
            }
            va_end(argumentList);
            outputStream << endl;
        }

        void WriteLine(const char * line)
        {
            WriteLine(line, cout);
        }

        void WriteEmptyLine(ostream & outputStream)
        {
            WriteLine("", outputStream);
        }

        void WriteEmptyLine()
        {
            WriteLine("");
        }
    }

    namespace input
    {

        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue, istream & inputStream)
        {
            NumberType result;
            while (true)
            {
                inputStream >> result;
                if (inputStream && result >= minValue && result <= maxValue)
                {
                    return result;
                }
            }
        }

        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue)
        {
            return ReadNumber(minValue, maxValue, cin);
        }

        char * ReadString(const int & minLength, const int & maxLength, istream & inputStream)
        {
            char * result = new char[maxLength];
            while (true)
            {
                inputStream.getline(result, maxLength + 300);
                int resultLength = inputStream.gcount() - 1;
                if (inputStream && resultLength >= minLength && resultLength <= maxLength)
                {
                    return result;
                }
            }
        }

        char * ReadString(const int & minLength, const int & maxLength)
        {
            return ReadString(minLength, maxLength, cin);
        }

    }
}

namespace scolarships
{

    namespace students
    {

        struct Student
        {
            int number;
            char * name;
            double averageGrade;
            double averageIncome;
        };

        char * GetAbbreviatedStudentName(Student * student, int length)
        {
            char * result = new char[length];
            char * temp = strtok(student->name , " ");
            char * firstAndSurName = new char[5];

            int spaceCount = 0;
            while(temp != NULL)
            {
                if(spaceCount < 2)
                {
                    strncat(firstAndSurName, temp, 1);
                    strcat(firstAndSurName, ".");
                }
                else
                {
                    firstAndSurName[4] = '\0';
                    strcat(result, temp);
                    strcat(result, " ");
                    strcat(result, firstAndSurName);
                }
                temp = strtok(NULL, " ");
                spaceCount++;
            }
            return result;
        }

        int GetStudentScolarship(Student * student)
        {
            if(student->averageGrade >= 5.50)
            {
                return 100;
            }
            else if(student->averageGrade >= m && student->averageIncome < k)
            {
                return 60;
            }
            else
            {
                return 0;
            }
        }

        namespace List
        {

            struct Node
            {
                Node * next;
                Student * element;

                Node()
                {
                    next = NULL;
                    element = NULL;
                }

                ~Node()
                {
                    delete element;
                }
            };

            int studentCount;
            Node * head = NULL;
            Node * tail = NULL;

            void Create()
            {
                elementCount = 0;
            }

            void Destroy()
            {
                Node * nodeToDelete = head;
                while (nodeToDelete != NULL)
                {
                    Node * temp = nodeToDelete;
                    nodeToDelete = nodeToDelete->next;
                    delete temp;
                }
                studentCount = 0;
            }

            void Add(Student * student)
            {
                Node * newNode = new Node;
                newNode->element = student;
                if (head == NULL)
                {
                    head = tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = tail->next;
                }
                studentCount++;
            }

            int Size()
            {
                return studentCount;
            }

            bool IsEmpty()
            {
                return studentCount == 0;
            }

            void Sort( int (*CmpFunc)(Student, Student) )
            {

            }

            void Map(void (*CallbackFunc) (Student*))
            {
                Node * node = head;
                while (node != NULL)
                {
                    CallbackFunc(node->element);
                    node = node->next;
                }
            }
        }
    }
}


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
         << GetStudentAbbreviatedName(student, 50) << " "
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
    cout << student->name << " " << GetStudentScolarship(student) << endl;
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
