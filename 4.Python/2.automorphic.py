num = int(input("Enter a number (1-9): "))
if 1 <= num <= 9:
    square = num * num
    if str(square).endswith(str(num)):
        print("Automorphic Number")
    else:
        print("Not an Automorphic Number")
else:
    print("Invalid input")
