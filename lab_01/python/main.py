

def int_try_parse(value):
    try:
        return int(value)
    except ValueError:
        return None


def enter_text_to_file(input_file):
    print("Enter text line by line. Enter ^K and [enter] at the end:")
    while True:
        text = input()
        if text == "\v":
            break
        text += "\n"
        input_file.write(text)



def process_text(input_file, output_file):
    input_file.seek(0)
    lines = input_file.readlines()
    for line in lines:
        words = list(map(int_try_parse, line.split()))
        numbers = [number for number in words if number]
        if (numbers):
            output_file.write(str(max(numbers)) + ": ")
            output_file.write(", ".join(list(map(str, numbers))) + "\n")
        
        



input_file_name = "in.txt"
output_file_name = "out.txt"

input_file = open(input_file_name, "w+")
output_file = open(output_file_name, "w+")


enter_text_to_file(input_file)
process_text(input_file, output_file)

output_file.seek(0)
print("\n\nFile out.txt:")
print(output_file.read())


