# CSC455-GP
CSC 455 group project

## Coding practice Requirements:
* No more than one statement per line.
* You must use block indentation.
* All nesting of if statements should not exceed a depth of three.
* All if statements must have an else statement.
* Each function must be documented by specifying the role of that function and the meaning of each parameter and return values.
* Functions code should not exceed 35 statements.
* The cyclomatic complexity of any function should not exceed 10.
* Must reuse functions as much as possible.
* The project should not be implemented in a single cpp file. You must have at least four files.

### Registration Manager:
Customer registration service: for a user to benefit from the reward service, the user needs to
register. The customer needs to provide the following information:
* user name:
    * Consists of at least eight characters, flowed by at most three numbers.
    * Must be unique
* First name
    * Must be a string no longer than 15 characters.
    * Does not contain any numbers (0,1, ...) or other special characters (?, ¿, #, ...).
* Last name
    * Must be a string no longer than 15 characters.
    * Does not contain any numbers (0,1, ...) or other special characters (?, ¿, #, ...).
* Date of birth
    * Must be in MM–DD–YYYY format.
    * MM, DD, and YYYY are numbers.
* Credit card number:
    * Must be unique.
    * Must be in xxxx–xxxx–xxxx format.
    * xxxx are numbers.
* The system will assign a unique user ID to each user. this ID should satisfy
    * Must be unique.
    * Must start with ”CID”, followed with 10 digits.
* Reward points
    i. Must be a positive number

### Product Manager
The shop manager should be able to add and remove products from inventory. Each product should have the following information
* Product ID:
    * Must start with ’P’ followed by a five-digit number.
    * Must be unique.
* Product name (description)
* Product price
* The number product items currently available in store
    * Must be a positive number.

### Reward Manager
This service allows the manager to specify the following
* The number of points awarded for a given shopping amount.
* The gifts that can be redeemed given the total number of reward points.

### Menu System
A menu system that provide the following options
* Customer registration.
* Customer Removal.
* Product addition.
* Product removal.
* Shopping.
* View customer using customer ID.
* Redeem rewards

### Logging
All data must be saved and loaded from a txt file
Save these to the logs directory, there are template files for reference
* customers.txt
* products.txt
* transactions.txt