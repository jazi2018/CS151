#include "Estring.cpp"
#include <iomanip>

using namespace std;

int main()
{
    //using assignment operator
    EString estring1 = "Hello MiraCosta!", estring2;
    estring2 = estring1;
    cout << "First string: " << estring1 << endl
        << "Second string: " << estring2 << endl << endl;

    //setup for other operators
    EString new_years = "New Year's Party at 8:30.";
    EString bring_friends = " Don't forget to bring your friends!";

    //using prefix operator
    cout << setw(25) << left << "Original string:" << new_years << endl;
    cout << setw(25) << left << "Using prefix operator:" << ++new_years << endl;
    cout << setw(25) << left << "After using prefix:" << new_years << endl;

    //using postfix operator
    cout << setw(25) << left << "Original string:" << bring_friends << endl;
    cout << setw(25) << left << "Using postfix operator:" << bring_friends++ << endl;
    cout << setw(25) << left << "After using postfix:" << bring_friends << endl;

    //using addition operator
    EString string_concat = new_years + bring_friends;
    cout << setw(25) << left << "Concatenated strings: " << string_concat << endl;

    //using square brackets operator
    cout << setw(15) << left << "Original:";
    for (int i = 0; i < new_years.getSize(); i++)
    {
        cout << " " << new_years[i];
    }
    cout << endl << setw(15) << left << "Updated:";
    for (int i = 0; i < new_years.getSize(); i++)
    {
        cout << " " << ++new_years[i];
    }
}