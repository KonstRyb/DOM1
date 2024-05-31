#include <iostream>
#include <string>

using namespace std;

string multiplyStrings(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();
    string result(n + m, '0');

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j + 1] = (sum % 10) + '0';
            result[i + j] += sum / 10;
        }
    }

    size_t startPos = result.find_first_not_of('0');
    if (startPos != string::npos) {
        return result.substr(startPos);
    }

    return "0";
}

int main() {
    string num1 = "123";
    string num2 = "456";

    string result = multiplyStrings(num1, num2);

    cout << "Result of multiplication: " << result << endl;

    return 0;
}