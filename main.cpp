//
// Created by isaac on 3/27/23.
//

#include <iostream>
#include <math.h>

using namespace std;

class Savings {
private:
    int time{}, ssn{};
    double ai{}, amt{}, interest{};
    string firstName, lastName;

public:
    Savings(string fn, string ln, int s, double a, int t, double i);
    Savings();
    ~Savings() = default;
    void credentials();
    void enterValues();
    void calculateSavings();
    void savings() const;
};

Savings::Savings() = default;

Savings::Savings(string fn, string ln, int s, double a, int t, double i) {
    firstName = fn;
    lastName = ln;
    ssn = s;
    time = t;
    ai = i;
    amt = a;
}

void Savings::credentials() {
    cout << "First name: " << endl;
    cin >> firstName;

    cout << "Last name: " << endl;
    cin >> lastName;

    cout << "Social Security Number: " << endl;
    cin >> ssn;

    cout << endl;
}

void Savings::enterValues() {
    cout << "Amount deposited: " << endl;
    cin >> amt;

    cout << "Time in years: " << endl;
    cin >> time;

    cout << "Annual interest: " << endl;
    cin >> ai;

    cout << endl;
}

void Savings::calculateSavings() {
    ai = ai / 100;

    for (int i = 1; i <= time; ++i) {
        interest = amt * ai;
        amt = amt + interest;
    }
}

void Savings::savings() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Social Security Number: " << ssn << endl;
    cout << "Savings: " << amt << endl;

    cout << endl;
}

int main() {
    Savings s,
            s2("Lindsy", "Dwyer", 223049, 100000, 12, 8),
            s3("Jane", "Doe", 493430, 310000, 14, 10),
            s4("Dick", "Gray", 232343, 400000, 10, 14);

    s.credentials();
    s.enterValues();
    s.calculateSavings();
    s.savings();

    s2.calculateSavings();
    s2.savings();

    s3.calculateSavings();
    s3.savings();

    s4.calculateSavings();
    s4.savings();

    return 0;
}
