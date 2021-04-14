#ifndef SSCPP2014_STRING_H
#define SSCPP2014_STRING_H
 
#include <iostream>
#include <cstring>
 
class String {
  private:
    char *_buff;
    int _length, _size;  // _size is of the allocated memory
 
  public:
    // constructors
    String();
    explicit String(const char *src);
    String(const String &src);
    // destructor
    ~String();
    // member methods
    void assign(const char *src);
    void append(const char &other);
    void clear();
    int compare(const String &other) const;
    const char* c_str() const;
    bool empty() const;
    int find(const String &other, int pos = 0) const;
    int length() const;
    String substr(const int &pos, const int &count) const;
    // overload operators
    char& operator[](const int &index);
    void operator=(const String &other);
    void operator=(const char *src);
    String operator+(const String &other) const;
    bool operator<(const String &other) const;
    bool operator<=(const String &other) const;
    bool operator>(const String &other) const;
    bool operator>=(const String &other) const;
    bool operator==(const String &other) const;
    bool operator!=(const String &other) const;
    // friend methods
    friend std::ostream& operator<<(std::ostream& out, const String &str);
    // non-meaning static property
    static char _error_sign;  // initial as any char is okay
};
String::String() {_length=0;_size=0;_buff=NULL;}
String::String(const char *src)
{
    auto len=strlen(src);
    _buff=new char[len+1];
    strcpy(_buff,src);
    _buff[len]=0;
    _size=len+1;
    _length=len;
}
String::String(const String &src)
{
    clear();
    _size=src._size;
    _length=src._length;
    _buff=new char[_size];
    strcpy(_buff,src._buff);
    _buff[_length]=0;
}
// destructor
String::~String()
{
    delete _buff;
}
    // member methods
void String::assign(const char *src)
{
    clear();
    _length=strlen(src);
    _size=_length+1;
    _buff=new char[_size];
    strcpy(_buff,src);
    _buff[_length]=0;
}
void String::append(const char &other)
{
    if(_size<_length+2)
    {
        _size=_length+2;
        auto temp=_buff;
        _buff=new char[_size];
        if(temp)
        strcpy(_buff,temp);
        delete temp;
    }
    _buff[_length++]=other;
    _buff[_length]=0;
}
void String::clear()
{
    if(_buff)
    delete _buff;
    _buff=NULL;
    _size=0;
    _length=0;
}
int String::compare(const String &other) const
{
    auto an=strcmp(_buff,other._buff);
    if(an>0)
    return 1;
    else if(an<0)
    return -1;
    else 
    return 0;
}
const char *String::c_str() const
{
    return _buff;
}
bool String::empty() const
{
    return _length==0;
}
int String::find(const String &other, int pos ) const
{
    auto ch=other.c_str();

    for(int i=pos;i<_length;i++)
    {
        if(_buff[i]==*ch)
        {
            bool is=true;
            for (int j=1,m=i+1;j<other._length;j++,m++)
            {
                if(_buff[m]!=ch[j])
                {
                    is=false;
                    break;
                }
            }
            if(is)
            return i;
        }
    }
    return _length;
}
int String::length() const { return _length; }
String String::substr(const int &pos, const int &count) const 
{
    char temp[_length];
    strncpy(temp,_buff+pos,count);
    temp[count]=0;
    return String(temp);
}
// overload operators
char &String::operator[](const int &index)
{
    return _buff[index];
}
void String::operator=(const String &other)
{
    clear();
    _size=other._size;
    _length=other._length;
    delete []_buff;
    _buff=new char[_size];
    strcpy(_buff,other._buff);
    _buff[_length]=0;
}
void String::operator=(const char *src)
{
    _size=strlen(src)+1;
    _length=_size-1;
    _buff=new char[_size];
    strcpy(_buff,src);
    _buff[_length]=0;
}
String String::operator+(const String &other) const
{
    auto size=_size+other._size;
    auto len=_length+other._length;
    char temp[size];
    memset(temp,0,sizeof(char)*size);
    strcat(temp,_buff);
    strcat(temp,other._buff);
    return String(temp);
}
bool String::operator<(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re==0 || re>0)
    return false;
    else
    return true;
}
bool String::operator<=(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re>0)
    return false;
    else
    return true;

}
bool String::operator>(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re<0 || re==0)
    return false;
    else
    return true;

}

bool String::operator>=(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re<0)
    return false;
    else
    return true;

}
bool String::operator==(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re!=0)
    return false;
    else
    return true;

}
bool String::operator!=(const String &other) const
{
    auto re=strcmp(_buff,other._buff);
    if(re==0)
    return false;
    else
    return true;
}
// friend methods
std::ostream &operator<<(std::ostream &out, const String &str)
{
    if(str._buff)
    out<<str.c_str();
    return out;
}
#endif