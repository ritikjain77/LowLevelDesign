#include <iostream>
#include <vector>
#include <algorithm>

class BasePizza{
    public:
    virtual int cost() = 0;
    virtual ~BasePizza() {}
};

class Toppings: public BasePizza{
    public:
    virtual int cost() = 0;
};

class ExtraCheese: public Toppings{
    public:
     BasePizza *obj;
    static int price;
     ExtraCheese(BasePizza *obj){
         this->obj = obj;
     }
     int cost() override{
         return obj->cost() + this->price;
     }
};

class ExtraPaneer: public Toppings{
    public:
     BasePizza *obj;
    static int price;
    ExtraPaneer(BasePizza *obj){
         this->obj = obj;
     }
     
     int cost() override{
         return obj->cost() + this->price;
     }
};

class ThinCrust: public Toppings{
    public:
     BasePizza *obj;
    static int price;
    ThinCrust(BasePizza *obj){
         this->obj = obj;
     }
     
     int cost() override{
         return obj->cost() + this->price;
     }
};

class VegDelight: public BasePizza{
    public:
    static int price;
    int cost() override{
        return this->price;
    }
};

class Margherita: public BasePizza{
    public:
    static int price;
    int cost() override{
        return this->price;
    }
};

class FarmHouse: public BasePizza{
    public:
    static int price;
    int cost() override{
        return this->price;
    }
};


int Margherita::price = 110;
int VegDelight::price = 150;
int FarmHouse::price = 210;
int ExtraCheese::price = 40;
int ExtraPaneer::price = 60;
int ThinCrust::price = 90;




int main() {
    BasePizza *pizza = new ThinCrust(new ExtraPaneer(new FarmHouse));
    cout<<pizza->cost();

    return 0;
}
