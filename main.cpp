#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pizza {
protected:
    string name;
    string description;
    unsigned int size;
    unsigned int price;
    unsigned int salt;
    unsigned int cheese;
public:
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual unsigned int getPrice() const = 0;
    virtual unsigned int getSize() const = 0;
    virtual unsigned int getSalt() const = 0;
    virtual unsigned int getCheese() const = 0;
};


class Classic : public Pizza {
public:
    Classic(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->name = "Classic";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
    }
    string getName() const override {
        return "Classic";
    };
    string getDescription() const override {
        return "scone, sauce, sausage, tomatoes, cheese";
    };

    unsigned int getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == 25) || (size == 30)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == 35) || (size == 40)) {
            return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
    }
};

class SpicyPizza : public Pizza {
public:
    SpicyPizza(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->name = "SpicyPizza";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
    }
        string getName() const override {
                return "SpicyPizza";
        };
        string getDescription() const override {
                return "scone, sauce, chicken, tomatoes, hot pepper, cheese";
        };

        unsigned int getSize() const override {
            return size;
        }
        unsigned int getCheese() const override {
                return cheese;
        }
        unsigned int getSalt() const override {
                return salt;
        }
        unsigned int getPrice() const override {
                if((size == 25) || (size == 30)) {
                    return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
                }
                else if((size == 35) || (size == 40)) {
                    return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
                }
        }
};

class FourCheese : public Pizza {
public:
    FourCheese(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->name = "FourCheese";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
    }
    string getName() const override {
        return "FourCheese";
    };
    string getDescription() const override {
        return "scone, brie, mozzarella, parmesan, ricotta";
    };
    unsigned int getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == 25) || (size == 30)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == 35) || (size == 40)) {
            return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
    }
};

class Margarita : public Pizza {
public:
    Margarita(unsigned int size, unsigned int salt, unsigned int cheese) {
        this->name = "Margarita";
        this->size = size;
        this->cheese = cheese;
        this->salt = salt;
    }
    string getName() const override {
        return "Margarita";
    };
    string getDescription() const override {
        return "scone, tomato sauce, mozzarella, tomato, basil";
    };
    unsigned int getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == 25) || (size == 30)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == 35) || (size == 40)) {
            return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
    }
};

class Order {
private:
    vector<const Pizza *> orderPizza;

public:
    void add(const Pizza *pizza) {
        orderPizza.push_back(pizza);
    }

    void PrintOrder() {
        unsigned int eprice = 0;
        int opizza = orderPizza.size();
        for(int i = 0; i < orderPizza.size(); i++) {
            cout << i + 1 << " . " <<
                 orderPizza[i]->getName() <<
                 orderPizza[i]->getDescription() <<
                 " size" << orderPizza[i]->getSize() <<
                 ", amount of salt" << orderPizza[i]->getSalt() <<
                 ", amount of cheese" << orderPizza[i]->getCheese() <<
                 ". Price for pizza - " << orderPizza[i]->getPrice() << endl;
            eprice = eprice + orderPizza[i]->getPrice();
        }
        cout << "Final price " << eprice << endl;
    }
};

int main() {
    cout << "Menu:" << endl;
    cout << "1. Classic - 350" << endl;
    cout << "2. SpicyPizza - 375" << endl;
    cout << "3. FourCheese - 350" << endl;
    cout << "4. Margarita - 360" << endl;

    Order order;

    cout << "Enter the number of the selected pizza" << endl;
    int choice;
    unsigned int size, salt, cheese;
    cin >> choice;
    while((choice > 0) && (choice < 5)) {
        cout << "--------------------------------------------------" << endl;
        cout << "Size of pizza:" << endl;
        cout << "1. Small - 25" << endl;
        cout << "2. Middle - 30" << endl;
        cout << "3. Big - 35" << endl;
        cout << "4. Giant - 40" << endl;
        cout << "Enter the size of the selected pizza" << endl;
        cin >> size;
        switch(size) {
            case 1: {
                size = 25;
            }
                break;
            case 2: {
                size = 30;
            }
                break;
            case 3: {
                size = 35;
            }
                break;
            case 4: {
                size = 40;
            }
                break;
        }
        cout << "Enter the amount of salt and cheese" << endl;
        cin >> salt, cheese;
    }
    switch(choice) {
        case 1: {
            order.add(new Classic(size, salt, cheese));
        }
            break;
        case 2: {
            order.add(new SpicyPizza(size, salt, cheese));
        }
            break;
        case 3: {
            order.add(new FourCheese(size, salt, cheese));
        }
            break;
        case 4: {
            order.add(new Margarita(size, salt, cheese));
        }
            break;
    }
    return 0;
}
