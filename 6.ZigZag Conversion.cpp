#include <iostream>
#include <string.h>
using namespace std;

string convert(string s, int numRows)
{
    int length = s.length();
    char m[1000][1000];
    char result[1000];
    if(length == 0 || numRows == 1 || length == 1 || length == 2)
        return s;
    memset(m , '\0' , sizeof(m));
    memset(result , '\0' , sizeof(result));
    int c;
    int r;
    int n = 0;
    int column = 0;
    for(c = 0; c >=0 ; c++)
    {
        for(r = 0 ; r < numRows ; r++)
        {
            int ju = c % (numRows - 1);
            if(ju == 0)
                m[r][c] = s[n++];
            else
            {
                m[numRows - ju - 1][c] = s[n++];
                break;
            }
            if(n == length)
                break;
        }
        if(n == length)
            break;
    }

    int num2 = 0;
    for(int r2 = 0 ; r2 < numRows ; r2++)
    {
        for(int c2 =  0 ; c2 <= c ; c2++)
        {
            if(m[r2][c2] == '\0')
                continue;
            result[num2++] = m[r2][c2];
        }
    }
    string res = result;
    return res;
}



int main()
{
    string m = convert("ABC" , 2);
    cout << m << endl;
    return 0;
}
