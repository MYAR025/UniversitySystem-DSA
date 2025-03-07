#include<bits/stdc++.h>
using namespace std;
class enrollment_history;


//SLL ----------------------------------------------------------------------------------------------------------------------------------------
class Student {
public:
    string Name, Email, Phone, Address, Password;
    int ID;
    Student(string name, string mail, string phone, string address, string password, int id) {
        Name = name;
        Email = mail;
        Phone = phone;
        Address = address;
        Password = password;
        ID = id;
    }
};

class Node {
public:
    Student* data;
    Node* next;

    Node(Student* student) {
        data = student;
        next = NULL;
    }
};

class SLL {
public:
    Node* head;
    Node* tail;
    int length;

    SLL() {
        head = tail = NULL;
        length = 0;
    }

    void addToTail(Student* student) {
        Node* newnode = new Node(student);
        if (length == 0) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        length++;
        cout << "Student added successfully!\n";
    }

    void deleteStudent(int id) {
        if (head == NULL) {
            cout << "The list is empty!\n";
            return;
        }

        // Delete Head
        if (head->data->ID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
            cout << "Student with ID " << id << " has been removed.\n";
            return;
        }

        // Search List
        Node* curr = head->next;
        Node* prev = head;
        while (curr != NULL) {
            if (curr->data->ID == id) {
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev; // Delete Tail
                }
                delete curr;
                length--;
                cout << "Student with ID " << id << " has been removed.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Student with ID " << id << " not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Student Records:\n";
        while (temp != NULL) {
            cout << "ID: " << temp->data->ID << ", "
                 << "Name: " << temp->data->Name << ", "
                 << "Email: " << temp->data->Email << ", "
                 << "Phone: " << temp->data->Phone << ", "
                 << "Address: " << temp->data->Address <<", "
                 << "Password: " << temp->data->Password << ", \n";
            temp = temp->next;
        }
    }

    Node* getTail(Node* curr){
    while(curr != nullptr && curr->next != nullptr){
        curr = curr->next;
    }
    return curr;
    }

    Node* Partition(Node* head, Node* tail){
    Node* pivot = head;
    Node* pre = head;
    Node* curr = head;

    while(curr != tail->next){
        if(curr->data->ID < pivot->data->ID){
            swap(curr->data, pre->next->data);
            pre = pre->next;
        }
        curr = curr->next;
    }
    swap(pivot->data, pre->data);
    return pre;
    }

    void quickSortHelper(Node* head, Node* tail){
    if(head == nullptr || head == tail){
        return;
    }
    Node* pivot = Partition(head, tail);

    // Recursively sort the left part
    quickSortHelper(head, pivot);

    // Recursively sort the right part
    if(pivot != nullptr && pivot->next != nullptr){
        quickSortHelper(pivot->next, tail);
    }
    }

    void quickSort(){
    Node* tail = getTail(head);
    quickSortHelper(head, tail);
    }
    void binary_searchstudent(int id){
    Node* last=NULL;
    int len=length;
    if(head==NULL){
        cout<<"No student yet."<<endl;
    }
    else if(head==tail){
        if(head->data->ID==id){
            cout<<"The student is found:"<<endl;
            cout<<"Name:"<<head->data->Name<<"\t"<<"Email:"<<head->data->Email<<"\t"<<"Phone:"<<head->data->Phone<<endl;
            return;
        }
        else{cout<<"The student cannot be found."<<endl;}

    }else{
    while(head!=last){
        len=len/2;
        Node*mid=head;
        for(int i=0;i<len;i++){
            if(mid->next!=NULL){
                mid=mid->next;}
        }
        if(mid->data->ID==id){
            cout<<"The student is found:"<<endl;
            cout<<"Name:"<<head->data->Name<<"\t"<<"Email:"<<head->data->Email<<"\t"<<"Phone:"<<head->data->Phone<<endl;
            return;
        }
        else{
            if(id<mid->data->ID){
                    last=mid;
            }
            else{
              head=mid->next;
            }
        }
    }}cout<<"student cannot be found."<<endl;
    }
    void linear_studentsearch(int id){
     if(head==NULL){
        cout<<"No student yet."<<endl;
        return;
    }
    else if(head==tail){
        if(head->data->ID==id){
            cout<<"The student is found:"<<endl;
            cout<<"Name:"<<head->data->Name<<"\t"<<"Email:"<<head->data->Email<<"\t"<<"Phone:"<<head->data->Phone<<endl;
            return;
        }
        else{cout<<"The student cannot be found."<<endl;
        return;}}
    else{
        Node*curr=head;
        while(curr!=NULL){
            if(curr->data->ID==id){
            cout<<"The student is found:"<<endl;
            cout<<"Name:"<<head->data->Name<<"\t"<<"Email:"<<head->data->Email<<"\t"<<"Phone:"<<head->data->Phone<<endl;
            return;
        }
        else{
            curr=curr->next;
        }
            }
        }
       cout<<"student cannot be found."<<endl;
    }

};



//QUEUE------------------------------------------------------------------------------------------------------------------------------------------------------
class QNode {
public:
    Student* data;
    QNode* next;

