#include <bits/stdc++.h>

using namespace std;

class BillingItem {
    private:
    string name;
    string id;
    double price;

    public:
    BillingItem(string name, string id, double price){
        this->id= id;
        this->price = price;
        this->name = name;
    }

    double GetPrice(){
        return this->price;
    }
};

class Invoice {
    private:
    string id;
    vector<BillingItem*> items;

    public:
    Invoice(string id){
        this->id = id;
    }

    Invoice(string id, vector<BillingItem*> items){
        this->items = items;
    }

    vector<BillingItem*> GetItems(){
        return this->items;
    } 
};

class Discount {
    public:
    virtual float CalculateDiscout(vector<BillingItem*> items) = 0;
};

class PercentageDiscount:Discount {
    private:
    float percentage;

    public:
    PercentageDiscount(float percentage){
        this->percentage = percentage;
    }

    float CalculateDiscount(vector<BillingItem*> items;) {
        float totalDiscount = 0;
        for(int i=0; i<items.size(); i++){
            totalDiscount += (items[0]->GetPrice() * percentage)/100.00;
        }

        return totalDiscount;
    }
};

class FlatDiscount:Discount {
    private:
    double flatDiscount;

    public:
    FlatDiscount(double discount){
        this->flatDiscount = discount;
    }

    float CalculateDiscount(vector<BillingItem*> items){
        return flatDiscount;
    }
};

class CostCalculator{
    public:
    double CalculateCost(vector<BillingItem*> items, Discount* discount){
        double initialCost = 0;
        for(auto item:items){
            initialCost += item->GetPrice();
        }

        double totalDiscount = discount->CalculateDiscout(items);

        return initialCost - totalDiscount;
    }
};