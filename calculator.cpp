
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double squareRoot(double a);
double modulo(double a, double b);
void displayMenu();
void displayAdvancedMenu();

// Basic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Division by zero!");
    }
    return a / b;
}

// Advanced operations
double power(double a, double b) {
    return pow(a, b);
}

double squareRoot(double a) {
    if (a < 0) {
        throw runtime_error("Error: Cannot calculate square root of negative number!");
    }
    return sqrt(a);
}

double modulo(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Modulo by zero!");
    }
    return fmod(a, b);
}

// Display menus
void displayMenu() {
    cout << "\n===== CALCULATOR MENU =====" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Advanced Operations" << endl;
    cout << "6. Exit" << endl;
    cout << "=============================" << endl;
}

void displayAdvancedMenu() {
    cout << "\n===== ADVANCED OPERATIONS =====" << endl;
    cout << "1. Power (a^b)" << endl;
    cout << "2. Square Root" << endl;
    cout << "3. Modulo (a%b)" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "=================================" << endl;
}

int main() {
    double num1, num2, result;
    int choice, advChoice;
    bool running = true;

    cout << "\n**** Welcome to C++ Calculator ****" << endl;

    while (running) {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = add(num1, num2);
                cout << fixed << setprecision(2);
                cout << num1 << " + " << num2 << " = " << result << endl;
                break;

            case 2:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = subtract(num1, num2);
                cout << fixed << setprecision(2);
                cout << num1 << " - " << num2 << " = " << result << endl;
                break;

            case 3:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = multiply(num1, num2);
                cout << fixed << setprecision(2);
                cout << num1 << " * " << num2 << " = " << result << endl;
                break;

            case 4:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                try {
                    result = divide(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << num1 << " / " << num2 << " = " << result << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 5:
                displayAdvancedMenu();
                cout << "Enter your choice (1-4): ";
                cin >> advChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input!" << endl;
                    break;
                }

                switch (advChoice) {
                    case 1:
                        cout << "Enter base number: ";
                        cin >> num1;
                        cout << "Enter exponent: ";
                        cin >> num2;
                        result = power(num1, num2);
                        cout << fixed << setprecision(2);
                        cout << num1 << "^" << num2 << " = " << result << endl;
                        break;

                    case 2:
                        cout << "Enter a number: ";
                        cin >> num1;
                        try {
                            result = squareRoot(num1);
                            cout << fixed << setprecision(2);
                            cout << "√" << num1 << " = " << result << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    case 3:
                        cout << "Enter first number: ";
                        cin >> num1;
                        cout << "Enter second number: ";
                        cin >> num2;
                        try {
                            result = modulo(num1, num2);
                            cout << fixed << setprecision(2);
                            cout << num1 << " % " << num2 << " = " << result << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    case 4:
                        cout << "Returning to main menu..." << endl;
                        break;

                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }
                break;

            case 6:
                cout << "\nThank you for using the Calculator!" << endl;
                running = false;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}
