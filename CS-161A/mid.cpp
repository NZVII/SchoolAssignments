#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // declare player name variables
    string playerOne;
    string playerTwo;
    string playerThree;
    // declare player rock amount variables
    int playerOneRocks;
    int playerTwoRocks;
    int playerThreeRocks;
    // declare rock average variable & constant
    double rockAverage;
    const int NUM_PLAYERS = 3;

    cout << "Welcome to the Rock Collector Championships\n" << endl;

    // enter player one details
    cout << "Enter player one's name: ";
    getline(cin, playerOne);
    cout << "How many rocks did player one collect? ";
    cin >> playerOneRocks;
     if (playerOneRocks < 0 ){
        cout << "Invalid amount. 0 will be entered." << endl;
        playerOneRocks = 0;
    }
    cin.ignore(1000,'\n');

    cout << endl;

    // enter player two details
    cout << "Enter player two's name: ";
    getline(cin, playerTwo);
    cout << "How many rocks did player two collect? ";
    cin >> playerTwoRocks;
    if (playerTwoRocks < 0 ){
        cout << "Invalid amount. 0 will be entered." << endl;
        playerTwoRocks = 0;
    }
    cin.ignore(1000,'\n');
    
    cout << endl;


    // enter player three details
    cout << "Enter player three's name: ";
    getline(cin, playerThree);
    cout << "How many rocks did player Three collect? ";
    cin >> playerThreeRocks;
    if (playerThreeRocks < 0 ){
        cout << "Invalid amount. 0 will be entered." << endl;
        playerThreeRocks = 0;
    }
    cin.ignore(1000,'\n');

    cout << endl;

    rockAverage = (playerOneRocks+playerTwoRocks+playerThreeRocks)/NUM_PLAYERS;

    // Get a three way tie
    if (playerOneRocks == playerTwoRocks && playerOneRocks == playerThreeRocks){
        cout << "it is a three way tie!" << endl;
    }
    else {
        // evaluate other ties
        if (playerOneRocks == playerTwoRocks){
            if (playerOneRocks > playerThreeRocks){
                cout << playerOne << " and " << playerTwo << " "
                        << "are tied for first place." << endl;
                cout << playerThree << " is in second place!" << endl;
            }
            else if (playerOneRocks < playerThreeRocks){
                cout << playerOne << " and " << playerTwo << " "
                        << "are tied for second place." << endl;
                cout << playerThree << " is in first place!" << endl;
            }
        }
        else if (playerOneRocks == playerThreeRocks){
            if (playerOneRocks > playerTwoRocks){
                cout << playerOne << " and " << playerThree << " "
                        << "are tied for first place." << endl;
                cout << playerTwo << " is in second place!" << endl;
            }
            else if (playerOneRocks < playerTwoRocks){
                cout << playerOne << " and " << playerThree << " "
                        << "are tied for second place." << endl;
                cout << playerTwo << " is in first place!" << endl;
            }
        }
        else if (playerTwoRocks == playerThreeRocks){
            if (playerTwoRocks > playerOneRocks){
                cout << playerTwo << " and " << playerThree << " "
                        << "are tied for first place." << endl;
                cout << playerOne << " is in second place!" << endl;
            }
            else if (playerTwoRocks < playerOneRocks){
                cout << playerTwo << " and " << playerThree << " "
                        << "are tied for second place." << endl;
                cout << playerOne << " is in first place!" << endl;
            }
        }
        else if (playerThreeRocks == playerTwoRocks){
            if (playerThreeRocks > playerOneRocks){
                cout << playerThree << " and " << playerTwo << " "
                        << "are tied for first place." << endl;
                cout << playerOne << " is in second place!" << endl;
            }
            else if (playerOneRocks < playerTwoRocks){
                cout << playerThree << " and " << playerTwo << " "
                        << "are tied for second place." << endl;
                cout << playerOne << " is in first place!" << endl;
            }
        }
        else{
            string firstPlace;
            string secondPlace;
            string thirdPlace;
            // evaluate first place
            if (playerOneRocks > playerTwoRocks && playerOneRocks > playerThreeRocks ){
                firstPlace = playerOne;
                // evaluate second place
                if (playerTwoRocks > playerThreeRocks){
                    secondPlace = playerTwo;
                    thirdPlace = playerThree;
                }
                else{
                    secondPlace = playerThree;
                    thirdPlace = playerTwo;
                }
            }

            // evaluate first place
            else if (playerTwoRocks > playerOneRocks && playerTwoRocks > playerThreeRocks ){
                firstPlace = playerTwo;
                // evaluate second place
                if (playerOneRocks > playerThreeRocks){
                    secondPlace = playerOne;
                    thirdPlace = playerThree;
                }
                else{
                    secondPlace = playerThree;
                    thirdPlace = playerOne;
                }
            }
            // evaluate first place
            else if (playerThreeRocks > playerOneRocks && playerThreeRocks > playerTwoRocks ){
                firstPlace = playerThree;
                // evaluate second place
                if (playerOneRocks > playerTwoRocks){
                    secondPlace = playerOne;
                    thirdPlace = playerThree;
                }
                else{
                    secondPlace = playerTwo;
                    thirdPlace = playerOne;
                }
            }
            cout << firstPlace << " is in first place!" << endl;
            cout << secondPlace << " is in second place!" << endl;
            cout << thirdPlace << " is in third place!" << endl;

        }
    }

    cout << fixed << setprecision(2) << "\nThe average amount of rocks collected by the top three players is " << rockAverage << "\n" << endl;
    cout << "Congratulations Rock Collectors!" << endl;
    return 0;
}