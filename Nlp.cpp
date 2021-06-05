#include <iostream>
#include <sstream>

using namespace std;
#include <vector>
#include <utility>
template<typename T,typename K>
struct Hpair{
	T first;
	K second;
};
template<typename T,typename K>
Hpair<T,K> make_Hpair(T t,K k)
{
	Hpair<T,K> p;
	p.first=t;
	p.second=k;
	return p;
}


class HashCode{
public:
	size_t hashval;
	string ch;
	operator int()
	{
		return hashval;
	}
	operator string()
	{
		return ch;
	}

	static HashCode getHash(string & st) 
	{
 		HashCode hc;
		hc.ch=st;
		size_t hashVal=0LL;
		for(auto &ch:st)
			hashVal=37*hashVal+ch;
		hc.hashval=hashVal+INT_MAX;
		return hc; 
	}
	static HashCode getHash(int  num) 
	{
		HashCode hc;
		hc.hashval=num;
		return hc;
	}
};
class HT{
	vector<Hpair<HashCode,HashCode>> tables;
	public:
	template<typename K,typename V>
	void put(K key,V val)
	{
		tables.push_back(make_Hpair(HashCode::getHash(key),HashCode::getHash(val)));
	}

	template <typename T>
	HashCode operator[](T k)
	{
		HashCode key=HashCode::getHash(k);
		for(auto &temp:tables)
		{
			if(temp.first.hashval==key.hashval)
			return temp.second;
		}
		return HashCode::getHash(0);
	}
	
	int size(){return tables.size();}
};

int main() {
	HT map;
	
	int key1;
	int value1;
	cin >> key1 >> value1;
	map.put(key1, value1);
	
	string key2;
	string value2;
	cin >> key2 >> value2;
	map.put(key2, value2);
	
	int key3;
	string value3;
	cin >> key3 >> value3;
	map.put(key3, value3);
	
	string key4;
	int value4;
	cin >> key4 >> value4;
	map.put(key4, value4);
	
	cout << map.size() << endl;
	cout << (int)map[key1] << endl;
	cout << (string)map[key2] << endl;
	cout << (string)map[key3] << endl;
	cout << (int)map[key4] << endl;
}
