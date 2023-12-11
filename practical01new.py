def remove_duplicate(lst):
    return list(set(lst))

def intersection(lst1, lst2):
    return list(set(lst1) & set(lst2))

def union(lst1, lst2):
    return list(set(lst1) | set(lst2))

def difference(lst1, lst2):
    return list(set(lst1) - set(lst2))

def symmetrical_difference(lst1, lst2):
    return list(set(lst1) ^ set(lst2))

def main():
    SEComp = [input() for _ in range(int(input("Enter number of students in SE COMP: ")))]
    Cricket = remove_duplicate([input() for _ in range(int(input("Enter number of students who play cricket: ")))])
    Football = remove_duplicate([input() for _ in range(int(input("Enter number of students who play football: ")))])
    Badminton = remove_duplicate([input() for _ in range(int(input("Enter number of students who play badminton: ")))])
    
    while True:
        print("\n--------------------MENU--------------------\n")
        print("1. List of students who play both cricket and badminton")
        print("2. List of students who play either cricket or badminton but not both")
        print("3. List of students who play neither cricket nor badminton")
        print("4. Number of students who play cricket and football but not badminton")
        print("5. Exit\n")
        choice = int(input("Enter your Choice (from 1 to 5): "))

        if choice == 1:
            print(f"Number of students who play both cricket and badminton: {len(intersection(Cricket, Badminton))}")
        elif choice == 2:
            print(f"Number of students who play either cricket or badminton but not both: {len(symmetrical_difference(Cricket, Badminton))}")
        elif choice == 3:
            print(f"Number of students who play neither cricket nor badminton: {len(difference(SEComp, union(Cricket, Badminton)))}")
        elif choice == 4:
            print(f"Number of students who play cricket and football but not badminton: {len(difference(intersection(Cricket, Football), Badminton))}")
        elif choice == 5:
            print("Thanks for using this program!")
            break
        else:
            print("!!Wrong Choice!! ")

        if input("\nDo you want to continue (yes/no): ").lower() != "yes":
            print("Thanks for using this program!")
            break

if __name__ == "__main__":
    main()