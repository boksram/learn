#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

my_string::string::string(const char* str)
	:_capacity(strlen(str))
	, _size(_capacity)
{
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

my_string::string::string(const string& s)
	:_capacity(s._capacity)
	,_size(s._size)
{
	_str = new char[_capacity + 1];
	strcpy(_str, s._str);
}

my_string::string::~string()
{
	_capacity = 0;
	_size = 0;
	delete[] _str;
	_str = nullptr;
}

iterator my_string::string::begin()
{
	return _str;
}

iterator my_string::string::end()
{
	return _str + _size;
}

void my_string::string::push_back(char c)
{
	if (_size == _capacity)
		reserve(_capacity == 0 ? 4 : 2 * _capacity);
	_str[_size++] = c;
	_str[_size] = '\0';
}

my_string::string& my_string::string::operator+=(char c)
{
	push_back(c);
	return *this;
}

my_string::string& my_string::string::operator+=(const char* str)
{
	append(str);
	return *this;
}

my_string::string& my_string::string::operator=(const string& s)
{
	_size = s._size;
	_capacity = s._capacity;
	reserve(_capacity + 1);
	strcpy(_str, s._str);
	return *this;
}

void my_string::string::append(const char* str)
{
	if (_capacity < _size + strlen(str))
		reserve(_size + strlen(str));
	strcpy(_str + _size, str);
	_size += strlen(str);
}

void my_string::string::clear()
{
	_size = 0;
	_capacity = 0;
}

void my_string::string::swap(string& s)
{
	std::swap(_str, s._str);
	std::swap(_capacity, s._capacity);
	std::swap(_size, s._size);
}

void my_string::string::reserve(size_t n)
{
	if (n > _capacity)
	{
		char* p = new char[n + 1];
		strcpy(p, _str);
		delete[] _str;
		_str = p;
		_capacity = n;
	}
}

const char* my_string::string::c_str() const
{
	return _str;
}

size_t my_string::string::size() const
{
	return _size;
}

size_t my_string::string::capacity() const
{
	return _capacity;
}

bool my_string::string::empty() const
{
	return _size == 0;
}

void my_string::string::resize(size_t n, char c)
{
	if (n > _size)
	{
		reserve(n);
		int i = _size;
		while (_size < n)
		{
			_str[_size++] = c;
		}
		_str[_size] = '\0';
	}
	else
	{
		while (_size >= n)
		{
			_str[_size--] = '\0';
		}
	}
}

char& my_string::string::operator[](size_t index)
{
	return _str[index];
}

const char& my_string::string::operator[](size_t index) const
{
	return _str[index];
}

bool my_string::string::operator<(const string& s)
{
	return strcmp(_str, s._str) < 0;
}

bool my_string::string::operator<=(const string& s)
{
	return strcmp(_str, s._str) <= 0;
}

bool my_string::string::operator>(const string& s)
{
	return strcmp(_str, s._str) > 0;
}

bool my_string::string::operator>=(const string& s)
{
	return strcmp(_str, s._str) >= 0;
}

bool my_string::string::operator==(const string& s)
{
	return strcmp(_str, s._str) == 0;
}

bool my_string::string::operator!=(const string& s)
{
	return strcmp(_str, s._str) != 0;
}

size_t my_string::string::find(char c, size_t pos) const
{
	while (pos <= _size)
	{
		if (_str[pos] == c)
			break;
		pos++;
	}
	if (pos <= _size)
		return pos;
	else
		return npos;
}

size_t my_string::string::find(const char* s, size_t pos) const
{
	const char* p = strstr(_str + pos, s);
	if (p)
		return p - _str;
	else
		return npos;
}

my_string::string& my_string::string::insert(size_t pos, char c)
{
	if (_size == _capacity)
		reserve(_capacity + 1);
	int i = _size;
	while (i >= (int)pos)
	{
		_str[i + 1] = _str[i];
		--i;
	}
	_str[pos] = c;
	_size += 1;
	return *this;
}

my_string::string& my_string::string::insert(size_t pos, const char* str)
{
	if (_capacity < _size + strlen(str))
		reserve(_size + strlen(str));
	int i = _size;
	while (i >= (int)pos)
	{
		_str[i + strlen(str)] = _str[i];
		i--;
	}
	strncpy(_str + pos, str, strlen(str));
	_size += strlen(str);
	return *this;
}

my_string::string& my_string::string::erase(size_t pos, size_t len)
{
	int i = pos + len;
	while (i <= (int)_size)
	{
		_str[i - len] = _str[i];
		++i;
	}
	_size -= len;
	return *this;
}
