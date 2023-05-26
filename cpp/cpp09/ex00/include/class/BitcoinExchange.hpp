/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:15:10 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 12:48:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <map>
# include <string>
# include <cctype>
# include <regex>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFileName);
    void evaluateFile(const std::string& inputFileName);

private:
    std::map<std::string, double> _exchangeRates;
    void loadExchangeRates(const std::string& dbFileName);
    double getRateForDate(const std::string& date);
    bool isValidDate(const std::string& date);
};

#endif
