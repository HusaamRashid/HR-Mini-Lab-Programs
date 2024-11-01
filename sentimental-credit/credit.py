# TODO
from cs50 import get_int
import math
number = get_int('Enter card number')
total = 0
cardnum = number / 10
# IS luhn algorithm
while cardnum > 1:
    doubled = (cardnum % 10) * 2
    if doubled > 9:
        doubled -= 9
    total += doubled
    cardnum = cardnum // 10
    undoubled = cardnum % 10
    total += undoubled
    cardnum = cardnum // 10
# Checks if the card is invalid
if ((total % 10) != 0):
    print('INVALID\n')
cardnum = number
temp = cardnum
temp = temp // 10
length = 1
while temp != 0:
    temp = temp // 10
    length += 1
# Scuffed method to get first and 2nd digits
firstDigit = int(str(cardnum)[0])
secondDigit = int(str(cardnum)[1])

if (length == 15 and firstDigit == 3 and secondDigit == 4 or secondDigit == 7):
    print('AMEX\n')
if length == 16 and firstDigit == 5:
    if secondDigit == 1 or secondDigit == 2 or secondDigit == 3 or secondDigit == 4 or secondDigit == 5:
        print('MASTERCARD\n')
if length == 13 or length == 16 and firstDigit == 4:
    print('VISA\n')

