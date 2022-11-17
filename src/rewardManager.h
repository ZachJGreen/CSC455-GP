#include "data.h"
#include <map>
using namespace std;

class RewardManager
{
public:
    struct Gift
    {
        Structures::Product product;
        int points;
    };

    //<product, redeem_amount>
    map<Structures::Product, int> giftList;
    void specifyRewardAmount(Structures::Product& product, int rewardAmount)
    {
        product.rewardAmount = rewardAmount;
    };

    void addGift(Structures::Product product, int points)
    {

        if (giftList.count(product) == 0)
        {
            giftList.insert(std::pair<Structures::Product, int>(product, points));
        }
        else if (giftList.count(product) > 0)
        {
            giftList[product] = points;
        };
    };

    void removeGift(Structures::Product product)
    {
        giftList.erase(product);
    };

    vector<Structures::Product> getPossibleGifts(Structures::Customer customer)
    {
        vector<Structures::Product> possible_gifts;
        //check which gifts the customer can redeem
        map<Structures::Product, int>::iterator it;
        for (it = giftList.begin(); it != giftList.end(); it++)
        {
            if (customer.rewardPoints >= it->second)
            {
                possible_gifts.push_back(it->first);
            }
        }

        return possible_gifts;
    }
}