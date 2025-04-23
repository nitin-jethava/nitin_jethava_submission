#include <iostream>
#include <string>
#include <algorithm> // for reverse
#include <cctype>    // for toupper

std::string inputString;
bool processed = false;

// Arduino-style setup function
void setup() {
    std::cout << "Initializing program..." << std::endl;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);
}

// Arduino-style loop function
void loop() {
    if (!processed) {
        // Reverse the string
        std::reverse(inputString.begin(), inputString.end());

        // Convert to uppercase
        for (char &c : inputString) {
            c = std::toupper(c);
        }

        // Print the result
        std::cout << "Processed String: " << inputString << std::endl;

        // Mark as processed to avoid repeating
        processed = true;
    }
}

int main() {
    setup();    // Run setup once
    while (!processed) {
        loop(); // Keep looping until processed
    }
    return 0;
}
