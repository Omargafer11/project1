/*
program : Subtract Square Game It is a game consisting of two players, The two players first choose either to enter the number of coins themselves or choose a random number from a list of numbers.
After that, each player chooses a number that has a root before the number they chose, For each number that the player chooses 
we subtract it from the coins and the player who arrives first... Zero wins the game
game: game 3
Author: Omar gafer helal abd elhakim
id: 20230249
version : 1.0
Date:1/3/2024
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
//Create a function to show the list
void showvector(vector <int> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(i==0) cout<<"[";
        cout<<vec.at(i);
        if(i+1<vec.size()) cout<<",";
        if(i+1==vec.size()) cout<<"]";
    }
}
// Create a function that produces a list of perfect squares up to the square root of n
vector<int> numSquare(int n)
{
    vector<int> squaresofnum;
    for(int i=1;i<sqrt(n);i++)
    {
        squaresofnum.push_back(i*i);
    }
    return squaresofnum;
}
int readNumber() 
{ 
 int n; 
 cout << "Enter the number of coins : "; 
 cin >> n; 
 
 while (cin.fail()) 
 { 
  cin.clear(); 
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  cout << "Please enter a valid number : "; 
  cin >> n; 
 } 
 return n; 
}
int main() 
{
    string choose;
    int n_coins;
    cout<<"Welcome to the Subtract Square Game\n";
    //# Ask the user if they want to enter the number of coins or generate a random number
    cout<<"Do you want to enter the number of coins yourself ? (yes/no): ";
    cin>>choose;
    //If the user chooses to enter the number of coins, Ask him to enter the number
    if(choose=="yes"||choose=="Yes")
    {
       n_coins = readNumber();
    }
    //If the user chooses not to enter the number, Give him a random number from 10 to 1000
    else
    {
        srand(static_cast<unsigned>(time(nullptr)));
        n_coins = rand() % (1000 - 10 + 1) + 10;
    }
    //Find the numbers that have a root before the number of coins
    vector<int> number_numSquare= numSquare(n_coins);
    // show list of numbers that have a root before the number of coins
    showvector(number_numSquare);
    while (n_coins > 0)
    {
        int move;
        //The first player's turn
        cout<<"\nPlayer 1: Choose a number from ";
        showvector(number_numSquare);
        cout<<" and less than or equal "<<n_coins<<": ";
        cin>>move;
        //Validate the chosen move
         while (cin.fail()) 
        { 
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Please enter a valid number : "; 
            cin >> move; 
        } 
        while (move > n_coins || move < 0 ||find(number_numSquare.begin(),number_numSquare.end(),move)==number_numSquare.end())
        {
            cout<<"Please enter a valid number\n";
            cout<<"Player 1: Choose a number from ";
            showvector(number_numSquare);
            cout<<"and less than or equal "<< n_coins<<": ";
            cin>>move;
        }
        //Update the total
        n_coins-=move;
        //remove the chosen move from the list
        number_numSquare.erase(remove(number_numSquare.begin(), number_numSquare.end(), move),number_numSquare.end());
        cout<<"Now we have: "<<n_coins <<" coins\n";
        //Check if the first player wins
        if(n_coins <= 0)
        {
            cout<<"Player 1 is the winner\n";
            cout<<"End game";
            break;
        }
        //The second player's turn
        cout<<"Player 2: Choose a number from ";
        showvector(number_numSquare);
        cout<<"and less than or equal "<<n_coins<<": ";
        cin>>move;
        //Validate the chosen move
        while (cin.fail()) 
        { 
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Please enter a valid number : "; 
            cin >> move;
        } 
        while (move > n_coins || move < 0 ||find(number_numSquare.begin(),number_numSquare.end(),move)==number_numSquare.end())
        {
            cout<<"Please enter a valid number\n";
            cout<<"Player 2: Choose a number from ";
            showvector(number_numSquare);
            cout<<"and less than or equal "<<n_coins<<": ";
            cin>>move;
        }
        //Update the total
        n_coins-=move;
        number_numSquare.erase(remove(number_numSquare.begin(), number_numSquare.end(), move),number_numSquare.end());
        cout<<"Now we have: "<<n_coins <<" coins\n";
        //Check if the second player wins
        if(n_coins <= 0)
        {
            cout<<"Player 2 is the winner\n";
            cout<<"End game";
            break;
        }
    }
    return 0;
}