/******************************************************************************
verifica 27/01/2024
Giuseppe Chiarenza

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string cities[] = { "        ","Milano ", "Bologna ", "Firenze ","Roma \n" };
    cout << cities[0];
    cout << cities[1];
    cout << cities[2];
    cout << cities[3];
    cout << cities[4];
    string distance_Milano[] = { "Milano ", "   0 ", "     300 ","    500 ", "  800\n " };
    cout << distance_Milano[0];
    cout << distance_Milano[1];
    cout << distance_Milano[2];
    cout << distance_Milano[3];
    cout << distance_Milano[4];
    cout << distance_Milano[5];
    string distance_Bologna[] = { "Bologna ", " 300", "     0 ","    300 ", "  500\n " };
    cout << distance_Bologna[0];
    cout << distance_Bologna[1];
    cout << distance_Bologna[2];
    cout << distance_Bologna[3];
    cout << distance_Bologna[4];
    cout << distance_Bologna[5];
    string distance_Firenze[] = { "Firenze ", "  500", "   300 ","     0  ", "  300\n " };
    cout << distance_Firenze[0];
    cout << distance_Firenze[1];
    cout << distance_Firenze[2];
    cout << distance_Firenze[3];
    cout << distance_Firenze[4];
    cout << distance_Firenze[5];
     string distance_Roma[] = { "Roma    ", "  800", "   500 ","   300  ", "    0\n " };
    cout << distance_Roma[0];
    cout << distance_Roma[1];
    cout << distance_Roma[2];
    cout << distance_Roma[3];
    cout << distance_Roma[4];
    cout << distance_Roma[5];
    
    return 0;
}
