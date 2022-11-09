#ifndef DATA
#define DATA

#include <iostream>
#include <string>
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
            vector<string> productIds;
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

class Data {
    public:
        vector<Structures::Customer> customerData;
        vector<Structures::Product> productData;
        vector<Structures::Transaction> transactionData;
};

#endif