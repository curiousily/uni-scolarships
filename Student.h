#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

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

        char * GetAbbreviatedStudentName(Student * student,const int & length);

        int GetStudentScolarship(Student * student, const int & lowestGrade, const int & highestIncome);

        Student * CreateStudent(int number, char name[], double averageGrade, double averageIncome);

    }

}

#endif // STUDENT_H_INCLUDED
