/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: Josh Lewis
 * Version: 2/7/2018
 */

#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    
    char answer;
    CDAccount account;
    
    
    do {
        cout << "Please enter your account information below: ";
        account.input(cin);
        account.output(cout);
        cout << "Would you like to run another calculation? (Y/N): ";
        cin >> answer;
        while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
        {
            cout << "Not a valid entry. Please enter Y or N: ";
            cin >> answer;
        }
        
    } while (answer == 'Y' || answer == 'y');
    
    if (answer == 'n' || answer == 'N')
        cout << "Goodbye!";

    return 0;
    
    // You implement the test code here
    // You may watch the video note to get the idea
    // notice that user will only enter balance as a double value
    // You may implement it as a menu oriented testing program
    // which be able to test constructors, methods of CDAccount class
}

CDAccount::CDAccount()
{
    dollar = 0;
    cent = 0;
    interest_rate = 0;
    term = 0;
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    dollar = (int) new_balance; // dollar is the interger part of balace
    cent = (int) ((new_balance - dollar) * 100); // cent is the fraction part * 100
    interest_rate = new_interest_rate;
    term = new_term;
}

double CDAccount::get_initial_balance() const
{
    return dollar + (cent / 100.0);
}

double CDAccount::get_balance_at_maturity() const
{
    double balance = get_initial_balance();
    return balance * (1 + interest_rate * term) / 12.0;
}

double CDAccount::get_interest_rate() const
{
    return interest_rate;
}

int CDAccount::get_term() const
{
    return term;
}

void CDAccount::input(istream& in)
{
    double balance;
    cout << "\n\nEnter the account balance: $ ";
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    cout << "Enter the interest rate as a decimal vallue (20% entered as 0.20): ";
    in >> interest_rate; // get interest rate from user
    cout << "Enter the term as the number of months: ";
    in >> term; // get term from user
}

void CDAccount::output(ostream& out)
{
    out << "Account information:\n";
    out << "Initial balance: $" << get_initial_balance() << endl;
    out << "Interest rate: $" << get_interest_rate() << endl;
    out << "Term: " << get_term() << endl;
    out << "The balance at maturity is: $" << get_balance_at_maturity() << endl;
}
