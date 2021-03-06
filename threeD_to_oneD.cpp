#include <iostream>
using namespace std;

// this allocates n*m*p places in the memory to store the new oneD matrix
int *createOneDVector(int n, int m, int p)
{
    int *vector = (int *)malloc(n * m * p * sizeof(int));
    return vector;
}

// this converts the given threeD matrix to a oneD matrix
int *convert3DTo1D(int n, int m, int p, int *vector)
{
    int *oneDVector = createOneDVector(n, m, p);
    oneDVector = vector;
    return oneDVector;
}

// check is a given +ve or -ve number is integer or not
bool isInteger(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ((i == 0) && (str[i] == '-'))
            continue;
        if (isdigit(str[i]) == false)
            return false;
    }
    return true;
}

// asks the user to enter the wanted dimensions of his threeD matrix
void scan3DMatrixDimensions(int &n, int &m, int &p)
{
    string strN, strM, strP;
    do
    {
        cout << "Enter the depth number: ";
        cin >> strN;
        if ((isInteger(strN)) && (stoi(strN) > 0))
        {
            n = stoi(strN);
            do
            {
                cout << "Enter the row number: ";
                cin >> strM;
                if ((isInteger(strM)) && (stoi(strM) > 0))
                {
                    m = stoi(strM);
                    do
                    {
                        cout << "Enter the column number: ";
                        cin >> strP;
                        if ((isInteger(strP)) && (stoi(strP) > 0))
                        {
                            p = stoi(strP);
                        }
                        else
                        {
                            cout << "Error!! Column number must be an integer more than zero.\n";
                        }
                    } while ((!isInteger(strP)) || (stoi(strP) == 0));
                }
                else
                {
                    cout << "Error!! Row number must be an integer more than zero.\n";
                }
            } while ((!isInteger(strM)) || (stoi(strM) == 0));
        }
        else
        {
            cout << "Error!! Depth number must be an integer more than zero.\n";
        }
    } while ((!isInteger(strN)) || (stoi(strN) == 0));
}

int main()
{
    int y;
    int n, m, p;
    string strN, strM, strP;
    int tempN, tempM, tempP;
    string element;

    // scan the wanted dimensions
    scan3DMatrixDimensions(n, m, p);

    int matrix[n][m][p];

    // start scanning the threeD matrix
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nStart entering the 3D matrix elements with format (depth, row, column)...\n";

    for (tempN = 0; tempN < n; tempN++)
    {
        for (tempM = 0; tempM < m; tempM++)
        {
            for (tempP = 0; tempP < p; tempP++)
            {
                do
                {
                    cout << "Enter element with index (" << tempN << "," << tempM << "," << tempP << "): ";
                    cin >> element;
                    if (isInteger(element))
                    {
                        matrix[tempN][tempM][tempP] = stoi(element);
                    }
                    else
                    {
                        cout << "Error!! Element number must be an integer.\n";
                    }

                } while ((!isInteger(element)));
            }
        }
    }

    // now after the threeD matrix is successfully scanned, it time to convert it to oneD matrix ... O(1)
    int *oneDMatrix = convert3DTo1D(n, m, p, matrix[0][0]);

    // the user main menu
    string operation;
    while (1)
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nOperations:\n1) Lookup \n2) Exit\n";
        cout << "Enter operation number: ";
        cin >> operation;
        if (operation == "1")
        {
            // look up is chosen
            cout << "\nLookup:\n";
            cout << "Enter the depth number: ";
            cin >> strN;
            if (isInteger(strN) && stoi(strN) >= 0 && stoi(strN) < n)
            {
                tempN = stoi(strN);
                cout << "Enter the row number: ";
                cin >> strM;
                if (isInteger(strM) && stoi(strM) >= 0 && stoi(strM) < m)
                {
                    tempM = stoi(strM);
                    cout << "Enter the column number: ";
                    cin >> strP;
                    if (isInteger(strP) && stoi(strP) >= 0 && stoi(strP) < p)
                    {
                        tempP = stoi(strP);
                        // this is the formula that allows me to acces the wanted the wanted element in oneD matrix using the threeD matrix specifications 
                        y = (p * tempM) + tempP + (m * p * tempN);
                        cout << "\nmatix[" << tempN << "][" << tempM << "][" << tempP << "] = " << oneDMatrix[y] << endl;
                    }
                    else
                    {
                        cout << "Error!! Out of range column number.\n";
                    }
                }
                else
                {
                    cout << "Error!! Out of range row number.\n";
                }
            }
            else
            {
                cout << "Error!! Out of range depth number.\n";
            }
        }
        else if (operation == "2")
        {
            break;
        }
        else
        {
            cout << "Error!! Invalid operation number.\n";
        }
        cout << "\n";
        // pause to allow the user to see the results of his actions
        system("pause");
    }
    return 0;
}
