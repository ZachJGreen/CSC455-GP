#include <iostream> // Used for main function, delete later
#include <algorithm>
#include <cstdlib>
#include <ctime>

// File dependencies
#include "data.h"

using namespace std;

class RegistrationManager {

    public:
        /** validate a new unique customer ID
         *
         * @param customerList A vector of customer data
         * @return `string` A unique randomly generated ID for a new customer.
        **/ 
        string validate_id(vector<Structures::Customer> customerList) {
            string id = "";
            bool valid = false;
        
            while(!valid) {
                id = generate_id();
                valid = none_of(customerList.begin(), customerList.end(), [&id](Structures::Customer customer) {
                    return customer.id == id;
                });
            }
            return id;
        }

        /** Generate random customer ID
         *
         * @return `string` A randomly generated ID for a new customer.
        **/ 
        string generate_id() {
            string cid = "CID";
            string id = "";
            srand((unsigned) time(0));
            for (int i = 0; i < 10; i++) {
                int random = rand() % 10;
                id = cid + to_string(random);
            }
            return id;
        }

        /**
         *  Check if the username is less than 8 characters, already exists, or has a sequence of 4 or more numbers. 
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the username is valid
         **/
        bool validate_username(string str) {
            string users[] = {"dsnegur123", "testuser123", "phoenix421"}; // Can delete this or alter after, using for testing purposes

            int count = 0;
            if (str.length() < 8) {
                cout << "\nInvalid input. Your username must be at least 8 characters long.\n";
                return false;
            }
            else if (find(begin(users), end(users), str) != end(users)) {
                cout << "\nThis username is already in use. Please enter a different username.\n";
                return false;
            }
            else {
                for (int i = 0; i < str.length(); i++) {
                    if (isdigit(str[i])) count++;
                    else {
                        if (count > 0) count--;
                    }
                    if (count > 3) {
                        cout << "\nYou cannot have more than three numbers in a row in your username.\n";
                        return false;
                    } else continue;
                }
            }
            return true;
        }

        /**
         *  Check if the the input is 15 characters or shorter and does not contain anything else other than letters.
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the name is valid
         **/
        bool validate_name(string str) {
            try {
                if (str.length() <= 15);
                else throw 1;
                for (int i = 0; i < str.length(); i++) {
                    if (isalpha(str[i])) continue;
                    else throw 1;
                }
                return true;
            }
            catch (...) {
                cout << "\nInvalid input. Please enter a name that is 15 characters or less and does not include non-alphabetic characters.\n";
                return false;
            }
        }

        /**
         *  Check if the the input is a valid date.
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the date is valid
         **/
        bool validate_dob(string str) {
            regex dobMatcher = regex("^([0-9]{2}-[0-9]{2}-[0-9]{4})$");
            if (str.length() != 10) { // Checks to see that there are 10 characters
                cout << "\nInvalid input. Please include two numbers for the month and day and "
                     << "four numbers for the year.\n";
                return false;
            } else {
                for (int i = 0; i < str.length(); i++) {
                    if (i == 2 || i == 5) {
                        if (str[i] != '-') {
                            cout << "\nInvalid input. Please include dashes in between the month, day, and year.\n";
                            return false;
                        } else continue;
                    } else {
                        if (!isdigit(str[i])) {
                            cout << "\nInvalid input. Please only use numerical values for the month, day, and year.\n";
                            return false;
                        } else continue;
                    }
                }
            }
            return true;
        }   

        /**
         *  Check if the the input is a valid credit card.
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the cc info is valid
         **/
        bool validate_card(string str) {
            regex cardMatcher = regex("^([0-9]{4}-[0-9]{4}-[0-9]{4})$");
            string test_cards[] = {"1111-1111-1111", "1234-1234-1234"};

            if (str.length() != 14) {
                cout << "\nInvalid input. Please enter 3 sets of 4 numbers seperated by dashes.\n";
                return false;
            } 
            else if (find(begin(test_cards), end(test_cards), str) != end(test_cards)) {
                cout << "\nThis card already exists on someone else's file. Please enter a different one.\n";
                return false;
            }
            else {
                for (int i = 0; i < str.length(); i++) {
                    if (i == 4 || i == 9) {
                        if (str[i] != '-') {
                            cout << "\nInvalid input. Please include dashes in between the sets of numbers.\n";
                            return false;
                        } else continue;
                    }
                    else {
                        if (!isdigit(str[i])) {
                            cout << "\nInvalid input. Please only use numerical values for the card numbers.\n";
                            return false;
                        } else continue;
                    }
                }
            }
            return true;
        }

        /**
         *  Check if the user inputs any special characters or letters. This includes a "-" in the beginning signifying a negative number..
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the points info is valid
         **/
        bool validate_points(string str) {
            regex numbersMatcher = regex("^/\\d+$");
            if(regex_search(str, numbersMatcher)){
                return true;
            } 
            else {
                cout << "\nPlease enter a positive numerical value (no letters or other characters).\n";
                    return false;
            }
        }
};
