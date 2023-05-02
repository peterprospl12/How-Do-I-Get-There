#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class BasicString {
public:
    char* str;
public:
    BasicString();
    BasicString(char* orig);
    BasicString(const char* orig);
    BasicString(const BasicString& cpy);
    BasicString(BasicString&& cpy);
    BasicString& operator=(const BasicString& right);
    BasicString& operator=(const char* right);
    BasicString& operator=(BasicString&& right) noexcept;


    friend std::ostream& operator<<(std::ostream& os, const BasicString& orig);
    friend std::istream& operator>>(std::istream& is, BasicString& orig);
    bool operator==(const BasicString& str2);
    bool operator!=(const BasicString& str2);
    BasicString operator+(const BasicString& orig) const;
    BasicString& operator+=(const BasicString& orig);



    ~BasicString();
};