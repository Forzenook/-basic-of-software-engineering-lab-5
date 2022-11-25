#include <fstream>
#include <locale>

#include <iostream>
#include <math.h>

using namespace std;

void checkValidInput()
{
    if (cin.fail())
    {
        throw "Incorrect input";
    }
}
void checkValidParams(int n)
{
    if (n < 1)
    {
        throw "Input correct data";
    }

}
int calculate(int n, int x)
{


    if (x <= 0)
    {
        double y = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            y *= (i * i + i)+5;
        }

        return y;
    }
    else
    {
        double y = 0;
        for (int i = 0; i <= n - 1; i++)
            for (int j = 0; j <= n - 1; j++)
                if (j + i != 0)
                {
                    y += x / (i + j)+5;
                }
        return y;



    }


}




int main()
{

    ofstream fout("D:\\test.txt");

    int a, n, b, h;
    int value;

    try {

        cout << "Input n>=1, n=";
        cin >> n;
        checkValidInput();
        checkValidParams(n);

        cout << "Input a=";
        cin >> a;
        double x = a;
        checkValidInput();
        cout << "Input b =";
        cin >> b;
        cout << "Input h=";
        cin >> h;


        cout << "Enter 1 if you want to save the results to a file" << endl;
        cin >> value;
        while (x <= b)
        {
            cout << "x=" << x << ";" << "y=" << calculate(n, x) << endl;


            if (value == 1)
            {
                fout << "x=" << x << endl;
                fout << "y=" << calculate(n, x) << endl;

            }
            x = x + h;
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return-1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
        return -2;
    }

}



    
    


