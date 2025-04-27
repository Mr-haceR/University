#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <regex>
#include <sstream>
using namespace std;

string normalize_brackets(const string& expr) {
    string res = expr;
    for (char& c : res) {
        if (c == '{' || c == '[') c = '(';
        else if (c == '}' || c == ']') c = ')';
    }
    return res;
}

vector<string> tokenize(const string& expression) {
    vector<string> tokens;
    regex token_pattern(R"(\d+\.\d+|\d+|[+\-*/()])");
    auto words_begin = sregex_iterator(expression.begin(), expression.end(), token_pattern);
    auto words_end = sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it) {
        tokens.push_back(it->str());
    }
    return tokens;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double apply_operator(char op, double a, double b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

double evaluate_infix(const string& expression) {
    cout << "Expression: \"" << expression << "\"\n";
    string expr = normalize_brackets(expression);
    vector<string> tokens = tokenize(expr);

    cout << "\nTokens:\n";
    for (auto& token : tokens) {
        cout << "Token: " << token << endl;
    }

    stack<char> ops;
    stack<double> values;

    auto pop_and_eval = [&]() {
        char op = ops.top(); ops.pop();
        double right = values.top(); values.pop();
        double left = values.top(); values.pop();
        double result = apply_operator(op, left, right);
        cout << "Applied operator: " << op << endl;
        cout << "Left: " << left << " Right: " << right << " Result: " << result << endl;
        values.push(result);
    };

    for (auto& token : tokens) {
        if (regex_match(token, regex(R"(\d+(\.\d+)?)"))) {
            values.push(stod(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
                pop_and_eval();
            }
            ops.push(token[0]);
        } else if (token == "(") {
            ops.push('(');
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                pop_and_eval();
            }
            ops.pop();
        }
    }

    while (!ops.empty()) {
        pop_and_eval();
    }

    double result = values.top();
    cout << "Result: " << result << endl;
    return result;
}

double evaluate_postfix(const string& expression) {
    cout << "Expression: \"" << expression << "\"\n";
    string expr = normalize_brackets(expression);
    istringstream iss(expr);
    string token;
    stack<double> stack;

    cout << "\nTokens:\n";
    while (iss >> token) {
        cout << "Token: " << token << endl;
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            double result = apply_operator(token[0], a, b);
            cout << "Applied operator: " << token << endl;
            cout << "Left: " << a << " Right: " << b << " Result: " << result << endl;
            stack.push(result);
        } else if (token == "()" || token == "[]" || token == "{}") {
            continue;
        } else {
            stack.push(stod(token));
        }
    }

    double result = stack.top();
    cout << "Result: " << result << endl;
    return result;
}

double evaluate_prefix(const string& expression) {
    cout << "Expression: \"" << expression << "\"\n";
    string expr = normalize_brackets(expression);
    istringstream iss(expr);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    reverse(tokens.begin(), tokens.end());

    stack<double> stack;
    cout << "\nTokens:\n";
    for (auto& token : tokens) {
        cout << "Token: " << token << endl;
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            double result = apply_operator(token[0], a, b);
            cout << "Applied operator: " << token << endl;
            cout << "Left: " << a << " Right: " << b << " Result: " << result << endl;
            stack.push(result);
        } else if (token == "()" || token == "[]" || token == "{}") {
            continue;
        } else {
            stack.push(stod(token));
        }
    }

    double result = stack.top();
    cout << "Result: " << result << endl;
    return result;
}

// Main logic
int main() {
    while (true) {
        cout << "*********************************************************************************************\n" 
             << "*                                         Evaluator                                         *\n"
             << "*********************************************************************************************\n"
             << "Menu > \n"
             << "-----------------------------------------\n"
             << "1. Infix\n"
             << "2. Prefix\n"
             << "3. Postfix\n"
             << "4. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter the expression: ";
            string expression;
            getline(cin, expression);
            evaluate_infix(expression);
        } else if (choice == 2) {
            cout << "Enter the expression: ";
            string expression;
            getline(cin, expression);
            evaluate_prefix(expression);
        } else if (choice == 3) {
            cout << "Enter the expression: ";
            string expression;
            getline(cin, expression);
            evaluate_postfix(expression);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
