# University Management System

## Project Overview
This project is a **University Management System** that utilizes fundamental data structures such as:
- **Singly Linked Lists (SLL)**
- **Binary Search Trees (BST)**
- **Doubly Linked Lists (DLL)**
- **Stacks**
- **Queues**
- **Sorting**
- **Hashing**  

These structures efficiently manage students’ information, courses, and enrollment data. The system supports operations like:
- Adding, deleting, searching, and sorting student and course records
- Managing enrollment histories
- Handling prerequisites and waiting lists

---

## Classes Overview

### 1. **Student Class**
Manages student information such as:
- **Attributes:** Name, ID, address, email, phone
- **Functionality:** Handles prerequisite subjects for each student

---

### 2. **Singly Linked List (SLL) Class**
This class represents a list where each **student** is stored as a **node**. Students are added from the tail and deleted by their ID. Searching is done using **binary** or **linear search**.

#### Functions:
- `addToTail()`: Adds a new student at the end (O(1))
- `deleteStudent()`: Removes a student by ID (O(n))
- `display()`: Displays all student records (O(n))
- `quickSort()`: Sorts students by ID using QuickSort (O(n²))
- `binary_searchstudent()`: Searches for a student using binary search (O(log n))
- `linear_studentsearch()`: Searches for a student using linear search (O(n))

---

### 3. **Binary Search Tree (BST) Class**
Used for managing **courses**, enabling efficient **searching, addition, and deletion**.

#### Functions:
- `addCourse()`: Inserts a course into the BST (O(log n))
- `dropCourse()`: Removes a course by ID (O(log n))
- `binary_coursesearch()`: Searches for a course by ID using binary search (O(log n))
- `linear_coursesearch()`: Searches for a course using in-order traversal (O(n))
- `check_courselimit()`: Manages course limits and waiting lists (O(log n))
- `in_ordertraversal()`: Retrieves courses in sorted order (O(n))

---

### 4. **Doubly Linked List (DLL) Class**
Used to manage **enrollment records**.

#### Functions:
- `add()`: Adds a course to enrollment history (O(1))
- `drop()`: Removes a course from history (O(n))
- `view()`: Displays all enrollment records (O(n))
- `quickSort()`: Sorts enrollment records by course ID (O(n²))

---

### 5. **Sorting**
- **QuickSort** is used to organize students and courses by their IDs.
- Applied in **SLL** and **DLL** for sorting (O(n²)).

---

### 6. **Stack Class**
Used for handling **course prerequisites**.

#### Functions:
- `add_prerequisite()`: Pushes prerequisite courses onto the stack (O(1))
- `pop()`: Removes the top prerequisite if completed (O(1))
- `validatePrerequisites()`: Ensures prerequisites are met (O(m × n))
- `display_remaining_prerequisites()`: Displays remaining prerequisites (O(m))

---

### 7. **Queue Class**
Used for **waiting lists** when courses are full.

#### Functions:
- `enqueue()`: Adds a student to the waiting list (O(1))
- `dequeue()`: Removes a student from the front (O(1))
- `display()`: Shows all students in the queue (O(n))
- `isEmpty()`: Checks if the queue is empty (O(1))

---

### 8. **Hashing Class**
Efficiently maps **student and course records** to specific table indices using a **hash function**.

#### Functions:
- `hashfunction()`: Computes hash value for an ID (O(1))
- `insert_students()`: Inserts students from SLL into the hash table (O(n))
- `insert_course()`: Inserts courses from BST into the hash table (O(m))
- `search_student()`: Searches for a student by ID (O(1) average, O(n) worst-case)
- `search_course()`: Searches for a course by ID (O(1) average, O(m) worst-case)

---

## Conclusion
This **University Management System** efficiently manages students, courses, and enrollments using various **data structures**. The use of **linked lists, trees, stacks, queues, sorting, and hashing** ensures optimized performance for essential university operations.

---

### 🔗 **How to Run**
1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/university-management-system.git
   ```
2. Navigate to the project folder:
   ```sh
   cd university-management-system
   ```
3. Compile and run the project.

🚀 **Happy Coding!**
