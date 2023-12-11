def fibonacci_search(phonebook, name):
    fib2 = 0
    fib1 = 1
    fib = fib1 + fib2

    while fib < len(phonebook):
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2

    offset = -1

    while fib > 1:
        index = min(offset + fib2, len(phonebook) - 1)

        if phonebook[index][0] == name:
            return True

        if phonebook[index][0] < name:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = index
        else:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1

    if fib1 == 1 and phonebook[offset + 1][0] == name:
        return True

    return False

def insert_friend(phonebook, name, number):
    index = 0
    while index < len(phonebook) and phonebook[index][0] < name:
        index += 1

    if index < len(phonebook) and phonebook[index][0] == name:
        print("Friend already exists in the phonebook.")
        return

    phonebook.insert(index, (name, number))
    print("Friend successfully added to the phonebook.")

def main():
    phonebook = []
    flag = False

    while True:
        print("Select an option:")
        print("1) Add a friend to the phonebook")
        print("2) Search for a friend [Fibonacii Search]")
        print("3) Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            name = input("Enter the name of your friend: ")
            number = input("Enter the mobile number of your friend: ")

            insert_friend(phonebook, name, number)
            flag = True

        elif choice == "2":
            if not flag:
                print("No friends added to the phonebook yet.")
                continue

            name = input("Enter the name of the friend to search: ")

            found = fibonacci_search(phonebook, name)
            if found:
                print("Friend found in the phonebook.")
            else:
                print("Friend not found in the phonebook.")

        elif choice == "3":
            print("Thank You....!")
            break

        else:
            print("Invalid choice. Please try again.")

        print()  # Empty line for better readability
main()
