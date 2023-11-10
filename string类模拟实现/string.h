#pragma once

#include <iostream>
#include <string.h>

typedef char* iterator;

namespace my_string
{
    class string
    {
    public:
        string(const char* str = "");
        string(const string& s);
        ~string();
        iterator begin();
        iterator end();
        void push_back(char c);
        string& operator=(const string& s);
        void append(const char* str);
        string& operator+=(char c);
        string& operator+=(const char* str);
        void clear();
        void swap(string& s);
        const char* c_str()const;
        size_t size()const;
        size_t capacity()const;
        bool empty()const;
        void resize(size_t n, char c = '\0');
        void reserve(size_t n);
        char& operator[](size_t index);
        const char& operator[](size_t index)const;
        bool operator<(const string& s);
        bool operator<=(const string& s);
        bool operator>(const string& s);
        bool operator>=(const string& s);
        bool operator==(const string& s);
        bool operator!=(const string& s);
        size_t find(char c, size_t pos = 0) const;
        size_t find(const char* s, size_t pos = 0) const;
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);
        string& erase(size_t pos, size_t len);
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    public:
        const static size_t npos;
    };
}
