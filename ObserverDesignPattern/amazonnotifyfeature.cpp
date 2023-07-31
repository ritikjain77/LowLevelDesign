#include <iostream>
#include <vector>
#include <algorithm>

class StockObserver {
public:
    virtual void update() = 0;
    virtual ~StockObserver() {}
};

class StockObservable {
public:
    virtual void add(StockObserver* observer) = 0;
    virtual void remove(StockObserver* observer) = 0;
    virtual void notify() = 0;
    virtual void setStock(int quantity) = 0;
    virtual int getStock() = 0;
    virtual ~StockObservable() {} 
};

class Iphone : public StockObservable {
public:
    std::vector<StockObserver*> observers;
    int stock;

    void add(StockObserver* observer) override {
        observers.push_back(observer);
    }

    void remove(StockObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (StockObserver* obs : observers) {
            obs->update();
        }
    }

    void setStock(int quantity) override {
        this->stock = quantity;
        if (this->stock != 0) {
            this->notify();
        }
    }

    int getStock() override {
        return this->stock;
    }
};

class userObserver : public StockObserver {
    StockObservable* obj;
public:
    userObserver(StockObservable* obj) {
        this->obj = obj;
    }

    void update() override {
        std::cout << "stock is available" << std::endl;
    }
};

int main() {
    StockObservable* product1 = new Iphone();
    StockObserver* user1 = new userObserver(product1);
    StockObserver* user2 = new userObserver(product1);
    product1->add(user1);
    product1->add(user2);

    // Cast product1 to Iphone before accessing 'stock'
    static_cast<Iphone*>(product1)->stock = 0;
    std::cout << "Current stock: " << product1->getStock() << std::endl;

    product1->setStock(10);

    delete user1;
    delete user2;
    delete product1;

    return 0;
}
