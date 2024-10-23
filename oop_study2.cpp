#include <iostream>
#include <string>
#include <map>

class Store{
    public:
        std::map<std::string, int> items = {
            {"apple", 10},
            {"orange", 15},
            {"cherry", 15},
            {"grapes", 20},
            {"strawberry", 30}
        };
        void display_items();
};

void Store::display_items(){
    std::cout << "------MY STORE------" << std::endl;
    for (auto item: items){
        std::cout << item.first << " - " << item.second << "\n";
    }
}

class Calculation : public Store{
    private:
        float total_price = 0;

    public:
        std::map<std::string, int> total_cart;
        void calculation();

};

/*
void Calculation::calculation(){
    total_price = 0;
    for (auto item: cart){
        std::string product = item.first;
        total_cart[product] = cart[product] * items[product];
    }
}
*/

class Customer : public Calculation{
    public:
        std::string card;
        float money;
        std::map<std::string, int> cart;

        Customer(std::string x, float y){
            card = x;
            money = y;
        }

        std::string user_pick();

        void display_cart();

        void checker();

        void store_buy();

};

std::string Customer::user_pick(){
    std::string user;
    std::cout << "Enter Item: ";
    std::cin >> user;
    
    return user;
}

void Customer::display_cart(){
    std::cout << "------Your Items------";
    for (auto item: cart){
        std::cout << item.first << " - " << item.second << "\n";
    }
}

/*
void Customer::checker(){

}
*/

void Customer::store_buy(){
    
}




int main(){
    Store obj;
    Customer customer("loyalty", 100.0);

    obj.display_items();
    
    return 0;
}