#include <bits/stdc++.h>

using namespace std;

class BankAccount{
    private:
    int balance;
    int userId;
    mutex mutex_;

    public:
    BankAccount(int userId){
        this->userId = userId;
        this->balance = 0;
    }

    void Deposit(int amount){
        lock_guard<mutex> lock(mutex_);
        this->balance += amount;
    }

    void Withdraw(int amount){
        lock_guard<mutex> lock(mutex_);
        try
        {
            if(amount > this->balance){
                throw(amount);
            }

            this->balance-= amount;
        }
        catch(int amount)
        {
            cout<<amount<<"is more than balance"<<endl;
        }
        
    }

    int GetBalance(){
        lock_guard<mutex> lock(mutex_);
        return this->balance;
    }
};

 
// Function to perform deposit operations
void PerformDeposits(BankAccount& account, int userId, int amount, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        account.Deposit(amount);
        cout << "User " << userId << " deposited " << amount << " (iteration " << i+1 << ")" << endl;
        // Simulate some delay between deposits
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Function to perform withdraw operations
void PerformWithdrawals(BankAccount& account, int userId, int amount, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        account.Withdraw(amount);
        cout << "User " << userId << " withdrew " << amount << " (iteration " << i+1 << ")" << endl;
        // Simulate some delay between withdrawals
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Function to perform balance checks
void PerformBalanceChecks(BankAccount& account, int userId, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        int balance = account.GetBalance();
        cout << "User " << userId << " checked balance: " << balance << " (iteration " << i+1 << ")" << endl;
        // Simulate some delay between balance checks
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    // Create a bank account object
    BankAccount account(123);

    // Number of threads and iterations for each operation
    const int numThreads = 3;
    const int iterations = 5;

    // Create vectors to hold thread objects
    vector<thread> depositThreads;
    vector<thread> withdrawThreads;
    vector<thread> balanceCheckThreads;

    // Start deposit threads
    for (int i = 0; i < numThreads; ++i) {
        depositThreads.push_back(thread(PerformDeposits, ref(account), i+1, 100, iterations));
    }

    // Start withdraw threads
    for (int i = 0; i < numThreads; ++i) {
        withdrawThreads.push_back(thread(PerformWithdrawals, ref(account), i+1, 50, iterations));
    }

    // Start balance check threads
    for (int i = 0; i < numThreads; ++i) {
        balanceCheckThreads.push_back(thread(PerformBalanceChecks, ref(account), i+1, iterations));
    }

    // Join all deposit threads
    for (auto& thread : depositThreads) {
        thread.join();
    }

    // Join all withdraw threads
    for (auto& thread : withdrawThreads) {
        thread.join();
    }

    // Join all balance check threads
    for (auto& thread : balanceCheckThreads) {
        thread.join();
    }

    // Final balance check after all operations
    cout << "Final balance after all operations: " << account.GetBalance() << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    return 0;
}