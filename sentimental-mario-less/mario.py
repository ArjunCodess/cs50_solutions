from cs50 import get_int


def print_pyramid(height):
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        hashes = "#" * i
        print(spaces + hashes)


def get_valid_height():
    while True:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            return height
        else:
            print("Please enter a positive integer between 1 and 8.")


if __name__ == "__main__":
    n = get_valid_height()
    print_pyramid(n)
