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
NumberType utility::input::ReadNumber(const NumberType & minValue, const NumberType & maxValue)
{
    return ReadNumber(minValue, maxValue, cin);
}

char * utility::input::ReadString(const int & minLength, const int & maxLength, istream & inputStream)
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

char * utility::input::ReadString(const int & minLength, const int & maxLength)
{
    return ReadString(minLength, maxLength, cin);
}


#endif // INPUT_H_INCLUDED
