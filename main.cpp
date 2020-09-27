//
//  Author: Austin White
//  Email:  robotmaker42@gmail.com
//  Blog:   https://blog.bltstack.dev
//
//  Program: ATM Queue
//  Description
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
//      max

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input_parm = "2\n3 3\n2 7 4\n5 6\n9 10 4 7 2";
    stringstream input_raw(input_parm);

    int numTests = 0;

    input_raw >> numTests;

    // Debug:
    //cout << "D: numTests: " << numTests << endl;

    for(int i = numTests; i > 0; i--){
        int numPeople = 0;
        int max_withdrawl = 0;
        string people_string = "";
        string trash = "";

        input_raw >> numPeople;
        input_raw >> max_withdrawl;
        input_raw.ignore();

        getline(input_raw, people_string);
        stringstream people_wants_raw(people_string);

        // Debug:
        // cout << "D: numPeople: " << numPeople << endl;
        // cout << "D: max_w: " << max_withdrawl << endl;
        // cout << "D: people: " << people_string << endl;
        


        // Paralell queues
        queue<int> people;
        queue<int> money_wanted_list;
        queue<int> out;

        // load people id(num) and want of money into queues
        for(int i = 1; i < numPeople + 1; i++){
            people.push(i);
            int money = 0;
            people_wants_raw >> money;

            money_wanted_list.push(money);
        }

        // people and money_wanted are paralell and should be the same size no matter what
        if(people.size() != money_wanted_list.size()){
            cout << "Parsing error, please review input and try again.\nGoodbye :)";
            exit(1);
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
                out.push(person);
            }else{
                // withdrawl max money from atm
                money_wanted -= max_withdrawl;

                // Go back to end of line
                people.push(person);
                money_wanted_list.push(money_wanted);
            }

        }

        // outputs order of people 
        cout << "Case #" << (numTests - i) + 1<< ": ";
        while(!out.empty()){
            cout << out.front() << " ";
            out.pop();
        }
        cout << endl;
    }
}

