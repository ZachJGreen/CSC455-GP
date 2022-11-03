#include <iostream>
#include <fstream>
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
            if (parseFile.is_open()) {
                while ( getline(parseFile, line) ) {
                    // Temp cout, parse through data and convert to correct object
                    cout << line << endl;
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        };
        /**
         * Parse transaction data from file to list
         * 
         * @param parseFile File whos values are to be parsed into Transaction objects
         * @return `list<Structures::Transaction>` A list of parsed Transaction objects
         */
        list<Structures::Transaction> transactionList(ifstream& parseFile) {
            string line;
            if (parseFile.is_open()) {
                while ( getline(parseFile, line) ) {
                    // Temp cout, parse through data and convert to correct object
                    cout << line << endl;
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
    /**
     * Parse product data from file to list
     * 
     * @param parseFile File whos values are to be parsed into Product objects
     * @return `list<Structures::Product>` A list of parsed Product objects
     */
        list<Structures::Product> productList(ifstream& parseFile) {
            string line;
            if (parseFile.is_open()) {
                while ( getline(parseFile, line) ) {
                    // Temp cout, parse through data and convert to correct object
                    cout << line << endl;
                }
                parseFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        };
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
        cout << "Reading: " << customersFile << endl;
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
    ReadFileData(customersFile);
    ReadFileData(productsFile);
    ReadFileData(transactionsFile);

    // Store File Data to memory
    /*
    *   commenting out for now to avoid writing over files with blank values
    */
    // WriteFileData(customersFile);
    // WriteFileData(productsFile);
    // WriteFileData(transactionsFile);
    return EXIT_SUCCESS;
}