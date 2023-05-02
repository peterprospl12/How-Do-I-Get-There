#include "BasicString.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>


BasicString::BasicString()
    :str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

BasicString::BasicString(char* orig) {
    str = new char[strlen(orig) + 1];
    strcpy(str, orig);
    str[strlen(orig)] = '\0';
}

BasicString::BasicString(const char* orig) {    
    str = new char[strlen(orig) + 1];
    strcpy(str, orig);
    str[strlen(orig)] = '\0';
}

BasicString::BasicString(const BasicString& cpy) {
    str = new char[strlen(cpy.str) + 1];
    strcpy(str, cpy.str);
    str[strlen(cpy.str)] = '\0';
}

BasicString::BasicString(BasicString&& cpy)
    :str(cpy.str) {
    cpy.str = nullptr;
}

BasicString& BasicString::operator=(const BasicString& right) {
    if (this == &right) {
        return *this;
    }
    delete[] str;
    str = new char[strlen(right.str) + 1];
    strcpy(str, right.str);
    str[strlen(right.str)] = '\0';
    return *this;
}


BasicString& BasicString::operator=(const char* right) {

    delete[] str;
    str = new char[strlen(right) + 1];
    strcpy(str, right);
    str[strlen(right)] = '\0';
    return *this;
}



BasicString& BasicString::operator=(BasicString&& right) noexcept
{
    delete[] str;
    str = right.str;
    right.str = nullptr;
    return *this;
}

bool BasicString::operator==(const BasicString& str2) {
    return !strcmp(str, str2.str);
}

bool BasicString::operator!=(const BasicString& str2) {
    return strcmp(str, str2.str);
}

std::ostream& operator<<(std::ostream& os, const BasicString& orig) {
    os << orig.str;
    return os;
}


std::istream& operator>>(std::istream& is, BasicString& orig) {
    char* str = new char[200];

    is >> str;

    orig = BasicString(str);
    delete[] str;
    return is;
}



BasicString BasicString::operator+(const BasicString& orig) const {
    int len1 = strlen(str);
    int len2 = strlen(orig.str);
    char* newStr = new char[len1 + len2 + 1];
    strcpy(newStr, str);
    strcpy(newStr + len1, orig.str);
    BasicString result(newStr);
    delete[] newStr;
    return result;
}

BasicString& BasicString::operator+=(const BasicString& orig) {
    int len1 = strlen(str);
    int len2 = strlen(orig.str);
    char* newStr = new char[len1 + len2 + 2];
    strcpy(newStr, str);
    newStr[len1] = ' ';
    newStr[len1 + 1] = '\0';
    strcpy(newStr + len1 + 1, orig.str);
    BasicString result(newStr);
    delete[] newStr;
    *this = result;
    return *this;
}



BasicString::~BasicString() {
    delete[] str;
}