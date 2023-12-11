    
def quick_sort(arr, low, high):
  if low<high:
      pivot=partition (arr, low, high)
      quick_sort(arr, low, pivot-1)
      quick_sort(arr, pivot+1, high)
       
def partition (arr, low, high):
  p = arr[low]
  i = low + 1
  j = high
    
  while True:
    while i<=j and arr[i]<=p:
     i+=1
    while i<=j and arr[j]>=p:
     j-=1
    if i<=j:
       arr[i],arr[j]=arr[j],arr[i]
    else:
       break
    arr[low],arr[j]=arr[j],arr[low]
    return j

# User input for student marks
student_marks = []
n = int(input("Enter the number of students: "))

for i in range(n):
    mark = int(input("Enter the mark for student {}: ".format(i + 1)))
    student_marks.append(mark)

while True:
    print("======= Menu =======")
    print("1. Display student marks")
    print("2. Sort marks in ascending order")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        print("Student marks:", student_marks)
    elif choice == 2:
        quickSort(student_marks, 0, len(student_marks) - 1)
        print("Sorted marks (ascending order):", student_marks)
    elif choice == 3:
        print("Exiting the program...")
        break
    else:
        print("Invalid choice. Please try again.")

