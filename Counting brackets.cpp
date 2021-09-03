#include <iostream>
#include <cmath>

using namespace std;

string str = "v)(a(ds)vc)())((c"; // 3
string str1 = "(()())"; // 3
string str2 = "v)(a(ds(vc)())((c"; // 3
string str3 = "v)(a)ds)vc)())((c"; // 2
string str4 = "v)ds)vc))((c"; // 0
string str5 = "((()))"; // 3
string str6 = "())())"; // 2

int Scroll(int counter, const string &data, const int &length)
{
    while (data[counter] != '(' && counter < length)
    {
        counter++;
    }
    return counter;
}

int Calc(string inputData)
{
    int strlength = inputData.length();
    int sum = 0;
    int openPare = 0;
    int closePare = 0;
    for (int i = Scroll(0, inputData, strlength); i < strlength; i++)
    {
        openPare = (inputData[i] == '(') ? openPare + 1 : openPare;
        closePare = (inputData[i] == ')') ? closePare + 1 : closePare;
        if (openPare == closePare)
        {
            sum += openPare;
            openPare = 0;
            closePare = 0;
            i = Scroll(i + 1, inputData, strlength) - 1; // +1 и -1 для исключения повторных проходов по циклу
        }
    }
    return (closePare > 0) ? sum + (abs(openPare - closePare)) : sum;
}

int main()
{
    cout << Calc(str6);
}