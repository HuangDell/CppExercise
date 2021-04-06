typedef Polynomial py;
py ans;
py &operator+(py py1, py py2)
{
    vector<double> temp(py1.getPoly());
    for (auto num : py2.getPoly())
        temp.push_back(num);
    ans = py(temp, "ans");
    return ans;
}
py &operator-(py py1, py py2)
{
    vector<double> temp(py1.getPoly());
    int index=0;
    for (auto num : py2.getPoly())
    {
        if(index++%2==0)
            num=-num;
        temp.push_back(num);

    }
    ans = py(temp, "ans");
    return ans;
}