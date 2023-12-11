def binary_search_recursive(phonebook, name, start, end):
    if start > end:
        return False

    mid = (start + end) // 2

    if phonebook[mid][0] == name:
        return True
    elif phonebook[mid][0] < name:
        return binary_search_recursive(phonebook, name, mid + 1, end)
    else:
        return binary_search_recursive(phonebook, name, start, mid - 1)

def binary_search_iterative(phonebook, name):
    start, end = 0, len(phonebook) - 1

    while start <= end:
        mid = (start + end) // 2

        if phonebook[mid][0] == name:
            return True
        elif phonebook[mid][0] < name:
            start = mid + 1
        else:
            end = mid - 1

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
        print("2) Search for a friend (recursive)")
        print("3) Search for a friend (non-recursive)")
        print("4) Exit")

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

            found = binary_search_recursive(phonebook, name, 0, len(phonebook) - 1)
            if found:
                print("Friend found in the phonebook.")
            else:
                print("Friend not found in the phonebook.")

        elif choice == "3":
            if not flag:
                print("No friends added to the phonebook yet.")
                continue

            name = input("Enter the name of the friend to search: ")

            found = binary_search_iterative(phonebook, name)
            if found:
                print("Friend found in the phonebook.")
            else:
                print("Friend not found in the phonebook.")

        elif choice == "4":
            print("Thank You....!")
            break

        else:
            print("Invalid choice. Please try again.")

        print()  # Empty line for better readability
main()
