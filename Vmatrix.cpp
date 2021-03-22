#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;
string *values;
int index;
class elem{
    public:
    char name;
    int val;
    elem(char name):name(name),val(0){};
};
bool elemIsin(const vector<elem>& ve,char name)
{
    for (auto v:ve)
        if(v.name==name)
            return true;
    return false;
}
int findVal(const vector<elem> &ve,char name)
{
    for (auto v:ve)
        if(v.name==name)
        return v.val;
}
bool judge(string prop, vector<elem>& ve,int i)
{
    stack <int> st;
    int size=ve.size();
    for (int j=0;j<size;j++)
        ve[j].val=values[i][j]-'0';
    for(auto ch:prop)
    {
        if(isalpha(ch))
        st.push(findVal(ve,ch));
        else if(ch=='~')
            st.top()=!st.top();
        else if(ch=='*')
        {
            int temp=st.top();
            st.pop();
            st.top()=st.top() && temp;
        }
        else if (ch=='+')
        {
            int temp=st.top();
            st.pop();
            st.top()=st.top() || temp;
        }
    }
    return st.top();
}
void generatedValue(string &temp,int val,int size)
{
    temp+=to_string(val);
    if (temp.size() == size)
    {
        values[index++]=temp;
        return;
    }
    generatedValue(temp,0, size);
    temp.pop_back();
    generatedValue(temp,1,size);
    temp.pop_back();
}
int main(void)
{
    int count;
    cin >>count;
    for (int i=0;i<count;i++)
    {
        string prop,temp;
        bool isTrue=true;
        index=0;
        vector <elem> elements;
        cin >> prop;
        for (auto ch:prop)
        if(isalpha(ch) &&!elemIsin(elements,ch))
        elements.push_back(elem(ch));
        int way=pow(2,elements.size());
        values=new string [way];
        generatedValue(temp,0,elements.size());
        temp.clear();
        generatedValue(temp,1,elements.size());
        for (int i=0;i<index;i++)
        {
            isTrue=isTrue && judge(prop,elements,i);
            if(!isTrue)
            break;
        }
        cout << prop +":"<<(isTrue ?"Yes":"No")<<endl;
    }
}