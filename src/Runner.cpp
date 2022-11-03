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
        void customerList(ofstream& writeFile){
            if (writeFile.is_open()) {
                // Writer info goes here
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
        void transactionList(ofstream& writeFile){
            if (writeFile.is_open()) {
                // Writer info goes here
                writeFile.close();
            } else {
                cout << "Error: attempted to access an unopened file" << endl;
            }
            return;
        }
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

bool ReadFileData(string fileName) {
    Parser parse;
    ifstream readFile;
    readFile.open(fileName);
    if (readFile.is_open()) {
        cout << "Reading: " << customersFile << endl;
        // Parse files
        if (fileName == customersFile) {
            parse.customerList (readFile);
        }
        else if (fileName == productsFile) {
            parse.productList(readFile);
        }
        else if (fileName == transactionsFile) {
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

bool WriteFileData(string fileName) {
    Writer write;
    ofstream writeFile;
    writeFile.open(fileName);
    if (writeFile.is_open()) {
        cout << "Writing to: " << customersFile << endl;
        // Parse files
        if (fileName == customersFile) {
            write.customerList (writeFile);
        }
        else if (fileName == productsFile) {
            write.productList(writeFile);
        }
        else if (fileName == transactionsFile) {
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