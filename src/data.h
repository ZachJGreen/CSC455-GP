#ifndef DATA
#define DATA

#include <iostream>
#include <string>
#include <list>
using namespace std;
/**
* This class defines common data structures to be used across
* different application components
*/
class Structures {
    public:
        struct Customer{
            string id;
            string username;
            string fname;
            string lname;
            string dateOfBirth;
            int rewardPoints;
        };

        struct Transaction {
            int id;
            string customerId;
            vector<string> productId;
            double total;
            int pointsAwarded;
        };

        struct Product {
            string id;
            string name;
            double price;
            int availableItems;
        };
};

#endif