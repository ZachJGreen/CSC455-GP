#ifndef DATA
#define DATA

#include <iostream>
#include <string>
#include <vector>
#include <regex>
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

class Parser {
    public:
        vector<Structures::Customer> customerData;
        vector<Structures::Product> productData;
        vector<Structures::Transaction> transactionData;
        /**
         * Parse customer data from file to vector
         * 
         * @param parseFile File whos values are to be parsed into Customer objects
         * @return `vector<Structures::Customer>` A vector of parsed Customer objects
         */
        vector<Structures::Customer> customerList(ifstream& parseFile) {
            string line;
            vector<Structures::Customer> customers;
            if (parseFile.is_open()) {
                Structures::Customer readCustomer = Structures::Customer();
                while ( getline(parseFile, line) ) {
                    if(regex_search(line, customerIdRegex)) {
                        readCustomer.id = getLastValue(line);
                    }
                    else if(regex_search(line, customerUsernameRegex)) {
                        readCustomer.username = getLastValue(line);
                    }
                    else if(regex_search(line, customerFNameRegex)) {
                        readCustomer.fname = getLastValue(line);
                    }
                    else if(regex_search(line, customerLNameRegex)) {
                        readCustomer.lname = getLastValue(line);
                    }
                    else if(regex_search(line, customerDobRegex)) {
                        readCustomer.dateOfBirth = getLastValue(line);
                    }
                    else if(regex_search(line, customerRewardRegex)) {
                        readCustomer.rewardPoints = stoi(getLastValue(line));
                    }
                    else {
                        // New line, start next object parse
                        customers.push_back(readCustomer);
                        readCustomer = Structures::Customer();
                    }
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return customers;
        };
        /**
         * Parse transaction data from file to vector
         * 
         * @param parseFile File whos values are to be parsed into Transaction objects
         * @return `vector<Structures::Transaction>` A vector of parsed Transaction objects
         */
        vector<Structures::Transaction> transactionList(ifstream& parseFile) {
            string line;
            vector<Structures::Transaction> transactions;
            if (parseFile.is_open()) {
                Structures::Transaction readTransaction = Structures::Transaction();
                while ( getline(parseFile, line) ) {
                    if(regex_search(line, transactionIdRegex)) {
                        readTransaction.id = stoi(getLastValue(line));
                    }
                    else if(regex_search(line, transactionUserRegex)) {
                        readTransaction.customerId = getLastValue(line);
                    }
                    else if(regex_search(line, transactionProductRegex)) {
                        readTransaction.productIds = parseTransactionProducts(line);
                    }
                    else if(regex_search(line, transactionTotalRegex)) {
                        readTransaction.total = stod(getLastValue(line));
                    }
                    else if(regex_search(line, transactionRewardsRegex)) {
                        readTransaction.pointsAwarded = stoi(getLastValue(line));
                    }
                    else {
                        // New line, start next object parse
                        transactions.push_back(readTransaction);
                        readTransaction = Structures::Transaction();
                    }
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return transactions;
        }
        /**
         * Parse product data from file to vector
         * 
         * @param parseFile File whos values are to be parsed into Product objects
         * @return `vector<Structures::Product>` A vector of parsed Product objects
         */
        vector<Structures::Product> productList(ifstream& parseFile) {
            string line;
            vector<Structures::Product> products;
            if (parseFile.is_open()) {
                Structures::Product readProduct = Structures::Product();
                while ( getline(parseFile, line) ) {
                    if(regex_search(line, productIdRegex)) {
                        readProduct.id = getLastValue(line);
                    }
                    else if(regex_search(line, productNameRegex)) {
                        readProduct.name = getLastValue(line);
                    }
                    else if(regex_search(line, productPriceRegex)) {
                        readProduct.price = stod(getLastValue(line));
                    }
                    else if(regex_search(line, productAvailableRegex)) {
                        readProduct.availableItems = stoi(getLastValue(line));
                    }
                    else {
                        // New line, start next object parse
                        products.push_back(readProduct);
                        readProduct = Structures::Product();
                    }
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return products;
        };
        private:
            regex customerIdRegex = regex("customer ([0-9]+) ID ");
            regex customerUsernameRegex = regex("customer ([0-9]+) user name");
            regex customerFNameRegex = regex("customer ([0-9]+) first name ");
            regex customerLNameRegex = regex("customer ([0-9]+) last name ");
            regex customerDobRegex = regex("customer ([0-9]+) date of birth ");
            regex customerRewardRegex = regex("customer ([0-9]+) total reward points ");

            regex productIdRegex = regex("product ([0-9]+) ID ");
            regex productNameRegex = regex("product ([0-9]+) name ");
            regex productPriceRegex = regex("product ([0-9]+) price ");
            regex productAvailableRegex = regex("product ([0-9]+) total items in store ");

            regex transactionIdRegex = regex("Transaction ID ");
            regex transactionUserRegex = regex("User ID ");
            regex transactionProductRegex = regex("Product ([0-9]+) ID ");
            regex transactionTotalRegex = regex("Total amount ");
            regex transactionRewardsRegex = regex("Total reward points ");

            /**
             * Returns the last element in a string of space seperated words
             * 
             * @param valueString String to find last value of
             * @param delimiter Optional parameter to split string based on - defaults to " "
             * @return `string` The last element in the string
             */
            string getLastValue(string valueString, string delimiter = " ") {
                vector<string> elems;
                size_t pos = 0;
                while ((pos = valueString.find(delimiter)) != string::npos) {
                    elems.push_back(valueString.substr(0, pos));
                    valueString.erase(0, pos + delimiter.length());
                }
                return valueString;
            }

             /**
             * Returns a vector of product ids
             * 
             * @param valueString String to turn into product id vector
             * @return `vector<string>` A vector of product ids
             */
            vector<string> parseTransactionProducts (string valueString) {
                string delimiter = ", ";
                vector<string> productIds;
                int start = 0;
                int end = valueString.find(delimiter);
                while (end != -1) {
                    productIds.push_back(getLastValue(valueString.substr(start, end - start)));
                    start = end + delimiter.size();
                    end = valueString.find(delimiter, start);
                }
                return productIds;
            }

};

class Writer {
    public:
        /**
         * Write customer data from vector to file
         * 
         * @param writeFile File to write the values of the Customer vector to
         * @return `bool` A boolean denoting if values were successfully written
         */
        void customerList(vector<Structures::Customer> customerData, ofstream& writeFile){
            if (writeFile.is_open()) {
                for (int i = 0; i < customerData.size(); i++) {
                    writeFile << "customer " << i+1 << " ID " << customerData[i].id << endl;
                    writeFile << "customer " << i+1 << " user name " << customerData[i].username << endl;
                    writeFile << "customer " << i+1 << " first name " << customerData[i].fname << endl;
                    writeFile << "customer " << i+1 << " last name " << customerData[i].lname << endl;
                    writeFile << "customer " << i+1 << " date of birth " << customerData[i].dateOfBirth << endl;
                    writeFile << "customer " << i+1 << " total reward points " << customerData[i].rewardPoints << endl;
                    writeFile << "-" << endl;
                }
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
        /**
         * Write transaction data from vector to file
         * 
         * @param writeFile File to write the values of the Transaction vector to
         * @return `bool` A boolean denoting if values were successfully written
         */
        void transactionList(vector<Structures::Transaction> transactionData, ofstream& writeFile){
            if (writeFile.is_open()) {
                for (auto customer : transactionData) {
                    writeFile << "Transaction ID " << " ID " << customer.id << endl;
                    writeFile << "User ID " << customer.customerId << endl;
                    stringstream products;
                    for(int i = 0; i < customer.productIds.size(); i++) {
                        products << "Product " << i+1 << " ID " << customer.productIds[i] << ", ";
                    }
                    string productsString = products.str();
                    writeFile << productsString << endl;
                    writeFile << "Total amount " << customer.total << endl;
                    writeFile << "Total reward points " << customer.pointsAwarded << endl;
                    writeFile << "-" << endl;
                }
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
        /**
         * Write product data from vector to file
         * 
         * @param writeFile File to write the values of the Product vector to
         * @return `bool` A boolean denoting if values were successfully written
         */
        void productList(vector<Structures::Product> productData, ofstream& writeFile){
            if (writeFile.is_open()) {
                for (int i = 0; i < productData.size(); i++) {
                    writeFile << "product " << i+1 << " ID " << productData[i].id << endl;
                    writeFile << "product " << i+1 << " name " << productData[i].name << endl;
                    writeFile << "product " << i+1 << " price " << productData[i].price << endl;
                    writeFile << "product " << i+1 << " total items in store " << productData[i].availableItems << endl;
                    writeFile << "-" << endl;
                }
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
};

#endif