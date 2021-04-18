#ifndef BITSET_H
#define BITSET_H
#include<iostream>
#include<cstring>
#define N 5
const int max_length = 32 * N;
class bitset {
    private:
        int a[N];
    public:
        bitset();
        void set(int pos);
        void reset(int pos);
        int count() const;
        bool test(int pos) const;
        bool any() const;
        bool none() const;
        bool all() const;
        bitset& operator&= (const bitset& b);
        bitset& operator|= (const bitset& b);
        bitset& operator^= (const bitset& b);
        bitset& operator= (const bitset& b);
        bitset& operator <<= (int pos);
        bitset& operator >>= (int pos);
        bitset operator~() const;
        bitset operator&(const bitset& b) const;
        bitset operator|(const bitset& b) const;
        bitset operator^(const bitset& b) const;
        bitset operator<<(int pos) const;
        bitset operator>>(int pos) const;
        bool operator== (const bitset& b) const;
        bool operator!= (const bitset& b) const;
        bool operator[] (int pos) const;
        friend std::ostream& operator << (std::ostream& os, const bitset& s) {
            for (int i = N-1; i >= 0; i--) {
                for (int j = 31; j >= 0; j--) {
                    if (s.a[i] & (1 << j)) os << 1;
                    else os << 0;
                }
            }
            return os;
        }
};
bitset::bitset()
{
	memset(a,0,sizeof(int)*N);

}
void bitset::set(int pos)
{
	int i=pos/32;
	a[i]=a[i] | (1<<(pos%32));
}
void bitset::reset(int pos)
{
	int i=pos/32;
    a[i]=~a[i];
    set(pos);
    a[i]=~a[i];
}
int bitset::count() const
{
	int count=0;
	for (int i=0;i<N;i++)
	{
		for (int j=31;j>=0;j--)
		{
			if((((a[i]<<(31-j))>>31)+2)==1)
			count++;
		}
	}
	return count;
}
bool bitset::test(int pos) const
{
	int i=pos/32;
	return (pos &(1<< pos%32))==1;
}
bool bitset::any() const
{
    for (int i=0;i<N;i++)
    {
        if(a[i]>0)
        return true;
    }
    return false;
}
bool bitset::none() const
{
    for(int i=0;i<N;i++)
    if(a[i]!=0)
    return false;
    return true;
}
bool bitset::all() const
{
    for (int i = 0; i < N; i++)
        if ((~a[i]) != 0)
            return false;
    return true;
}
bitset &bitset::operator&=(const bitset &b)
{
    for(int i=0;i<N;i++)
    a[i]&=b.a[i];
    return *this;
}
bitset &bitset::operator|=(const bitset &b)
{
    for(int i=0;i<N;i++)
    a[i]|=b.a[i];
    return *this;
}
bitset &bitset::operator^=(const bitset &b)
{
    for(int i=0;i<N;i++)
    a[i]^=b.a[i];
    return *this;
}
bitset &bitset::operator=(const bitset &b)
{
    for(int i=0;i<N;i++)
        a[i]=b.a[i];
    return *this;
}
bitset &bitset::operator<<=(int pos)
{
    for (int i = N-1; i >= 0; i -= 2)
    {
        auto temp=a[i];
        a[i]<<=pos;
        auto car=temp>>(32-pos);
        a[i-1]<<=pos;
        a[i-1]|=car;
    }
    return *this;
}
bitset &bitset::operator>>=(int pos)
{
    for(int i=0;i<N;i+=2)
    {
        auto temp=a[i];
        a[i]>>=pos;
        auto car=temp<<(32-pos);
        a[i+1]>>=pos;
        a[i+1]|=car;
    }
    return *this;
}
bitset bitset::operator~() const
{
    auto temp=*this;
    for (int i=0;i<N;i++)
    temp.a[i]=~temp.a[i];
    return temp;
}
bitset bitset::operator&(const bitset &b) const
{
    auto temp=*this;
    for (int i=0;i<N;i++)
        temp.a[i]&=b.a[i];
    return temp;
}
bitset bitset::operator|(const bitset &b) const
{
    auto temp=*this;
    for (int i=0;i<N;i++)
        temp.a[i]|=b.a[i];
    return temp;
}
bitset bitset::operator^(const bitset &b) const
{
    auto temp=*this;
    for (int i=0;i<N;i++)
        temp.a[i]^=b.a[i];
    return temp;
}
bitset bitset::operator<<(int pos) const
{
    auto an=*this;
    for (int i = N; i >= 0; i -= 2)
    {
        auto temp=a[i];
        an.a[i]<<=pos;
        auto car=temp>>(32-pos);
        an.a[i-1]<<=pos;
        an.a[i-1]|=car;
    }
    return an;

}
bitset bitset::operator>>(int pos) const
{
    auto an=*this;
    for(int i=0;i<N;i+=2)
    {
        auto temp=a[i];
        an.a[i]>>=pos;
        auto car=temp<<(32-pos);
        an.a[i+1]>>=pos;
        an.a[i+1]|=car;
    }
    return an;

}
bool bitset::operator==(const bitset &b) const
{
    for(int i=0;i<N;i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}
bool bitset::operator!=(const bitset &b) const
{
    return !(*this==b);
}
bool bitset::operator[](int pos) const
{
    return test(pos)?1:0;

}
#endif
#include<iostream>
using namespace std;
int main() {
    bitset a, b;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.set(x);
    }
    cout << "a.count() is " << a.count() << "\n";
    cout << "a.test(5) is " << (a.test(5) ? "true" : "false") << "\n";
    cout << "a.any() is " << (a.any() ? "true" : "false") << "\n";
    cout << "a.none() is " << (a.none() ? "true" : "false") << "\n";
    cout << "a.all() is " << (a.all() ? "true" : "false") << "\n";
    b = ~b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.reset(x);
    }
    cout << a << "\n";
    cout << b << "\n";
    if (a == b) {
        cout << "hello\n";
    }
    if (a != b) {
        cout << "world\n";
    }
    bitset c;
    // test &
    c = a;
    c &= b;
    cout << c << "\n";
    c = a & b;
    cout << c << "\n";
    // test |
    c = a;
    c |= b;
    cout << c << "\n";
    c = a | b;
    cout << c << "\n";
    // test ^
    c = a;
    c ^= b;
    cout << c << "\n";
    c = a ^ b;
    cout << c << "\n";
    // test <<
    c = a;
    c <<= 2;
    cout << c << "\n";
    c = a << 2;
    cout << c << "\n";
    // test >>
    c = b;
    c >>= 2;
    cout << c << "\n";
    c = b >> 2;
    cout << c << "\n";
    // test []
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (a[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}