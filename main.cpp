#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int hw01(int start, int end, std::vector<int>& primeNumbers) {
    if (start < 10 || start > 99 || end < 10 || end > 99) {
        return -1;
    }

    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            primeNumbers.push_back(i);
            sum += sumOfDigits(i);
        }
    }

    return sum;
}

int main() {
    int start, end;
    std::vector<int> primeNumbers;
    std::cout << "Enter the range [start ... end]: ";
    std::cin >> start >> end;

    int result = hw01(start, end, primeNumbers);

    if (result == -1) {
        std::cout << "Invalid input. Both start and end must be two-digit numbers." << std::endl;
    } else {
        std::cout << "Prime two-digit numbers in the range [" << start << " ... " << end << "] and their sums of digits:" << std::endl;
        for (int i = 0; i < primeNumbers.size(); i++) {
            std::cout << primeNumbers[i] << ": " << sumOfDigits(primeNumbers[i]) << std::endl;
        }
        std::cout << "Sum of digits for prime two-digit numbers: " << result << std::endl;
    }

    return 0;
}
