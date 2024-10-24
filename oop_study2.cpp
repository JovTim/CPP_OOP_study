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

        void calculation(const std::map<std::string, int>& cart);

        void total_display();

        void change(float& money);

};


void Calculation::calculation(const std::map<std::string, int>& cart){
    total_price = 0;
    for (auto item: cart){
        std::string product = item.first;
        int quantity = item.second;

        total_cart[product] = quantity * items[product];
        total_price += total_cart[product];
    }
}

void Calculation::total_display(){
    std::cout << "------RECEIPT------" << std::endl;
    for (auto item: total_cart){
        std::cout << item.first << " - " << item.second << std::endl;
    }
    std::cout << "TOTAL AMOUNT: " << total_price << std::endl;
}

void Calculation::change(float& money){
    if (money >= total_price){
        std::cout << "Change: " << money - total_price << std::endl;
    }
    else{
        system("cls");
        std::cout << "NOT ENOUGH MONEY!" << std::endl;
    }
}


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

        void checker(std::string item);

        void store_buy();

};

std::string Customer::user_pick(){
    std::string user;
    std::cout << "Enter Item: ";
    std::cin >> user;
    
    return user;
}

void Customer::display_cart(){
    std::cout << "------Your Items------" << std::endl;
    for (auto item: cart){
        std::cout << item.first << " - " << item.second << "\n";
    }
}


void Customer::checker(std::string item){
    if (Store().items.count(item) > 0){
        if (cart.count(item) > 0){
            cart[item] += 1;
        }
        else{
            cart[item] = 1;
        }
    }
    else{
        std::cout << "Item no available!" << std::endl;
    }
}


void Customer::store_buy(){
    system("cls");
    Store().display_items();
    while (true){
        std::string user;
        user = user_pick();
        if (user == "end"){
            calculation(cart);
            total_display();
            change(money);
            break;

        }
        else{
            system("cls");
            Store().display_items();
            checker(user);
            display_cart();
            std::cout << std::endl;
        }
    }

}

int main(){
    Store obj;
    Customer customer("loyalty", 100.0);

    customer.store_buy();
    
    return 0;
}