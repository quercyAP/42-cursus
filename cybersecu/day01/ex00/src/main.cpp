/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:05:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/16 14:28:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <openssl/hmac.h>
#include <openssl/evp.h>

bool is_hex(const std::string& s) {
    return s.find_first_not_of("0123456789abcdefABCDEF") == std::string::npos;
}

std::string to_hex(unsigned char* data, size_t len) {
    std::stringstream ss;
    ss << std::hex;
    for (size_t i = 0; i < len; ++i) {
        ss << std::setw(2) << std::setfill('0') << (int)data[i];
    }
    return ss.str();
}

std::string hotp(const std::string& key, uint64_t counter) {
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    HMAC_CTX *ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, key.data(), key.length(), EVP_sha1(), nullptr);
    HMAC_Update(ctx, reinterpret_cast<const unsigned char*>(&counter), sizeof(counter));
    HMAC_Final(ctx, result, &result_len);
    HMAC_CTX_free(ctx);

    int offset = result[result_len - 1] & 0xf;
    int bin_code = (result[offset] & 0x7f) << 24
                 | (result[offset + 1] & 0xff) << 16
                 | (result[offset + 2] & 0xff) << 8
                 | (result[offset + 3] & 0xff);
    int otp = bin_code % 1000000;
    return std::to_string(otp);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [-g keyfile | -k keyfile]" << std::endl;
        return 1;
    }

    std::string arg = argv[1];
    std::string key_file = argv[2];
    std::ifstream infile(key_file);

    if (arg == "-g") {
        if (!infile) {
            std::cerr << "Error: Could not open key file." << std::endl;
            return 1;
        }
        std::string key((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        if (key.length() != 64 || !is_hex(key)) {
            std::cerr << "Error: key must be 64 hexadecimal characters." << std::endl;
            return 1;
        }

        std::ofstream outfile("ft_otp.key");
        outfile << key;
        outfile.close();
        std::cout << "Key was successfully saved in ft_otp.key." << std::endl;
    } else if (arg == "-k") {
        if (!infile) {
            std::cerr << "Error: Could not open key file." << std::endl;
            return 1;
        }
        std::string key((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        uint64_t counter = static_cast<uint64_t>(time(nullptr)) / 30;
        std::string otp = hotp(key, counter);
        std::cout << otp << std::endl;
    } else {
        std::cerr << "Usage: " << argv[0] << " [-g keyfile | -k keyfile]" << std::endl;
        return 1;
    }

    return 0;
}
