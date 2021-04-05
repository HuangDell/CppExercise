#include <vector>
#include "Polynomial.cpp"
using namespace std;
class DataBase{
    vector<Polynomial> data;
    public:
    DataBase(){}
    void addPoly(Polynomial py)
    {
        data.push_back(py);
    }

    void showData()
    {
        int count=1;
        for (auto temp:data)
        {
            printf("%s=%s\t\t",temp.getName(),temp.to_string());
            if(count%2==0)
                puts("");
            count++;
        }
    }
};