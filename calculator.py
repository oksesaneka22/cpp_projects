import math
print("Welcome to the Calculator Program!")
print("Select operation:")
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
print("5. Square Root")
print("6. Square")
print("7. Powering")
print("8. Percent")
print("9. Exit")

choice = int(input("Enter your choice (1-9): "))
if choice != 9:
    a = float(input("Enter first number: "))
if choice != 5 and choice != 6 and choice != 9:
    b = float(input("Enter second number: "))
result = 0.0
match choice:
    case 1:
        result = a + b
    case 2:
        result = a - b
    case 3:
        result = a * b
    case 4:
        if b != 0:
            result = a / b
        else:
            print("You can't devide by 0")
    case 5:
        result = pow(a, 1/2)
    case 6:
        result = a*a
    case 7:
        result = pow(a, b)
    case 8:
        result = a * (b/100)
    case 9:
        exit
if choice != 9:
    print("Result", result)
