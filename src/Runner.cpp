#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <string>
#include <list>

// File dependencies
#include "data.h"

using namespace std;
string customersFile = "../logs/customers.txt";
string productsFile = "../logs/products.txt";
string transactionsFile = "../logs/transactions.txt";

class Parser {
    public:
        /**
         * Parse customer data from file to list
         * 
         * @param parseFile File whos values are to be parsed into Customer objects
         * @return `list<Structures::Customer>` A list of parsed Customer objects
         */
        list<Structures::Customer> customerList(ifstream& parseFile) {
            string line;
            list<Structures::Customer> customers;
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
                parseFile.clear();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return customers;
        };
        /**
         * Parse transaction data from file to list
         * 
         * @param parseFile File whos values are to be parsed into Transaction objects
         * @return `list<Structures::Transaction>` A list of parsed Transaction objects
         */
        list<Structures::Transaction> transactionList(ifstream& parseFile) {
            string line;
            list<Structures::Transaction> transactions;
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
                        readTransaction.productId = parseTransactionProducts(line);
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
                    // Temp cout, parse through data and convert to correct object
                    cout << line << endl;
                }
                cout << transactions.size() << endl;
                parseFile.close();
                parseFile.clear();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return transactions;
        }
        /**
         * Parse product data from file to list
         * 
         * @param parseFile File whos values are to be parsed into Product objects
         * @return `list<Structures::Product>` A list of parsed Product objects
         */
        list<Structures::Product> productList(ifstream& parseFile) {
            string line;
            list<Structures::Product> products;
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
                        cout << "Weird Line: " << line << endl;
                        // New line, start next object parse
                        products.push_back(readProduct);
                        readProduct = Structures::Product();
                    }
                }
                cout << products.size() << endl;
                parseFile.close();
                parseFile.clear();
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

            string getLastValue(string valueString, string delimiter = " ") {
                cout << "Getting last value of: " << valueString << endl;
                vector<string> elems;
                size_t pos = 0;
                while ((pos = valueString.find(delimiter)) != string::npos) {
                    elems.push_back(valueString.substr(0, pos));
                    valueString.erase(0, pos + delimiter.length());
                }
                cout << "EndItem: " << valueString << endl;
                return valueString;
            }

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
     * Write customer data from list to file
     * 
     * @param writeFile File to write the values of the Customer list to
     * @return `bool` A boolean denoting if values were successfully written
     */
        void customerList(ofstream& writeFile){
            if (writeFile.is_open()) {
                // Writer info goes here
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
    /**
     * Write transaction data from list to file
     * 
     * @param writeFile File to write the values of the Transaction list to
     * @return `bool` A boolean denoting if values were successfully written
     */
        void transactionList(ofstream& writeFile){
            if (writeFile.is_open()) {
                // Writer info goes here
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
    /**
     * Write product data from list to file
     * 
     * @param writeFile File to write the values of the Product list to
     * @return `bool` A boolean denoting if values were successfully written
     */
        void productList(ofstream& writeFile){
            if (writeFile.is_open()) {
                // Writer info goes here
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
};
/**
 * Read file and perform appropriate parsing
 * 
 * @param filePath File path String
 * @return `bool` A boolean denoting if the values were successfully read
 */
bool ReadFileData(string filePath) {
    Parser parse;
    ifstream readFile;
    readFile.open(filePath);
    if (readFile.is_open()) {
        cout << "Reading: " << filePath << endl;
        // Parse files
        if (filePath == customersFile) {
            parse.customerList (readFile);
        }
        else if (filePath == productsFile) {
            parse.productList(readFile);
        }
        else if (filePath == transactionsFile) {
            parse.transactionList(readFile);
        }
        else {
            cout << "Error: attempted to parse an invalid file" << endl;
            readFile.close();
            return false;
        }
    } else {
        cout << "Could not Read: " << customersFile << endl;
        // File unable to be opened
        readFile.close();
        return false;
    }
    readFile.close();
    readFile.clear();
    filePath.clear();
    return true;
}

/**
 * Write to appropriate file
 * 
 * @param filePath File path String
 * @return `bool` A boolean denoting if the values were successfully written
 */
bool WriteFileData(string filePath) {
    Writer write;
    ofstream writeFile;
    writeFile.open(filePath);
    if (writeFile.is_open()) {
        cout << "Writing to: " << customersFile << endl;
        // Parse files
        if (filePath == customersFile) {
            write.customerList (writeFile);
        }
        else if (filePath == productsFile) {
            write.productList(writeFile);
        }
        else if (filePath == transactionsFile) {
            write.transactionList(writeFile);
        }
        else {
            cout << "Error: attempted to write to an invalid file" << endl;
            writeFile.close();
            return false;
        }
    } else {
        cout << "Could not Write to: " << customersFile << endl;
        // File unable to be opened
        writeFile.close();
        return false;
    }
    return true;
}

/**
 * Application main function
 * 
 * @return `int` Exit code
 */
int main() {
    // Read File Data into memory
    bool cutomersRead = ReadFileData(customersFile);
    bool productsRead = ReadFileData(productsFile);
    bool transactionsRead = ReadFileData(transactionsFile);

    // Store File Data to memory
    /*
    *   commenting out for now to avoid writing over files with blank values
    */
    // WriteFileData(customersFile);
    // WriteFileData(productsFile);
    // WriteFileData(transactionsFile);
    return EXIT_SUCCESS;
}