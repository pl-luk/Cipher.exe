// Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//disable deprecation of localtime
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <functional>
#include <time.h>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz.:/*-ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main() {
    
    //get time
    time_t tim = time(NULL);
    struct tm* aTime = localtime(&tim);

    int hour = aTime->tm_hour;
    int minute = aTime->tm_min;

    std::string time_str = std::to_string(hour) + std::string(":") + std::to_string(minute);
    
    //hash string
    std::hash<std::string> hasher;
    size_t hash = hasher(time_str);

    std::string cipher = alphabet;

    //generate cipher alphabet
    std::rotate(cipher.begin(), cipher.begin() + (hash % alphabet.size()), cipher.end());

    //read string
    std::string input;
    std::cout << "Eingabe: ";
    std::cin >> input;
    
    if (input.size() > 100) {
        std::cout << "Netter versuch :)" << std::endl;
        return 0;
    }

    char curr_char;
    char new_char;

    std::string out;

    bool cheat = true;

    for (int x = 0; x < alphabet.size(); x++) {
        if (input.find(alphabet.at(x)) == std::string::npos) {
            cheat = false;
        }
    }

    if (cheat) {
        std::cout << "Resultat: Unsinn" << std::endl;
        return 0;
    }

    //loop through every char
    for (int i = 0; i < input.size(); i++) {
        curr_char = input.at(i);

        //find index in alphabet
        const char* pc = strchr(alphabet.c_str(), curr_char);
        int index = pc - alphabet.c_str();
        
        if (index < 0 || index > alphabet.size()) {
            std::cout << "Buchstabe is nix im alphabet" << std::endl;
            return 0;
        }

        //get char at index in cipher and append it to out
        new_char = cipher[index];
        out += new_char;
    }

    std::cout << "Resultat: " << out << std::endl;

    return 0;
}
