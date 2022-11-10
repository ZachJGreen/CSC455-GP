#include <algorithm>
#include <cstdlib>

// File dependencies
#include "data.h"

using namespace std;


namespace Product {
    class ProductManager {

        public:

        /** Generate random product ID
         *
         * @return `string` A randomly generated ID for a new product.
        **/ 
        string generate_id() {
            string pid = "P";
            string id = "";
            srand((unsigned) time(0));
            for (int i = 0; i < 5; i++) {
                int random = rand() % 10;
                id = pid + to_string(random);
            }
            return id;
        }

        /** validate a new unique product ID
         *
         * @param customerList A vector of product data
         * @return `string` A unique randomly generated ID for a new product.
        **/ 
        string validate_id(vector<Structures::Product> productList) {
            string id = "";
            bool valid = false;
        
            while(!valid) {
                id = generate_id();
                valid = none_of(productList.begin(), productList.end(), [&id](Structures::Product product) {
                    return product.id == id;
                });
            }
            return id;
        }

        /**
         *  Accept only alphanumeric values as valid inputs.
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the product name is valid
         **/
        bool validate_product_name(string str) {
            regex numbersMatcher = regex("^[a-zA-Z0-9_]+$");
            if(regex_search(str, numbersMatcher)){
                return true;
            } 
            else {
                cout << "\nPlease enter alphanumeric values only.\n";
                    return false;
            }
        }

        /**
         *  Check if the user inputs any special characters or letters. This includes a "-" in the beginning signifying a negative number..
         * 
         * @param str a string provided by the user
         * @return `bool` a boolean denoting if the product price and count in stock is valid
         **/
        bool validate_product_nums(string str) {
            regex numbersMatcher = regex("^/\\d+$");
            if(regex_search(str, numbersMatcher)){
                return true;
            } 
            else {
                cout << "\nPlease enter a positive numerical value (no letters or other characters).\n";
                    return false;
            }
        }
};
}