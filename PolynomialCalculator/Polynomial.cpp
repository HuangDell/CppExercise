#include <string>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;
class Polynomial
{
private:
    vector<double> poly;
    string name;
public:
    Polynomial(vector<double> ve,string n){
        poly=vector<double>(ve);
        name=n;
    }
    string to_string()
    {
        stringstream ss;
        auto temp=vector<double>(poly);
        string str_poly;
        string val;
        bool isHead=true;
        while (!temp.empty())
        {
            int max_index = 0;
            for (int j = 0; j < temp.size(); j += 2)
            {
                if (temp[j] > temp[max_index])
                    max_index = j;
            }
            ss.clear();
            ss << temp[max_index];
            ss >> val;
            if(val=="-1" || val=="1")
                val.pop_back();
            if (isHead)
            {
                str_poly += val+ "x^";
                isHead = false;
            }
            else
                str_poly += (val[0] == '-' ? val : "+"+val ) + "x^";
            ss.clear();
            ss << temp[max_index + 1];
            ss >> val;
            str_poly += val;
            temp.erase(temp.begin() + max_index);
            temp.erase(temp.begin() + max_index);
        }
        return str_poly;
    }
};