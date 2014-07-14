#include <iostream>
#include <ctime> // time variable for random number
#include <cstdlib> // srand & rand
#include <cctype> // allows lower and uppercase input
#include <cmath> // displays absolute value on chutes


using namespace std;



const int WINNING_POSITION = 100;

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

const int ROLL_MIN_VALUE = 1;
const int ROLL_MAX_VALUE = 6;

void welcome();

int numberOfPlayers ();

int roll ();

int takeTurn(int position, string& playerNames);

void playerNames();

int main()
{
    welcome();
    
    int position = 0;
    
        while (position != WINNING_POSITION){
            playerNames();
            takeTurn (position, playerNames);
        }
    
    }

void playerNames()
{
    string playerName [MAX_PLAYERS];
    
    int players = numberOfPlayers();
    
    for (int i = 0; i < players; i++)
    {
        cout << "Please enter Player " << (i + 1) << "'s name: ";
        cin >> playerName [i];
        cin.ignore();
        }
    
    for (int a = 0; a < players; a++) {
        string playerOne = playerName[a];
        
    }
    
}

int takeTurn (int position, string playerNames)
{
    string playerName;
    
    playerName = playerNames();
    
    cout << playerName << "'s current position is " << position << "." << endl;

    int initialMove = roll();
    cout << playerName << " spun a " << initialMove << endl;
    

    if((position >= 95) && (initialMove + position > WINNING_POSITION)) {
        cout << "Sorry, " << player << "you can't go over " << WINNING_POSITION << ", you're still on "
        << position << endl;
        return position;
    }
    
    
    int newPosition = position + initialMove;
    cout << playerName << " moved to space " << newPosition << "." << endl;
    

    cout << playerName << " is now on space " << newPosition << "." << endl;
    
    return newPosition;
}


int roll ()
{
    
    cout << endl << "Press enter to spin ";
    cin.get();
    cout << endl;
    int num;
    srand ((unsigned)time(0));
    num = rand() % (ROLL_MAX_VALUE - ROLL_MIN_VALUE) + ROLL_MIN_VALUE;
    return num;
}


void welcome()
{
    cout << "Hello and welcome to a game of Chutes and Ladders!" << endl << endl;
    cout << "This is a game between 2-6 players to see who can reach the goal\n"
    << "of space " << WINNING_POSITION << " first.\n"
    << endl << "Each turn, each player will spin a number from 1-6 and move that many spaces." << endl << endl;
    cout << "If the player lands on a 'chute', they fall back a given amount of spaces and if they land "
    << "on a ladder they zoom up a number of spaces.\n"
    << endl << "Whoever reaches space " << WINNING_POSITION << " first wins- but they must land on exactly "
    << "that space, without going past."
    << endl << endl << "Best of luck!";
    cout << endl;
    
}


int numberOfPlayers ()
{
    int players;
    
    
    cout << endl << "How many players would like to play (" << MIN_PLAYERS << "-" << MAX_PLAYERS << ")?: ";
    cin >> players;
    
    
    while (players < MIN_PLAYERS || players > MAX_PLAYERS){
        cout << endl<< "Please enter a number between " << MIN_PLAYERS << "-" << MAX_PLAYERS << ": ";
        cin >> players;
    }
    
    return players;
}


