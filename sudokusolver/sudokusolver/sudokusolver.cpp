#include <iostream>
using namespace std;
int countt = 0;
bool checker(int sudo[9][9], int i, int j, int n, int num)
{
    //vertical check
    for (int k = 0; k < n; k++)
    {
        if (sudo[k][j] == num)
        {
            return false;
        }
    }

    //horizontal check
    for (int m = 0; m < n; m++)
    {
        if (sudo[i][m] == num)
        {
            return false;
        }
    }

    //for 3x3 matrix

    int sno = sqrt(n);
    int s1 = (i / sno) * sno;
    int s2 = (j / sno) * sno;

    for (int i = s1; i < s1 + sno; i++)
    {
        for (int j = s2; j < s2 + sno; j++)
        {
            if (sudo[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}


bool sudokusolver(int sudo[9][9], int i, int j, int n)
{
    //base case

    if (i == n)
    {
        for (int l = 0; l < n; l++)
        {
            for (int m = 0; m < n; m++)
            {
                cout << sudo[l][m] << " ";
            }
            cout << endl;
        }
        return true;
    }




    //rec case
    if (j == n)
    {
        return  sudokusolver(sudo, i + 1, 0, n);
    }
    if (sudo[i][j] != 0)
    {
        return  sudokusolver(sudo, i, j + 1, n);

    }

    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (checker(sudo, i, j, n, num))
            {
                sudo[i][j] = num;

                bool resul = sudokusolver(sudo, i, j + 1, n);
                if (resul == true)

                {
                    return true;
                }
            }
            sudo[i][j] = 0;
        }
    }


    return false;

}

int main()
{
    int n;
    int sudo[9][9];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudo[i][j];
        }
    }
    cout << endl;
    sudokusolver(sudo, 0, 0, n);

    return 0;
}