    QNode(Student* student) : data(student), next(nullptr) {}
};
class QueueLinkedList{
public:
QNode *queueRear;
QNode *queueFront;
int length;
    QueueLinkedList(){
    queueRear = queueFront = nullptr;
    length = 0;
    }
    bool isEmpty(){
    return length == 0;
    }

    void dequeue(){
    if(isEmpty()){
        cout<<"Waitlist is empty, no one to enroll."<<endl;
        return;
    }
    else if(length == 1){
        QNode *temp = queueFront;
        queueFront = queueRear = nullptr;
        length = 0;
        delete temp;
    }
    else{
       QNode *temp = queueFront;
        queueFront =queueFront->next;
        delete temp;
        length--;
    }
    }

    void enqueue(Student*student){
    QNode* new_node = new QNode(student);
    new_node->next = nullptr;
    if(isEmpty()){
        queueFront = queueRear = new_node;
        length = 1;
    }
    else{
        queueRear->next = new_node;
        queueRear = new_node;
        length++;
    }
    }
    void Front(){
        if(!isEmpty()){
            cout<<"Name:"<<queueFront->data->Name<<"\t"<<"Email:"<<queueFront->data->Email<<"\t"<<"Phone:"<<queueFront->data->Phone<<endl;
        }
        return;
    }

    void display(){
    if(isEmpty()){
        cout<<"wiatlist is empty. "<<endl;
        return;
    }
    QNode *head = queueFront;
    int i=1;
    while(head != nullptr){
        cout<<"Student "<<i<<": "<<"Name:"<<head->data->Name<<"\t"<<"Email:"<<head->data->Email<<"\t"<<"Phone:"<<head->data->Phone<<endl;
        head = head->next;
        i++;
        cout<<endl;
    }
    }
};



//Stack-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct StackNode {
    int item;
    StackNode *next;
};

