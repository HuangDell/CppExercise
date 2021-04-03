#include <regex>
#include <string>
#include <vector>
using namespace std;
class Judge
{
    private:
    regex str_reg;
    regex str_draw;
    regex str_name;
    smatch matchResult;
    string poly_name;
    
    public:
    Judge()
    {
        poly_name="";
        str_reg=regex("((\\w+)=)?(\\(-?\\d+,-?\\d+\\))+");
        str_draw=regex(R"~((-?\d+),(-?\d+))~");
        str_name=regex("(\\w+)=");
    }

    vector<double> polynomial(string input)//此函数用于判断输入的多项式是否valid
    {
        vector<double> poly;
        if(regex_match(input,matchResult,str_reg) && matchResult[0].length()==input.size())
        {
            sregex_iterator iter(input.begin(), input.end(), str_draw);
            sregex_iterator end;
            while(iter!=end)
            {
                for (int i=1;i<iter->size();i++)
                    poly.push_back(stod((*iter)[i]));
                    iter++;
            }
            if(regex_match(input,matchResult,str_name))
                poly_name=matchResult[1];
        }
        return poly;
    }
    string getName()
    {
        return poly_name;
    }

};
