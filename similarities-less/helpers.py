from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    alines = set(a.split("\n"))
    blines = set(b.split("\n"))
    # at this point i have a[unique lines] & b[unique lines]
    return alines & blines


def sentences(a, b):
    """Return sentences in both a and b"""

    asent = set(sent_tokenize(a))
    bsent = set(sent_tokenize(b))
    return asent & bsent

def substring_tokenize(str, n):
    substrings = []

    for i in range(len(str) - n + 1):
        substrings.append(str[i:i + n])

    return substrings

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    a_substring = set(substring_tokenize(a, n))
    b_substring = set(substring_tokenize(b, n))
    return a_substring & b_substring
