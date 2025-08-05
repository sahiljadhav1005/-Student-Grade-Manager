# 🎓 Student Grade Manager (C++ Project)

A complete C++ console-based system for managing student records, calculating grades, and exporting results — structured using OOP with `.h/.cpp` files.

## 🚀 Features

- 🔐 Login system with password masking
- 👥 Multiple user support (admin/teacher via `admin.txt`)
- 🔁 Change password from inside the app
- ➕ Add, edit, delete student records
- 🧾 Add subjects and marks per student
- 📊 Grade and average calculation (A–F)
- 🏆 Student ranking system
- 📤 Export to CSV (`subjectwise.csv`, `summary.csv`)
- 💾 File persistence (`students.txt`)

## 🧱 Technologies Used

- Language: C++
- Concepts: OOP, File Handling, std::map, std::vector, Sorting

## 📁 Files

| File             | Purpose                                |
|------------------|----------------------------------------|
| main.cpp         | Entry point and menu UI                |
| Login.*          | Handles user login and password change |
| Student.*        | Data structure and grade logic         |
| StudentManager.* | All student operations (CRUD, ranking) |
| admin.txt        | Stores username-password               |
| students.txt     | Persistent student data                |
| CSV files        | Auto-generated from data               |

## 🧪 Sample Login

Username: admin
Password: ****

## topics and where they use

| Topic                 | Explanation                                                  |
|-----------------------|--------------------------------------------------------------|
| **OOP**               | Classes used: `Student`, `StudentManager`                    |
| **Encapsulation**     | Student data + operations hidden inside class                |
| **File Handling**     | Uses `ifstream`, `ofstream`, `fstream` for `.txt` and `.csv` |
| **Login System**      | Reads from `admin.txt`, allows password masking              |
| **CSV Export**        | Writes subject and grade summaries using `ofstream`          |
| **Sorting (Ranking)** | Uses `std::sort()` on average marks                          | 
| **Data Storage**      | Uses `students.txt` instead of a database                    |

## 🔷 4. Flowchart (Text Version)

```
[Start]
   ↓
[Login Screen] 
   ↓ (if correct)
[Show Menu]
   ↓
[1. Add Student] ←→ [2. Edit] ←→ [3. Delete]
   ↓
[4. Add Subject + Marks]
   ↓
[5. View All] ←→ [6. Search by Roll] ←→ [7. Search by Name]
   ↓
[8. Show Topper] ←→ [9. Export CSV] ←→ [10. Show Ranking]
   ↓
[99. Change Password]
   ↓
[0. Exit]
```
