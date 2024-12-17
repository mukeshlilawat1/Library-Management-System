# Library-Management-System
Here is a well-formatted **`README.md`** file suitable for your GitHub repository:

---

# 📚 **Lilawat Library Management System**

**Lilawat Library Management System** is a console-based C++ application designed to manage a library's book records. It allows users to add, view, search, delete, and count books efficiently.

---

## 🚀 **Features**

### ✅ **Core Features**
1. **Add New Books**  
   - Input book details:  
     - Book ID  
     - Book Name  
     - Author Name  
     - Book Status (Available/Issued)  
     - Date and Time of Addition  
2. **View All Books**  
   - Display a list of all books with their details in a user-friendly format.  
3. **Search Book by ID**  
   - Extract and display specific book details using a unique **Book ID**.  
4. **Search Books by Author**  
   - Search for books written by a specific author.  
5. **Delete Book by ID**  
   - Remove a book record using its unique **Book ID**.  
6. **Count Total Books**  
   - Display the total number of books in the system.  

---

## 🛠️ **Technologies Used**
- **Programming Language**: C++  
- **File Handling**: Text-based storage using `fstream`  

---

## 📂 **Project Structure**
```
|-- LilawatLibrary.cpp    # Main program file
|-- BookData.txt          # Stores all book records
|-- README.md             # Project documentation
```

---

## ⚙️ **How to Run**

### **Prerequisites**
- C++ Compiler (e.g., `g++`, CodeBlocks, Visual Studio)

### **Steps to Compile and Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/LilawatLibrary.git
   cd LilawatLibrary
   ```

2. Compile the program:
   ```bash
   g++ LilawatLibrary.cpp -o LilawatLibrary
   ```

3. Run the program:
   ```bash
   ./LilawatLibrary
   ```

---

## 📝 **Usage Instructions**

### Main Menu:
When you run the program, the following menu will appear:
```
------- Welcome To Lilawat Library --------
1 - Show All Books
2 - Add New Book
3 - Delete Book
4 - Search Book by Author Name
5 - Count Total Books
6 - Exit
-------------------------------------------
Enter Your Choice:
```

1. **Option 1**: View all books in the library.  
2. **Option 2**: Add a new book with ID, name, author, and status.  
3. **Option 3**: Delete a book by its unique Book ID.  
4. **Option 4**: Search and display books by a specific author's name.  
5. **Option 5**: Show the total number of books in the library.  
6. **Option 6**: Exit the program.  

---

## 📄 **File Details**

### **BookData.txt**
All the book data is stored in a text file (`BookData.txt`) in the following format:  
```
BookID|BookName|AuthorName|Status|DateAdded
```

### Example:
```
101|The Alchemist|Paulo Coelho|Available|Mon Jan 1 15:34:56 2024
102|1984|George Orwell|Issued|Mon Jan 1 16:00:00 2024
```

---

## 🔧 **Future Improvements**
- Add book issue/return management system.  
- Implement sorting books by ID, name, or author.  
- Improve UI using a graphical library.  

---

## 🤝 **Contributing**
Contributions are welcome!  
- Fork the repository.  
- Create a new branch (`git checkout -b feature-branch`).  
- Make changes and commit them (`git commit -m "Add feature"`).  
- Push to the branch (`git push origin feature-branch`).  
- Submit a pull request.  

---

## 📜 **License**
This project is licensed under the MIT License.  

---

## 👨‍💻 **Author**
- **Your Name**  
- GitHub: [MukeshLilawat](https://github.com/mukeshlilawat1)  

---

Feel free to customize this README further as per your needs! 🚀
