#include <string>
#include <regex>
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
        string str_poly;
        for(int i=0;i<poly.size();i++)
            str_poly+=std::to_string(poly[i++])+"x^"+std::to_string(poly[i])+"+";
        return str_poly;

    }
};