from decimal import Decimal, getcontext

getcontext().prec = 100000000 

def read_number_from_file(file_path):
    with open(file_path, 'r') as file:
        number = file.read().strip()
    return Decimal(number)

def write_result_to_file(file_path, result):
    with open(file_path, 'w') as file:
        file.write(str(result))


number1 = read_number_from_file("/Users/yasir/Desktop/number1.txt")
number2 = read_number_from_file("/Users/yasir/Desktop/number2.txt")


addition = number1 + number2
subtraction = number1 - number2
multiplication = number1 * number2

write_result_to_file("addition.txt", addition)
write_result_to_file("subtraction.txt", subtraction)
write_result_to_file("multiplication.txt", multiplication)

getcontext().prec = 100
division = number1 / number2 if number2 != 0 else 'Bölme Hatası'
write_result_to_file("division.txt", division if division != 'Bölme Hatası' else "Bölünemez (bölücü 0)")
