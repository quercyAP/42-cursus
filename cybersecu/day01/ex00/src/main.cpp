/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:05:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/19 09:37:19 by glamazer         ###   ########.fr       */
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
#include <openssl/aes.h>
#include <cstdint>
#include <cstring>

uint64_t swap64(uint64_t value) {
    return ((value & 0xFF00000000000000ULL) >> 56) |
           ((value & 0x00FF000000000000ULL) >> 40) |
           ((value & 0x0000FF0000000000ULL) >> 24) |
           ((value & 0x000000FF00000000ULL) >> 8) |
           ((value & 0x00000000FF000000ULL) << 8) |
           ((value & 0x0000000000FF0000ULL) << 24) |
           ((value & 0x000000000000FF00ULL) << 40) |
           ((value & 0x00000000000000FFULL) << 56);
}

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

std::string hex_to_binary(const std::string& hex) {
    std::string binary;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2);
        char bin = static_cast<char>(strtol(byte.c_str(), nullptr, 16));
        binary += bin;
    }
    return binary;
}

std::string exec(const char* cmd) {
    char buffer[1024];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer, sizeof buffer, pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

std::string hotp(const std::string& key, uint64_t counter) {
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;
    std::string binary_key = hex_to_binary(key);

    HMAC_CTX *ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, binary_key.data(), binary_key.length(), EVP_sha1(), nullptr);
    uint64_t counter_be = swap64(counter);
    HMAC_Update(ctx, reinterpret_cast<const unsigned char*>(&counter_be), sizeof(counter_be));
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

    if (!infile) {
        std::cerr << "Error: Could not open key file." << std::endl;
        return 1;
    }

    if (arg == "-g") {
        std::string key((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        if (key.length() < 64 || !is_hex(key) || key.length() % 2 != 0) {
            std::cerr << "Error: The key must be at least 64 characters of an even hexadecimal number." << std::endl;
            return 1;
        }
        
        std::string command = "openssl enc -aes-256-cbc -in " + key_file + " -out ft_otp.key -pass pass:mysecretpassword";
        system(command.c_str());
        std::cout << "Key was successfully saved in ft_otp.key." << std::endl;
    } else if (arg == "-k") {      
        std::string decrypted_key = exec("openssl enc -aes-256-cbc -d -in ft_otp.key -pass pass:mysecretpassword");

        uint64_t counter = static_cast<uint64_t>(time(nullptr)) / 30;
        std::string otp = hotp(decrypted_key, counter);
        std::cout << otp << std::endl;
    } else {
        std::cerr << "Usage: " << argv[0] << " [-g keyfile | -k keyfile]" << std::endl;
        return 1;
    }

    return 0;
}

