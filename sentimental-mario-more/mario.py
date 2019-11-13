from cs50 import get_int


while True:
    h = get_int("Height of marios pyramid: ")
    if h >= 0 and h <= 23:
        break

row = 0
hashtags = 0
spaces = h - row
for row in range(h):
    # spaces
    for spaces in range((h - row) - 1):
        print(" ", end="")
    # hashtags
    for hashtags in range(row+1):
        print("#", end="")

    # space between pyramids
    print("  ", end="")

    # second pyramid
    for hashtags in range(row+1):
        print("#", end="")
    print("")
