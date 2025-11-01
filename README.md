# MP3 Tag Reader and Editor

The **MP3 Tag Reader and Editor** is a C-based command line project that lets users **read**, **display**, and **modify** MP3 file metadata (ID3 tags).  
It demonstrates concepts like **file handling**, **pointer manipulation**, and **string operations** in C.

## 🔍 How It Works
The program reads the **last 128 bytes** of an MP3 file, where the **ID3v1 tag** information is stored.  
This section contains fields like **Title, Artist, Album, Year, Comment**, and **Genre**.  
Each field has a fixed size, so the program extracts these bytes, displays them, and allows the user to edit and update them directly in the file.

## ⚙️ Key Functions and Flow
- **Validation** – Checks if the input file is a valid MP3 file.  
- **Reading tags** – Opens the file in read mode, seeks to the last 128 bytes, and reads the tag data.  
- **Displaying tags** – Prints the extracted details (Title, Artist, Album, etc.) in a readable format.  
- **Editing tags** – Lets the user modify any tag field, updates the structure, and writes the modified data back into the MP3 file.  
- **Usage messages** – Displays usage instructions and valid command formats.  
- **main function** – Controls program flow, processes user input, and calls the appropriate functions.


## 📘 Example
```bash
./mp3_tag_reader -v song.mp3     # View MP3 tag info
./mp3_tag_reader -e song.mp3     # Edit MP3 tag info 
```
**👨‍💻 Author**

 Alwin Labu  
 Embedded Systems & C Programming Enthusiast
