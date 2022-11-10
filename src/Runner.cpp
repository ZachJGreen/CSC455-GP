#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// File dependencies
#include "data.h"
#include "registrationManager.h"

using namespace std;
string customersFile = "../logs/customers.txt";
string productsFile = "../logs/products.txt";
string transactionsFile = "../logs/transactions.txt";

/**
 * Read file and perform appropriate parsing
 * 
 * @param filePath File path String
 * @return `bool` A boolean denoting if the values were successfully read
 */
bool ReadFileData(Data &data, string filePath) {
    Parser parse;
    ifstream readFile;
    readFile.open(filePath);
    if (readFile.is_open()) {
        cout << "Reading: " << filePath << endl;
        // Parse files
        if (filePath == customersFile) {
            data.customerData = parse.customerList(readFile);
        }
        else if (filePath == productsFile) {
            data.productData = parse.productList(readFile);
        }
        else if (filePath == transactionsFile) {
            data.transactionData = parse.transactionList(readFile);
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
bool WriteFileData(Data &data, string filePath) {
    Writer write;
    ofstream writeFile;
    writeFile.open(filePath);
    if (writeFile.is_open()) {
        cout << "Writing to: " << customersFile << endl;
        // Parse files
        if (filePath == customersFile) {
            write.customerList(data.customerData, writeFile);
        }
        else if (filePath == productsFile) {
            write.productList(data.productData, writeFile);
        }
        else if (filePath == transactionsFile) {
            write.transactionList(data.transactionData, writeFile);
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
    Data data;
    RegistrationManager regManager;
    // Read File Data into memory
    bool cutomersRead = ReadFileData(data, customersFile);
    bool productsRead = ReadFileData(data, productsFile);
    bool transactionsRead = ReadFileData(data, transactionsFile);


    // Store File Data to memory
    /*
    *   commenting out for now to avoid writing over files with blank values
    */
    WriteFileData(data, customersFile);
    WriteFileData(data, productsFile);
    WriteFileData(data, transactionsFile);
    return EXIT_SUCCESS;
}