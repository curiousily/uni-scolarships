#include <string.h>

#include "Student.h"

char * scolarships::students::GetAbbreviatedStudentName(Student * student, const int & length)
{
    char * result = new char[length];
    char * temp = new char[length];
    temp = strcpy(temp, student->name);
    temp = strtok(temp , " ");
    char * firstAndSurName = new char[5];

    int spaceCount = 0;
    while (temp != NULL)
    {
        if (spaceCount < 2)
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

int scolarships::students::GetStudentScolarship(Student * student, const int & lowestGrade, const int & highestIncome)
{
    if (student->averageGrade >= 5.50)
    {
        return 100;
    }
    else if (student->averageGrade >= lowestGrade && student->averageIncome < highestIncome)
    {
        return 60;
    }
    else
    {
        return 0;
    }
}

scolarships::students::Student * scolarships::students::CreateStudent(int number, char name[], double averageGrade, double averageIncome)
{
    Student * student = new Student;
    student->number = number;
    student->name = new char[50];
    strcpy(student->name, name);
    student->averageGrade = averageGrade;
    student->averageIncome = averageIncome;
    return student;
}
