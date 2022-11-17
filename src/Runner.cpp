#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// File dependencies
#include "data.h"
#include "registrationManager.h"
#include "rewardManager.h"
#include "productManager.h"

using namespace std;
string customersFile = "../logs/customers.txt";
string productsFile = "../logs/products.txt";
string transactionsFile = "../logs/transactions.txt";

RegistrationManager regManager;

// Function calls for out of scope errors
void managerMenu();
void customerMenu();
void manageCustomers();

/**
 * Read file and perform appropriate parsing
 * 
 * @param filePath File path String
 * @return `bool` A boolean denoting if the values were successfully read
 */
bool ReadFileData(Data &data, string filePath)
{
    Parser parse;
    ifstream readFile;
    readFile.open(filePath);
    if (readFile.is_open())
    {
        cout << "Reading: " << filePath << endl;
        // Parse files
        if (filePath == customersFile)
        {
            data.customerData = parse.customerList(readFile);
        }
        else if (filePath == productsFile)
        {
            data.productData = parse.productList(readFile);
        }
        else if (filePath == transactionsFile)
        {
            data.transactionData = parse.transactionList(readFile);
        }
        else
        {
            cout << "Error: attempted to parse an invalid file" << endl;
            readFile.close();
            return false;
        }
    }
    else
    {
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
bool WriteFileData(Data &data, string filePath)
{
    Writer write;
    ofstream writeFile;
    writeFile.open(filePath);
    if (writeFile.is_open())
    {
        cout << "Writing to: " << customersFile << endl;
        // Parse files
        if (filePath == customersFile)
        {
            write.customerList(data.customerData, writeFile);
        }
        else if (filePath == productsFile)
        {
            write.productList(data.productData, writeFile);
        }
        else if (filePath == transactionsFile)
        {
            write.transactionList(data.transactionData, writeFile);
        }
        else
        {
            cout << "Error: attempted to write to an invalid file" << endl;
            writeFile.close();
            return false;
        }
    }
    else
    {
        cout << "Could not Write to: " << customersFile << endl;
        // File unable to be opened
        writeFile.close();
        return false;
    }
    return true;
}

// Beginning menu
void menu()
{
    bool running = true;
    while (running)
    {
        string choice;

        cout << "\nWelcome. Please select one of the following: \n"
             << "   1. Manager Actions\n"
             << "   2. Customer Actions\n"
             << "   3. Quit\n"
             << "Enter a number to select: ";
        cin >> choice;

        if (choice == "1")
        {
            managerMenu();
            running = false;
        }
        else if (choice == "2")
        {
            customerMenu();
            running = false;
        }
        else if (choice == "3")
        {
            cout << "Goodbye!\n";
            running = false;
        }
        else
        {
            cout << "That is not a valid selection.\n";
        }
    }
}

// Manager Menu
void managerMenu()
{
    bool running = true;
    while (running)
    {
        string choice;

        cout << "\nPlease select one of the following: \n"
             << "   1. Manage Customers\n"
             << "   2. Manage Products\n"
             << "   3. Go Back\n"
             << "   4. Quit\n"
             << "Enter a number to select: ";
        cin >> choice;

        if (choice == "1")
        {

            cout << "Calling customer management\n";
            running = false;
        }
        else if (choice == "2")
        {
            cout << "Calling product management\n";
            running = false;
        }
        else if (choice == "3")
        {
            menu();
            running = false;
        }
        else if (choice == "4")
        {
            cout << "Goodbye!\n";
            running = false;
        }
        else
        {
            cout << "\nThat is not a valid selection.\n";
        }
    }
}

// Customer Menu
void customerMenu()
{
    bool running = true;
    while (running)
    {
        string choice;

        cout << "\nPlease select one of the following: \n"
             << "   1. Shopping\n"
             << "   2. Redeem Rewards\n"
             << "   3. Go Back\n"
             << "   4. Quit\n"
             << "Enter a number to select: ";
        cin >> choice;

        if (choice == "1")
        {

            cout << "Calling shopping\n";
            running = false;
        }
        else if (choice == "2")
        {
            cout << "Calling redeem rewards\n";
            running = false;
        }
        else if (choice == "3")
        {
            menu();
            running = false;
        }
        else if (choice == "4")
        {
            cout << "Goodbye!\n";
            running = false;
        }
        else
        {
            cout << "\nThat is not a valid selection.\n";
        }
    }
}

void manageCustomers()
{
    bool running = true;
    while (running)
    {
        string choice;

        cout << "\nPlease select one of the following: \n"
             << "   1. Register a Customer\n"
             << "   2. Remove a Customer\n"
             << "   3. Search a Customer by ID\n"
             << "   4. Go Back\n"
             << "   5. Quit\n"
             << "Enter a number to select: ";
        cin >> choice;

        if (choice == "1")
        {
            cout << "Calling customer management\n";
            running = false;
        }
        else if (choice == "2")
        {
            cout << "Calling customer removal\n";
            running = false;
        }
        else if (choice == "3")
        {
            cout << "Calling customer search\n";
            running = false;
        }
        else if (choice == "4")
        {
            menu();
            running = false;
        }
        else if (choice == "5")
        {
            cout << "Goodbye!\n";
            running = false;
        }
        else
        {
            cout << "\nThat is not a valid selection.\n";
        }
    }
}

void manageProducts()
{
    /// Nothing so far
}

void registerCustomers()
{
    /// Nothing so far
}

void manageRewards(Data &d)
{
    bool running = true;
    string choice;
    while (running)
    {

        running = false;

        cout << "\nPlease select one of the following" << '\n'
             << "1. Specify number of points awarded" << '\n'
             << "2. Display Gifts" << '\n'
             << "3. Go Back" << '\n'
             << "4. Quit" << '\n'
             << "Enter a number to select: ";
        cin >> choice;

        if (choice == "1")
        {
        }
        else if (choice == "2")
        {
            getPossibleGifts()
        }
        else if (choice == "3")
        {
            manageProducts();
        }
        else if (choice == "4")
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "\nThat is not a valid selection.\n";
            running = true;
        }
    }
}

void enterNewRewardAmount(Data &d)
{
    string id, reward;
    ProductManager prodMan;
    RewardManager rewardMan;

    cout << "Enter Product ID: ";
    cin >> id;
    cout << "Enter Reward Amount: ";
    cin >> reward;

    auto vectorSearch = find_if(begin(d.productData), end(d.productData),
        [&id](const Structures::Product &product)
        {
            return product.id == id;
        });

    try
    {
        if (vectorSearch != end(d.productData))
            throw runtime_error("Product not found");

        int rewardInt = stoi(reward);
        throw invalid_argument("Invalid reward amount");

        if (rewardInt < 0)
            throw runtime_error("Cannot reward a negative value.");

        rewardMan.specifyRewardAmount(*vectorSearch, rewardInt);
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
}

/**
 * Application main function
 * 
 * @return `int` Exit code
 */
int main()
{
    Data data;
    // Read File Data into memory
    bool cutomersRead = ReadFileData(data, customersFile);
    bool productsRead = ReadFileData(data, productsFile);
    bool transactionsRead = ReadFileData(data, transactionsFile);

    menu();

    // Store File Data to memory
    /*
    *   commenting out for now to avoid writing over files with blank values
    */
    WriteFileData(data, customersFile);
    WriteFileData(data, productsFile);
    WriteFileData(data, transactionsFile);
    return EXIT_SUCCESS;
}