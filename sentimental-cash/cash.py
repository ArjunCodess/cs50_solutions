# TODO

from cs50 import get_float


def get_valid_amount():
    while True:
        amount = get_float("Change owed: ")
        if amount is not None and amount >= 0:
            return amount
        else:
            print("Please enter a non-negative amount.")


def calculate_coins(amount):
    coins = 0
    cents = round(amount * 100)

    while cents > 0:
        if cents >= 25:
            cents -= 25
        elif cents >= 10:
            cents -= 10
        elif cents >= 5:
            cents -= 5
        else:
            cents -= 1

        coins += 1

    return coins


if __name__ == "__main__":
    amount = get_valid_amount()
    coins = calculate_coins(amount)

    print(coins)