class Stack {
    StackNode *top;
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int newItem) {
        StackNode *newPtr = new StackNode;
        if (newPtr == NULL)
            cout << "Stack push cannot allocate memory" << endl;
        else {
            newPtr->item = newItem;
            newPtr->next = top;
            top = newPtr;
        }
    }

    void pop() {
        if (isEmpty())
            cout << "Stack empty on pop" << endl;
        else {
            StackNode *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    int Peek() {
        if (isEmpty()) {
            return -1;
        } else {
            return top->item;
        }
    }

    void display() {
        StackNode *curPtr = top;
        cout << "[ ";
        while (curPtr != NULL) {
            cout << curPtr->item << " ";
            curPtr = curPtr->next;
        }
        cout << "]\n";
    }
};




//BST --------------------------------------------------------------------------------------------------------------------------------------
class Course {
public:
    int CourseID, CourseCredits,studentcount=0,limit=2;
    string CourseName, CourseInstructor;
     QueueLinkedList waitinglist;
    vector<int> prerequisites;

    Course(int id, string name, int credits, string instructor, vector<int> prereqs) {
        CourseID = id;
        CourseName = name;
        CourseCredits = credits;
        CourseInstructor = instructor;
        prerequisites = prereqs;
    }

};

class BSTNode {
public:
    Course course;
    BSTNode *Left, *Right;

    BSTNode(Course c) : course(c) {
        Left = Right = NULL;
    }
};

class BST {
public:
    BSTNode *root;

    int Size;
    BST() {root = NULL; Size = 0;}

    BSTNode *addBST(BSTNode *root, Course c) {
        if (root == NULL) {
            return new BSTNode(c);
        }
        if (c.CourseID < root->course.CourseID) {
            root->Left = addBST(root->Left, c);
        } else if (c.CourseID > root->course.CourseID) {
            root->Right = addBST(root->Right, c);
        }
        return root;
    }

    void addCourse(int id, string name, int credits, string instructor, vector<int> prereqs) {
        Course c(id, name, credits, instructor, prereqs);
        root = addBST(root, c);
        cout << "Course with ID " << id << " added successfully.\n";
    }

    Course *findCourse(int id, BSTNode *node) {
        if (node == NULL) return NULL;
        if (node->course.CourseID == id) return &node->course;
        if (id < node->course.CourseID) return findCourse(id, node->Left);
        return findCourse(id, node->Right);
    }

    Course *findCourse(int id) {
        return findCourse(id, root);
    }


    int minValue(BSTNode* root) {
        while (root->Left != NULL) {
            root = root->Left;
        }
        return root->course.CourseID;
    }

    BSTNode* dropCourse(BSTNode* root, int id) {
        if (root == NULL) return root;

        if (id < root->course.CourseID) {
            root->Left = dropCourse(root->Left, id);
        } else if (id > root->course.CourseID) {
            root->Right = dropCourse(root->Right, id);
        } else {
            // Case 1: Node with only one child or no child
            if (root->Left == NULL) {
                BSTNode* temp = root->Right;
                delete root;
                Size--;
                return temp;
            } else if (root->Right == NULL) {
                BSTNode* temp = root->Left;
                delete root;
                Size--;
                return temp;
            }

            // Case 2: Node with two children
            int minVal = minValue(root->Right);
            root->course.CourseID = minVal;
            root->Right = dropCourse(root->Right, minVal);
        }
        return root;
    }

    void dropCourse(int id) {
        root = dropCourse(root, id);
        cout << "Course with ID " << id << " dropped successfully.\n";
    }

    void inorder(BSTNode* root) {
        if (root == NULL) return;
        inorder(root->Left);
        cout << "CourseID: " << root->course.CourseID
             << ", Name: " << root->course.CourseName
             << ", Credits: " << root->course.CourseCredits
             << ", Instructor: " << root->course.CourseInstructor << "\n";
        inorder(root->Right);
    }
Course* Check_courselimit(int id,BSTNode*root){
    if(root==NULL){
        cout<<"The course cannot be found."<<endl;
        return NULL;
    }
    else if(root->course.CourseID==id){
       return &(root->course);
    }
    else if(id<root->course.CourseID){
        return Check_courselimit(id,root->Left);
    }
    else{
        return Check_courselimit(id,root->Right);
    }
}
void binary_coursesearch(int id,BSTNode*root){
    if(root==NULL){
        cout<<"The course cannot be found."<<endl;
        return;
    }
    else if(root->course.CourseID==id){
        cout<<"The course is found"<<endl;
        cout << "CourseID: " << root->course.CourseID
             << ", Name: " << root->course.CourseName
             << ", Credits: " << root->course.CourseCredits
             << ", Instructor: " << root->course.CourseInstructor << "\n";
        return ;
    }
    else if(id<root->course.CourseID){
        binary_coursesearch(id,root->Left);
    }
    else{
        binary_coursesearch(id,root->Right);
    }
}
void in_ordertraversal(BSTNode* root, vector<BSTNode*>& courses) {
    if (root == NULL) {
        return;
    }
    in_ordertraversal(root->Left, courses); // Traverse left subtree
    courses.push_back(root);               // Add current node
    in_ordertraversal(root->Right, courses); // Traverse right subtree
}

vector<BSTNode*> in_ordertraversal() {
    vector<BSTNode*> courses;
    in_ordertraversal(root, courses); // Pass the vector by reference
    return courses;
}
void linear_coursesearch(int id){
    if(Size==0){
        cout<<"No courses to search"<<endl;
    }
    else{
    vector<BSTNode*> courses=in_ordertraversal();
     for(int i=0;i<courses.size();i++){
        if(courses[i]->course.CourseID==id){
            cout<<"The course id found:"<<endl;
            cout << "CourseID: " << courses[i]->course.CourseID
             << ", Name: " << courses[i]->course.CourseName
             << ", Credits: " << courses[i]->course.CourseCredits
             << ", Instructor: " <<courses[i]->course.CourseInstructor << "\n";
            return;
        }
     }
   }}
};




//DLL-----------------------------------------------------------------------------------------------------------------------------------------------------------------
struct enrollment_record {
int course_ID;
string course_Name;
int student_id;
enrollment_record* prev;
enrollment_record* next;
enrollment_record(int id, string name,int stu_id) {
    course_ID = id;
    course_Name = name;
    student_id=stu_id;
    prev = nullptr;
    next = nullptr;
}
};
class enrollment_history {
public:
    enrollment_record *head, *tail;
    enrollment_history() {
        head = tail = NULL;
    }

    bool hasCompleted(int courseID) {
        enrollment_record *current = head;
        while (current != NULL) {
            if (current->course_ID== courseID) return true;
            current = current->next;
        }
        return false;
    }

void add(int courseID, string courseName, BST &courses, Student *student) {
    Course *course = courses.findCourse(courseID);
    if (course == NULL) {
        cout << "Course with ID " << courseID << " cannot be found.\n";
        return;
    }

    // Step 1: Check prerequisites using a stack
    Stack prereqStack;
    for (int prereq : course->prerequisites) {
        prereqStack.push(prereq);
    }

    while (!prereqStack.isEmpty()) {
        int prereq = prereqStack.Peek();
        if (hasCompleted(prereq)) {
            prereqStack.pop();
        } else {
            cout << "Cannot enroll in course " << courseID << ". Remaining prerequisites: ";
            prereqStack.display();
            return;
        }
    }

    // Step 2: Handle course limits and waiting list
    if (course->studentcount < course->limit) {
        enrollment_record *newRecord = new enrollment_record(courseID, courseName,student->ID);
        if (head == NULL) {
            head = tail = newRecord;
        } else {
            tail->next = newRecord;
            newRecord->prev = tail;
            tail = newRecord;
        }
        course->studentcount++; // Increment student count for the course
        cout << "Student successfully enrolled in course " << courseName << ".\n";
    } else {
        cout << "The course is currently full. Adding the student to the waiting list.\n";
        course->waitinglist.enqueue(student);
    }
}
void drop(int course_ID,BST ctree) {
    if (head == nullptr) {
        cout << "No enrollments found to drop.\n";
        return;
    }
    BSTNode* root=ctree.root;
    Course* course=ctree.Check_courselimit(course_ID,root);
    if (course == nullptr) {
        cout << "The course with ID " << course_ID << " cannot be found.\n";
        return;
    }
    enrollment_record* current = head;
    while (current != nullptr && current->course_ID != course_ID) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Course with ID " << course_ID << " not found in enrollment history.\n";
        return;
    }
    if (current == head) {
        head = current->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    }
    else if (current == tail) {
        tail = current->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
    course->studentcount--;
     if (!course->waitinglist.isEmpty()) {
        Student* nextStudent = course->waitinglist.queueFront->data;
        course->waitinglist.dequeue();
        add(course_ID, course->CourseName, ctree, nextStudent);
    }
    cout << "Course with ID " << course_ID << " has been successfully dropped.\n";
}
void view(int id) {
    if (head == nullptr) {
        cout << "No enrollments found" << endl;
        return;
    }
    enrollment_record* temp = head;
    cout << "history of enrollments for student with id "<<id<<" is:"<<endl;
    while (temp) {
        if(temp->student_id==id){
        cout << " course ID is " << temp->course_ID << " for course " << temp->course_Name << endl;}
        temp = temp->next;}
}
enrollment_record* Partition(enrollment_record* head, enrollment_record* tail){
enrollment_record* pivot = tail;
enrollment_record* i = head->prev;

for(enrollment_record* j = head; j != tail; j = j->next){
    if(j->course_ID < pivot->course_ID){
        if(i == nullptr){
            i = head;
        }
        else{
            i = i->next;
        }

    }
}
if(i == nullptr){
    i = head;
}
else{
    i = i->next;
}
swap(i->course_ID, tail->course_ID);
swap(i->course_Name, tail->course_Name);
return i;
}

void quickSortHelper(enrollment_record* head, enrollment_record* tail){
if(head == nullptr || head == tail || head == tail->next){
    return;
}
enrollment_record* pivot = Partition(head, tail);

if (pivot != nullptr && pivot->prev != nullptr) {
        quickSortHelper(head, pivot->prev);
    }
if (pivot != nullptr && pivot->next != nullptr) {
        quickSortHelper(pivot->next, tail);
    }
}

void quickSort(){
    enrollment_record* tail = head;
    while(tail != nullptr && tail->next != nullptr){
        tail = tail->next;
    }
    quickSortHelper(head, tail);
}
~enrollment_history() {
    while (head) {
        enrollment_record* temp = head;
        head = head->next;
        delete temp;
    }
}
};
template <typename T>
class hashing{
    vector<T*> table;
    int size;
public:

    hashing(int tablesize){
        size=tablesize;
        table.resize(size,NULL);
    }
    int hashfunction(int id){
        return id%size;
    }
    void insert_students(SLL students){
        Node*curr=students.head;
        while(curr!=NULL){
        int index=hashfunction(curr->data->ID);
        Node* newNode = new Node(curr->data);
        if(table[index]==NULL){
            table[index]=newNode;
        }
        else{
            Node*temp=table[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        curr = curr->next;
        }
    }
    void insert_course(BST*bstcourses){
        vector<BSTNode*> courses=bstcourses->in_ordertraversal();
        for(int i=0;i<courses.size();i++){
            int index=hashfunction(courses[i]->course.CourseID);
            BSTNode* newCourseNode = new BSTNode(courses[i]->course);
            if(table[index]==NULL){
            table[index]=newCourseNode;
        }
        else{
            BSTNode*temp=table[index];
            while(temp->Left!=NULL){
                temp=temp->Left;
            }
            temp->Left=newCourseNode;
        }
        }
        }
    void search_student(int id){
        int index=hashfunction(id);
        Node* curr = (Node*)table[index]; // Explicit cast to Node*.
        while (curr != NULL) {
            if (curr->data->ID == id) {
                cout << "The student is found:\n";
                cout << "Name: " << curr->data->Name
                     << ", Email: " << curr->data->Email
                     << ", Phone: " << curr->data->Phone << "\n";
                return;
            }
            curr = curr->next;
        }
        cout << "The student cannot be found.\n";
    }
      void search_course(int id){
        int index=hashfunction(id);
       BSTNode*curr = (BSTNode*)table[index]; // Explicit cast to BSTNode*.
        while (curr != NULL) {
            if (curr->course.CourseID == id) {
                cout << "The course is found:\n";
                cout << "CourseID: " << curr->course.CourseID
                     << ", Name: " << curr->course.CourseName
                     << ", Credits: " << curr->course.CourseCredits
                     << ", Instructor: " << curr->course.CourseInstructor << "\n";
                return;
            }
            curr = curr->Left; // Traverse the chain.
        }
        cout << "The course cannot be found.\n";}


};

int main() {
    // Initialize data structures
    SLL studentList;
    BST courseTree;
    hashing<Node> studentHashTable(10); // Hash table for students (size 10)
    hashing<BSTNode> courseHashTable(10); // Hash table for courses (size 10)
    enrollment_history history;

    cout << "----------------------------------------------Welcome to the University Management System----------------------------------------------------" << endl;
    while (true) {
        cout << "MENU:\n"
             << "1 - Add Student\n"
             << "2 - Remove Student\n"
             << "3 - View All Students\n"
             << "4 - Add Course\n"
             << "5 - Remove Course\n"
             << "6 - View Inorder Courses Tree\n"
             << "7 - Search for a Student (Linear, Binary, Hashing)\n"
             << "8 - Search for a Course (Linear, Binary, Hashing)\n"
             << "9 - Enroll Student in a Course\n"
             << "10 - Add Course to Enrollment History\n"
             << "11 - View Enrollment History\n"
             << "12 - Sort Students (Quicksort)\n"
             << "13 - Exit Program\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add a student
            cin.ignore();
            string name, email, phone, address, password;
            int id;
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Student Email: ";
            getline(cin, email);
            cout << "Enter Student Phone: ";
            getline(cin, phone);
            cout << "Enter Student Address: ";
            getline(cin, address);
            cout << "Enter Student Password: ";
            getline(cin, password);
            cout << "Enter Student ID: ";
            cin >> id;

            studentList.addToTail(new Student(name, email, phone, address, password, id));
            studentHashTable.insert_students(studentList);
            break;
        }
        case 2: {
            // Remove a student
            int id;
            cout << "Enter Student ID to Remove: ";
            cin >> id;
            studentList.deleteStudent(id);
            studentHashTable.insert_students(studentList); // Update hash table
            break;
        }
        case 3: {
            // View all students
            studentList.display();
            break;
        }
        case 4: {
            // Add a course
            cin.ignore();
            int id, credits;
            string name, instructor;
            vector<int> prereqs;
            cout << "Enter Course ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Course Name: ";
            getline(cin, name);
            cout << "Enter Course Credits: ";
            cin >> credits;
            cin.ignore();
            cout << "Enter Course Instructor: ";
            getline(cin, instructor);
            cout << "Enter Prerequisites (space-separated, end with -1, if it doesnot require Prerequisites enter 0): ";
            int prereq;
            while (cin >> prereq && prereq != -1 && prereq!=0) {
                prereqs.push_back(prereq);
            }
            cin.ignore();

            courseTree.addCourse(id, name, credits, instructor, prereqs);
            courseHashTable.insert_course(&courseTree);
            break;
        }
        case 5: {
            // Remove a course
            int id;
            cout << "Enter Course ID to Remove: ";
            cin >> id;
            courseTree.dropCourse(id);
            courseHashTable.insert_course(&courseTree); // Update hash table
            break;
        }
        case 6: {
            // View inorder courses tree
            cout << "Inorder Traversal of Courses:\n";
            courseTree.inorder(courseTree.root);
            break;
        }
        case 7: {
            // Search for a student
            int id;
            cout << "Enter Student ID to Search: ";
            cin >> id;
            cout << "Choose Search Method (1 - Linear, 2 - Binary, 3 - Hashing): ";
            int method;
            cin >> method;

            if (method == 1) {
                studentList.linear_studentsearch(id);
            } else if (method == 2) {
                studentList.quickSort(); // Ensure the list is sorted
                studentList.binary_searchstudent(id);
            } else if (method == 3) {
                studentHashTable.search_student(id);
            } else {
                cout << "Invalid search method.\n";
            }
            break;
        }
        case 8: {
            // Search for a course
            int id;
            cout << "Enter Course ID to Search: ";
            cin >> id;
            cout << "Choose Search Method (1 - Linear, 2 - Binary, 3 - Hashing): ";
            int method;
            cin >> method;

            if (method == 1) {
                courseTree.linear_coursesearch(id);
            } else if (method == 2) {
                courseTree.binary_coursesearch(id, courseTree.root);
            } else if (method == 3) {
                courseHashTable.search_course(id);
            } else {
                cout << "Invalid search method.\n";
            }
            break;
        }
        case 9: {
            // Enroll a student in a course
            int studentID, courseID;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;

            Student* student = nullptr;
            Node* current = studentList.head;
            while (current != nullptr) {
                if (current->data->ID == studentID) {
                    student = current->data;
                    break;
                }
                current = current->next;
            }

            if (student == nullptr) {
                cout << "Student not found.\n";
                break;
            }

            // Retrieve the course name
            Course* course = courseTree.findCourse(courseID);
            if (course == nullptr) {
                cout << "Course not found.\n";
                break;
            }

            // Call the add method with all required parameters
            history.add(courseID, course->CourseName, courseTree, student);
            break;
        }
        case 10: {
            // Add course to enrollment history for a specific student
            int studentID, courseID;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID to add to enrollment history: ";
            cin >> courseID;

            Student* student = nullptr;
            Node* current = studentList.head;
            while (current != nullptr) {
                if (current->data->ID == studentID) {
                    student = current->data;
                    break;
                }
                current = current->next;
            }

            if (student == nullptr) {
                cout << "Student not found.\n";
                break;
            }

            // Retrieve the course name
            Course* course = courseTree.findCourse(courseID);
            if (course == nullptr) {
                cout << "Course not found.\n";
                break;
            }

            // Call the add method with all required parameters
            history.add(courseID, course->CourseName, courseTree, student);
            break;
        }
        case 11: {
            // View enrollment history
            int id;
            cout<<"Enter student id: ";
            cin>>id;
            history.view(id);
            break;
        }
        case 12: {
            // Sort students using quicksort
            studentList.quickSort();
            cout << "Students have been sorted successfully.\n";
            break;
        }
        case 13: {
            // Exit program
            cout << "Thank you for using the University Management System. Goodbye!\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n";
    }
    return 0;
}
