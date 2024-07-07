#include<bits/stdc++.h>

// Simplified PayPalGateway class representing the PayPal API
class PayPalGateway {
public:
    PayPalGateway(){}
    void makePayment(double amount) {
        std::cout << "Processing PayPal payment: $" << amount << std::endl;
        // Actual implementation of PayPal payment processing
    }

    void refundPayment(double amount) {
        std::cout << "Processing PayPal refund: $" << amount << std::endl;
        // Actual implementation of PayPal refund processing
    }

    bool getTransactionStatus(int transactionId) {
        std::cout << "Checking PayPal transaction status for ID: " << transactionId << std::endl;
        // Actual implementation of PayPal transaction status checking
        return true; // Placeholder return value
    }
};

// Simplified StripeGateway class representing the Stripe API
class StripeGateway {
public:
    void charge(double amount) {
        std::cout << "Charging $" << amount << " via Stripe" << std::endl;
        // Actual implementation of Stripe payment processing
    }

    void refund(double amount) {
        std::cout << "Refunding $" << amount << " via Stripe" << std::endl;
        // Actual implementation of Stripe refund processing
    }

    bool checkTransaction(int transactionId) {
        std::cout << "Checking Stripe transaction status for ID: " << transactionId << std::endl;
        // Actual implementation of Stripe transaction status checking
        return true; // Placeholder return value
    }
};

class InternalPaymentInterface {
    public:
    virtual void InitiatePayment(double amount) = 0;
    virtual void IntitateRefund(double amount) = 0;
    virtual bool CheckTransactionStatus(int transactionId) = 0;
};

class PaypalAdapter: public InternalPaymentInterface {
    private:
    PayPalGateway* gatewayPtr;

    public:
    PaypalAdapter(PayPalGateway* ptr){
        this->gatewayPtr = ptr;
    }
    virtual void InitiatePayment(double amount){
        gatewayPtr->makePayment(amount);
    };
    virtual void IntitateRefund(double amount){
        gatewayPtr->refundPayment(amount);
    }
    virtual bool CheckTransactionStatus(int transactionId){
        gatewayPtr->getTransactionStatus(transactionId);
    }
};

int main(){
    PayPalGateway* paypalGateway = new PaypalGateway();
    InternalPaymentInterface* paymentGateway = new PaypalAdapter(paypalGateway);
}