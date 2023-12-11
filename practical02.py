def average(lst):
    valid_marks = [mark for mark in lst if mark != -999]
    total = sum(valid_marks)
    count = len(valid_marks)
    avg = total / count if count > 0 else 0
    print("Total Marks:", total)
    print("Average Marks: {:.2f}".format(avg))

def Maximum(lst):
    return max(mark for mark in lst if mark != -999)

def Minimum(lst):
    return min(mark for mark in lst if mark != -999 and mark != -1)

def absentcount(lst):
    return lst.count(-1)

def maxFrequency(lst):
    freq_dict = {mark: lst.count(mark) for mark in set(lst)}
    max_mark = max(freq_dict, key=freq_dict.get)
    return max_mark, freq_dict[max_mark]

def main():
    marks = [int(input(f"Enter marks of student {i + 1}: ")) for i in range(int(input("Enter total number of students: ")))]
    flag = 1
    while flag:
        print("\n\n--------------------MENU--------------------\n")
        print("1. Total and Average Marks of the Class")
        print("2. Highest and Lowest Marks in the Class")
        print("3. Number of Students absent for the test")
        print("4. Marks with Highest Frequency")
        print("5. Exit\n")
        choice = int(input("Enter your Choice (from 1 to 5): "))
        if choice == 1:
            average(marks)
        elif choice == 2:
            print("Highest Score in Class:", Maximum(marks))
            print("Lowest Score in Class:", Minimum(marks))
        elif choice == 3:
            print("Number of Students absent in the test:", absentcount(marks))
        elif choice == 4:
            mark, freq = maxFrequency(marks)
            print("Highest frequency is of marks {0} that is {1}".format(mark, freq))
        elif choice == 5:
            flag = 0
            print("Thanks for using this program!")
        else:
            print("!!Wrong Choice!!")
        a = input("Do you want to continue (yes/no): ")
        if a.lower() != "yes":
            flag = 0
            print("Thanks for using this program!")

if __name__ == "__main__":
    main()