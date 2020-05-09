#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum PizzaSize {
    SMALL = 25,
    MIDDLE = 30,
    BIG = 35,
    GIANT = 40
};

class Pizza {
protected:
    string name;
    string description;
    PizzaSize size;
    unsigned int price;
    unsigned int salt;
    unsigned int cheese;
public:
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual unsigned int getPrice() const = 0;
    virtual PizzaSize getSize() const = 0;
    virtual unsigned int getSalt() const = 0;
    virtual unsigned int getCheese() const = 0;
};


class Classic : public Pizza {
public:
    Classic(PizzaSize size, unsigned int salt, unsigned int cheese) {
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
    PizzaSize getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == SMALL) || (size == MIDDLE)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == BIG) || (size == GIANT)) {
            return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
    }
};

class SpicyPizza : public Pizza {
public:
    SpicyPizza(PizzaSize size, unsigned int salt, unsigned int cheese) {
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
        PizzaSize getSize() const override {
            return size;
        }
        unsigned int getCheese() const override {
                return cheese;
        }
        unsigned int getSalt() const override {
                return salt;
        }
        unsigned int getPrice() const override {
                if((size == SMALL) || (size == MIDDLE)) {
                    return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
                }
                else if((size == BIG) || (size == GIANT)) {
                    return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
                }
        }
};

class FourCheese : public Pizza {
public:
    FourCheese(PizzaSize size, unsigned int salt, unsigned int cheese) {
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
    PizzaSize getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == SMALL) || (size == MIDDLE)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == BIG) || (size == GIANT)) {
            return 400 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
    }
};

class Margarita : public Pizza {
public:
    Margarita(PizzaSize size, unsigned int salt, unsigned int cheese) {
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
    PizzaSize getSize() const override {
        return size;
    }
    unsigned int getCheese() const override {
        return cheese;
    }
    unsigned int getSalt() const override {
        return salt;
    }
    unsigned int getPrice() const override {
        if((size == SMALL) || (size == MIDDLE)) {
            return 350 + getSize() + getCheese() * 3 + getSalt() * 1;
        }
        else if((size == BIG) || (size == GIANT)) {
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
    void Selection() {
        OrderNew:
        cout << "Menu:" << endl;
        cout << "1. Classic - 350" << endl;
        cout << "2. SpicyPizza - 375" << endl;
        cout << "3. FourCheese - 350" << endl;
        cout << "4. Margarita - 360" << endl;

        int choice;
        unsigned int type = 0;
        cin >> choice;

        switch(choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            {
                type = choice;
            }
                break;
        }

        PizzaSize pizzaSize;

        ChooseSize:
        cout << "--------------------------------------------------" << endl;
        cout << "Size of pizza:" << endl;
        cout << "1. Small - 25" << endl;
        cout << "2. Middle - 30" << endl;
        cout << "3. Big - 35" << endl;
        cout << "4. Giant - 40" << endl;

        cin >> choice;
        switch(choice) {
            case 1: {
                pizzaSize = SMALL;
            }
                break;
            case 2: {
                pizzaSize = MIDDLE;
            }
                break;
            case 3: {
                pizzaSize = BIG;
            }
                break;
            case 4: {
                pizzaSize = GIANT;
            }
                break;
        }

        unsigned int aSalt = 0;
        unsigned int aCheese = 0;

        ChooseTopping:
        cout << "1. Add salt" << endl;
        cout << "2. Add cheese" << endl;
        cout << "3. Nothing" << endl;

        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "How much?" << endl;
                cin >> aSalt;
            }
                break;
            case 2: {
                cout << "How much?" << endl;
                cin >> aCheese;
            }
                break;
            case 3: {
            }
                break;
        }

        switch(type) {
            case 1: {
                add(new Classic(pizzaSize, aSalt, aCheese));
            }
                break;
            case 2: {
                add(new SpicyPizza(pizzaSize, aSalt, aCheese));
            }
                break;
            case 3: {
                add(new FourCheese(pizzaSize, aSalt, aCheese));
            }
                break;
            case 4: {
                add(new Margarita(pizzaSize, aSalt, aCheese));
            }
                break;
        }
    }
};

int main() {
    Order order;
    Classic c(SMALL);
    c.getCheese(3);
    c.getSalt(1);
    order.add(&c);
    return 0;
}
