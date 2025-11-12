#include <iostream>
#include <fstream>
using namespace std;

void isIdentifier(string input)
{

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            cout << "It is not a valid identifier(contains space)" << endl;
            return;
        }
    }

    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
           input[0] == '_'))
    {
        cout << "It is not a valid identifier" << endl;
        return;
    }

    for (int i = 1; input[i] != '\0'; i++)
    {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
               input[i] == '_'))
        {
            cout << "It is not a valid identifier" << endl;
            return;
        }
    }

    cout << "It is a valid identifier" << endl;
}

int main()
{
    ifstream file("lab4.txt");
    string input;

    if (!file)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    while (getline(file, input)) {
        cout << "Reading from file:"<< input << endl;

        isIdentifier(input);
    }

    file.close();
    return 0;
}
