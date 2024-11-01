# TODO
from cs50 import get_int
height = get_int('Please enter height: ')
while height < 1 or height > 8:
    height = get_int('Please enter a height between 1 and 8')
# Spaces
rownum = 1
space_count = height - rownum
for i in range(height):
    print(space_count * ' ' + ('#' * (height - space_count)) + '  ' + ('#' * (height - space_count)))
    rownum += 1
    space_count = height - rownum
