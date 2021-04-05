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

    vector<Polynomial>& getData()
    {
        return data;
    }
};