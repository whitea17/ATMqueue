//
//  Author: Austin White
//  Email:  robotmaker42@gmail.com
//  Blog:   https://blog.bltstack.dev
//
//  Program: ATM Queue
//  Description:
//      This program takes an input of information about a list of
//      people who want to withdrawl money from an atm. Additional
//      information provided includes the number of people in line
//      and the max amount the atm can despense in one turn before
//      the person has to return to the begining of the line to
//      continue.
//  Output:
//      Outputs the final order of people leaving the atm once the
//      have withdrawled their desired amount of money. Note, each
//      line is for a specific test case aka line of people and atm
//      max.

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {

    int numTests;

    cin >> numTests;

    // Debug:
    //cout << "D: numTests: " << numTests << endl;

    for(int i = numTests; i > 0; i--){
        int numPeople;
        int max_withdrawl;
        // string people_string = "";

        cin >> numPeople;
        cin >> max_withdrawl;
        cin.ignore();

        // getline(cin, people_string);
        // stringstream people_wants_raw(people_string);

        // Debug:
        //  cout << "D: numPeople: " << numPeople << endl;
        //  cout << "D: max_w: " << max_withdrawl << endl;
        //  cout << "D: people: " << people_string << endl;
        


        // Paralell queues
        queue<int> people;
        queue<int> money_wanted_list;
        string out;
        int tmp;

        // load people id(num) and want of money into queues
        for(int i = 1; i < numPeople + 1; i++){
            cin >> tmp;
            people.push(i);
 
            money_wanted_list.push(tmp);
        }

    
        while(!people.empty()){
            // Get person from line to use atm
            int person = people.front();
            int money_wanted = money_wanted_list.front();
            people.pop();
            money_wanted_list.pop();

            // Use atm
            if(money_wanted <= max_withdrawl){
                // Got enough money, Leave line
                out = out + " " + to_string(person);
            }else{
                // withdrawl max money from atm
                money_wanted -= max_withdrawl;

                // Go back to end of line
                people.push(person);
                money_wanted_list.push(money_wanted);
            }

        }

        // outputs order of people 
        cout << "Case #" << (numTests - i) + 1 << ": ";
        cout << out;
        cout << endl;
    }
}

