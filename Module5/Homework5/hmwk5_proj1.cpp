#include "Numbers.cpp"

int main()
{
    int input;

    while (true)
    {
        cout << "Enter a number or \"0\" to exit" << endl;
        cin >> input;
        if (input == 0)
        {
            break;
        }
        else if (input < 0)
        {
            cout << "Invalid input" << endl;
            continue;
        }
        else
        {
            Numbers num(input);
            num.print();
        }
    }

    return 0;
}