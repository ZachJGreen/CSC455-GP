#ifndef DATA
#define DATA

#include <iostream>
#include <string>
#include <list>
using namespace std;
class Structures {
    public:
        struct Customer{
            string id;
            string username;
            string fname;
            string lname;
            time_t dateOfBirth;
            string ccinfo;
            int rewardPoints;
        };

        struct Transaction {
            int id;
            string customerId;
            list<string> productId;
            double total;
            int pointsAwarded;
        };

        struct Product {
            string productId;
            string productName;
            double productPrice;
            int availableItems;
        };
};

#endif