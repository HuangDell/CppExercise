#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
vector<string> split(string & s)
{
	vector<string> an;
	for (int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		{
			an.push_back(s.substr(0,i));
			while(isspace(s[i]) && i<s.size())
			i++;
			if(i==s.size())
				return an;
			s=s.substr(i);
			i=0;
		}
	}
	an.push_back(s);
	return an;
}
void test() {
	string line;
	getline(cin, line);
	vector<string> words = split(line);
	for (int i = 0; i < words.size(); ++ i) {
		cout << words[i] << endl;
	}
}

int main() {
	test();
}