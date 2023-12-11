def selection_sort(scores):
    n = len(scores)
    for i in range(n-1):
        mini=i
        for j in range(i+1,n):
           if scores[j]<scores[mini]:
              mini = j
        scores[i],scores[mini]=scores[mini],scores[i]

def bubble_sort(scores):
    n = len(scores)
    for i in range(n):
        swapped = False
        for j in range(0, n-1):
            if scores[j] > scores[j+1]:
                scores[j], scores[j+1] = scores[j+1], scores[j]
                swapped = True
        if not swapped:
            break 
 
def display_top_scores(scores):
    print("Top Five Scores:")
    for i in range(len(scores) - 1, len(scores) - 6, -1):
        print(scores[i])

def main():
    scores = []
    flag = False

    while True:
        print("Select an option:")
        print("1) Add a student's first-year percentage")
        print("2) Sort the scores using Selection Sort")
        print("3) Sort the scores using Bubble Sort")
        print("4) Display top five scores")
        print("5) Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            percentage = float(input("Enter the first-year percentage: "))
            scores.append(percentage)
            flag = True

        elif choice == "2":
            if not flag:
                print("No scores added yet.")
                continue

            selection_sort(scores)
            print("Scores sorted using Selection Sort:")
            print(scores)

        elif choice == "3":
            if not flag:
                print("No scores added yet.")
                continue

            bubble_sort(scores)
            print("Scores sorted using Bubble Sort:")
            print(scores)

        elif choice == "4":
            if not flag:
                print("No scores added yet.")
                continue

            display_top_scores(scores)

        elif choice == "5":
            print("Thank You....!")
            break

        else:
            print("Invalid choice. Please try again.")
main()
    