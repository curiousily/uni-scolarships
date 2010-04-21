#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <iostream>

using namespace std;

namespace utility
{
    namespace input
    {
        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue, istream & inputStream);

        template <class NumberType>
        NumberType ReadNumber(const NumberType & minValue, const NumberType & maxValue);

        char * ReadString(const int & minLength, const int & maxLength, istream & inputStream);

        char * ReadString(const int & minLength, const int & maxLength);
    }
}

template <class NumberType>
NumberType utility::input::ReadNumber(const NumberType & minValue, const NumberType & maxValue, istream & inputStream)
{
    NumberType result;
    int run = 0;
    while (true)
    {
        inputStream >> result;
        if (inputStream && result >= minValue && result <= maxValue)
        {
            return result;
        }
        if (run > 0)
        {
            cout << "Invalid number supplied expected between " << minValue << " and " << maxValue << endl;
            cout << "try again : ";
        }
        run++;
    }
}

template <class NumberType>
NumberType utility::input::ReadNumber(const NumberType & minValue, const NumberType & maxValue)
{
    return ReadNumber(minValue, maxValue, cin);
}

char * utility::input::ReadString(const int & minLength, const int & maxLength, istream & inputStream)
{
    char * result;
    int run = 0;
    while (true)
    {
        char buffer[200];
        inputStream.getline(buffer, 200);
        int resultLength = inputStream.gcount() - 1;
        if (inputStream && resultLength >= minLength && resultLength <= maxLength)
        {
            result = new char[resultLength + 1];
            strcpy(result, buffer);
            return result;
        }
        if (run > 0)
        {
            cout << "Invalid string supplied expected length between " << minLength << " and " << maxLength << endl;
            cout << "try again : ";
        }
        run++;
    }
}

char * utility::input::ReadString(const int & minLength, const int & maxLength)
{
    return ReadString(minLength, maxLength, cin);
}


#endif // INPUT_H_INCLUDED
