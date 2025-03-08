#include<iostream>
#include<vector>
#include<string>
#include <limits> //для get_valid_number()
using namespace std;

void show_menu_simple();
void simple_calc_handler();
void addition_simple(vector<double>& results);
void subtraction_simple(vector<double>& results);
void multiplication_simple(vector<double>& results);
void division_simple(vector<double>& results);
void show_res_simple(const vector<double>& results);
double get_valid_number();

int main() {
    string calc_var;

    while (true) {
        cout << "\nSelect the calculator option:" << endl;
        cout << "Enter 'Simple' or 'Advanced'" << endl;
        cin >> calc_var;
        for (auto& c : calc_var) c = toupper(c);

        if (calc_var == "SIMPLE") {
            show_menu_simple();
            simple_calc_handler();
            break;
        }
        else if (calc_var == "ADVANCED") {
            cout << "The functionality is not ready";
        }
        else cout << "non-existent option";
    }

    return 0;
}

void show_menu_simple() {
    cout << "A - Addition" << endl;
    cout << "S - Subtraction" << endl;
    cout << "M - Multiplication" << endl;
    cout << "D - Division" << endl;
    cout << "R - Show previous results" << endl;
    cout << "B - Back to menu" << endl;
    cout << "Q - Quit" << endl;
}

void simple_calc_handler() {

    vector<double> results;

    while (true) {
        cout << "\nEnter your choice: ";
        string option;
        cin >> option;

        if (option.length() == 1) {
            char selected_option = toupper(option[0]);

            switch (selected_option) {
            case 'A': addition_simple(results);
                break;

            case 'S': subtraction_simple(results);
                break;

            case 'M': multiplication_simple(results);
                break;

            case 'D': division_simple(results);
                break;

            case 'B': show_menu_simple();
                break;

            case 'R': show_res_simple(results);
                break;

            case 'Q': cout << "Goodbye";
                break;

            default: cout << "Unknown selection, please try again";
                break;
            }

            if (selected_option == 'Q') break;
        }
        else cout << "Please enter only one character as your choice!" << endl;
    }
}
void addition_simple(vector<double>& results) {
    cout << "Enter the addends: ";
    double num_1 = get_valid_number();
    double num_2 = get_valid_number();

    double result = num_1 + num_2;;

    cout << "Your result: " << result << endl;
    results.push_back(result);
}
void subtraction_simple(vector<double>& results) {
    cout << "Enter the numbers to subtract: ";
    double num_1 = get_valid_number();
    double num_2 = get_valid_number();

    double result = num_1 - num_2;;

    cout << "Your result: " << result << endl;
    results.push_back(result);
}
void multiplication_simple(vector<double>& results) {
    cout << "Enter the factors: ";
    double num_1 = get_valid_number();
    double num_2 = get_valid_number();

    double result = num_1 * num_2;

    cout << "Your result: " << result << endl;
    results.push_back(result);
}
void division_simple(vector<double>& results) {
    double num_1, num_2;

    while (true) {
        cout << "Enter the dividend and divisor: ";
        num_1 = get_valid_number();
        num_2 = get_valid_number();

        if (num_2 != 0) {
            double result = num_1 / num_2;
            cout << "Your result: " << result << endl;
            results.push_back(result);
            break;
        }
        else {
            cout << "You cannot divide by '0'. Try again." << endl;
        }
    }

}
void show_res_simple(const vector<double>& results) {
    if (results.empty()) {
        cout << "No previous results." << endl;
        return;
    }

    cout << "Your previous results: ";
    for (auto num : results) {
        cout << "[ " << num << " ]";
    }
}

double get_valid_number() {
    double num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter a valid number: ";
        }
        else {
            return num;
        }
    }
}

