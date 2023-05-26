/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:17:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 12:48:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFileName) {
    loadExchangeRates(dbFileName);
}

void BitcoinExchange::loadExchangeRates(const std::string& dbFileName) {
    std::ifstream dbFile(dbFileName);
    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open file " << dbFileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(dbFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string rateStr;
        if (!std::getline(iss, date, ',') || !std::getline(iss, rateStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (date == "date" && rateStr == "exchange_rate")
            continue;
        if (!isValidDate(date)) { continue; }
        try {
            double rate = std::stod(rateStr);
            _exchangeRates[date] = rate;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: invalid rate => " << rateStr << std::endl;
        }
    }
}

double BitcoinExchange::getRateForDate(const std::string& date) {
    if (_exchangeRates.find(date) != _exchangeRates.end()) {
        return _exchangeRates[date];
    }

    std::map<std::string, double>::iterator it = _exchangeRates.upper_bound(date);
    if (it == _exchangeRates.begin()) {
        return it->second;
    }

    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::smatch match;
    std::regex datePattern("(\\d{4})-(\\d{2})-(\\d{2})");
    
    if (!std::regex_match(date, match, datePattern)) {
        return false;
    }
    try {
        int year = std::stoi(match[1]);
        int month = std::stoi(match[2]);
        int day = std::stoi(match[3]);

        if (year < 1900 || year > 2099 || month < 1 || month > 12) {
            std::cout << "Error: bad date => " << date << std::endl;
            return false;
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            std::cout << "Error: bad day in date => " << date << std::endl;
            return false;
        }

        if (month == 2) {
            bool leapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
            if ((leapYear && day > 29) || (!leapYear && day > 28)) {
                std::cout << "Error: bad day in date => " << date << std::endl;
                return false;
            }
        }

        if (day < 1 || day > 31) {
            std::cout << "Error: bad day in date => " << date << std::endl;
            return false;
        }
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    return true;
}

void BitcoinExchange::evaluateFile(const std::string& filePath) {
    std::ifstream file(filePath.c_str());
    if (!file) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (date == "date " && valueStr == " value")
            continue;

        size_t start = date.find_first_not_of(' ');
        if (start != std::string::npos)
            date = date.substr(start);
        size_t end = date.find_last_not_of(' ');
        if (end != std::string::npos)
            date = date.substr(0, end + 1);

        start = valueStr.find_first_not_of(' ');
        if (start != std::string::npos)
            valueStr = valueStr.substr(start);
        end = valueStr.find_last_not_of(' ');
        if (end != std::string::npos)
            valueStr = valueStr.substr(0, end + 1);

        if (!isValidDate(date)) { continue; }

        double value;
        std::istringstream(valueStr) >> value;

        if (value < 0 || value > 1000) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        double rate = getRateForDate(date);
        double result = rate * value;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
