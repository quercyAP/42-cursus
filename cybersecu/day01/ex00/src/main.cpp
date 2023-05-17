/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:05:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/17 06:36:49 by glamazer         ###   ########.fr       */
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
#include <cstring>

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

std::string decrypt(const std::string& key, const std::string& encryptedData) {
    unsigned char outbuf[1024];
    int outlen, tmplen;
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)(key.data()), iv);

    if (!EVP_DecryptUpdate(ctx, outbuf, &outlen, (const unsigned char*)(encryptedData.data()), encryptedData.size())) {
        // handle error
    }
    if (!EVP_DecryptFinal_ex(ctx, outbuf + outlen, &tmplen)) {
        // handle error
    }
    outlen += tmplen;
    EVP_CIPHER_CTX_free(ctx);

    return std::string((const unsigned char*)(outbuf), outlen);
}

std::string encrypt(const std::string& key, const std::string& data) {
    unsigned char outbuf[1024];
    int outlen, tmplen;
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, (const unsigned char*)(key.data()), iv);

    if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, (const unsigned char*)(data.data()), data.size())) {
        // handle error
    }
    if (!EVP_EncryptFinal_ex(ctx, outbuf + outlen, &tmplen)) {
        // handle error
    }
    outlen += tmplen;
    EVP_CIPHER_CTX_free(ctx);

    return to_hex(outbuf, outlen);
}
std::string hotp(const std::string& key, uint64_t counter) {
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    HMAC_CTX *ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, key.data(), key.length(), EVP_sha1(), nullptr);
    HMAC_Update(ctx, (const unsigned char*)(&counter), sizeof(counter));
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

        std::string encrypted_key = encrypt(key, key);
        std::ofstream outfile("ft_otp.key");
        outfile << encrypted_key;
        outfile.close();
        std::cout << "Key was successfully saved in ft_otp.key." << std::endl;
    } else if (arg == "-k") {
        if (!infile) {
            std::cerr << "Error: Could not open key file." << std::endl;
            return 1;
        }
        std::string encryptedKey((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        std::string key = decrypt(encryptedKey, encryptedKey);

        uint64_t counter = static_cast<uint64_t>(time(nullptr)) / 30;
        std::string otp = hotp(key, counter);
        std::cout << otp << std::endl;
    } else {
        std::cerr << "Usage: " << argv[0] << " [-g keyfile | -k keyfile]" << std::endl;
        return 1;
    }

    return 0;
}
