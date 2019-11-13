import sys
from cs50 import get_string


def main():
    # make sure command line arguments are correct
    if len(sys.argv) != 2:
        print("Command line arguments must be 2")
        exit(1)

    key = int(sys.argv[1])
    cyphertext = []
    # get plaintext
    plaintext = get_string("Plaintext: ")
    # convert plaintext keeping upper and lowercase in mind
    print("ciphertext: ", end="")
    for c in plaintext:
        if c.isalpha():
            cyphertext.append(encryption(c, key))
        else:
            cyphertext.append(c)

    print("".join(cyphertext))
    exit(0)


# encryption formula with name encryption


def encryption(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)


if __name__ == "__main__":
    main()