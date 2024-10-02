/* lab6_proj2.cpp - demonstrates more operator overloading of + << = and >=
 * Author: Jared Ziv
 * Module: 6
 * Project: 2 (lab)
 * Description:
 *      Uses the money class and overloaded operators to compare and combine
 *      several money objects.
 *  Algorithm:
 *      Followed lab instructions.
 */
#include "Money.cpp"

using namespace std;

int main()
{
    Money obj1("4.90"), obj2("1.27"), obj3("5.24"), obj4("0.99");

    Money obj12_sum = obj1 + obj2;
    Money obj34_sum = obj3 + obj4;

    //ternary operator to print result
    (obj12_sum >= obj34_sum) ? cout << obj12_sum << endl : cout << obj34_sum << endl;

    Money five("5");
    obj1 = five;
    obj12_sum = obj1 + obj2;

    (obj12_sum >= obj34_sum) ? cout << obj12_sum << endl : cout << obj34_sum << endl;
}