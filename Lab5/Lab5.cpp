#include <iostream>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {"int","float","double","char","if","else","for","while","return"};
    int size = 9;

    for (int i = 0; i < size; i++)
    {
        if (s == keywords[i])
        {
            return true;
        }

    }
    return false;
}

bool isOperator(char ch)
{
    char ops[] = "+-*/=";
    for (int i = 0; i < 5; i++)
    {
        if (ch == ops[i])
        {
             return true;
        }

    }
    return false;
}

bool isSeparator(char ch)
{
    char sep[] = "(){};,";
    for (int i = 0; i < 6; i++)
    {
        if (ch == sep[i])
        {
             return true;
        }

    }
    return false;
}

bool isNumeric(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
             return false;
        }
    }
    return true;
}

int main()
{
    string line, word;

    cout << "Enter code:\n";

    while (true)
    {
        getline(cin, line);


        word = "";

        for (int i = 0; line[i] != '\0'; i++)
        {
            char ch = line[i];


            if (isOperator(ch))
            {
                if (word != "")
                {
                    if (isKeyword(word)) cout << word << " : Keyword\n";
                    else if (isNumeric(word)) cout << word << " : Numeric Constant\n";
                    else cout << word << " : Identifier\n";
                    word = "";
                }
                cout << ch << " : Operator\n";
            }


            else if (isSeparator(ch))
            {
                if (word != "") {
                    if (isKeyword(word)) cout << word << " : Keyword\n";
                    else if (isNumeric(word)) cout << word << " : Numeric Constant\n";
                    else cout << word << " : Identifier\n";
                    word = "";
                }
                cout << ch << " : Separator\n";
            }

            else if (ch != ' ')
            {
                word += ch;
            }


            else
            {
                if (word != "")
                {
                    if (isKeyword(word)) cout << word << " : Keyword\n";
                    else if (isNumeric(word)) cout << word << " : Numeric Constant\n";
                    else cout << word << " : Identifier\n";
                    word = "";
                }
            }
        }


        if (word != "")
        {
            if (isKeyword(word)) cout << word << " : Keyword\n";
            else if (isNumeric(word)) cout << word << " : Numeric Constant\n";
            else cout << word << " : Identifier\n";
        }
    }

    return 0;
}
