#include "output.h"
#include <stdarg.h>

using namespace std;

void utility::output::Write(const char * line, ostream & outputStream)
{
    outputStream << line;
}

void utility::output::Write(const char * line)
{
    Write(line, cout);
}

void utility::output::WriteLine(const char * line, ostream & outputStream, const char * format, ...)
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

void utility::output::WriteLine(const char * line)
{
    WriteLine(line, cout);
}

void utility::output::WriteEmptyLine(ostream & outputStream)
{
    WriteLine("", outputStream);
}

void utility::output::WriteEmptyLine()
{
    WriteLine("");
}

