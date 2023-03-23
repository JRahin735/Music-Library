# Music-Library
Creating a music library search system using C++ maps and sets



Collaboration Policy
By submitting this assignment, you are acknowledging you have read the collaboration policy in the syllabus for projects.  This project should be done individually.  You may not receive any assistance from anyone outside of the CS 251 teaching staff.


Late Policy
You are given the grace period between the deadline and the first lecture of the following day (9am). You do not need to let anyone know you are using this grace period. Beyond this period, no late submissions will be accepted.


What & Where to Submit
zyBooks - musiclibrary.cpp (Implementation Scores)
Gradescope - musiclibrary.cpp (Style & Implementation Restrictions)'


Do not submit any additional files.


Table of Contents
Project Summary
Program and Coding Restrictions
Data Files
Milestone 0 - Starter Program
Milestone 1 - load Command
Milestone 2 - stats Command
Milestone 3 - clear Command
Milestone 4 - export Command
Milestone 5 - search Command
Requirements Reminders
Example Execution and Solution Execution






Copyright Notice
Copyright 2023 Adam T Koehler, PhD - University of Illinois Chicago
This assignment description is protected by U.S. copyright law. Reproduction and distribution of this work, including posting or sharing through any medium, such as to websites like chegg.com is explicitly prohibited by law and also violates UIC's Student Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. Participation in Academically Dishonest Activities: Material Distribution). 

Material posted on any third party sites in violation of this copyright and the website terms will be removed. Your user information will be released to the author.



Project Summary
Music libraries are everywhere in our lives. Whether we have personal libraries or live in Spotify the ability to load, store, display, and alter the information is at the backend of every system. Additionally, users must be able to effectively search massive libraries of music to discover what they are looking for. In this project, you will recreate a piece of this technology by using the map and set abstractions to build a music library search engine that can find album titles that match a user's query in addition to implementing some basic library interactions. 


This is a simplified version of a music library as we strip away graphical interfaces and some of the interactions that might seem useful to help pair down the project. In our version, the music database files will have album titles, artists, and songs. Every music data file is set up the same way, and our system has a series of commands to interact with the data files (load & export) as well as displaying information about the data once it is in the program.


You will need to use your own implementation strategies, but we strongly suggest function decomposition be at the forefront of your algorithm design. Significant chunks of code have been provided for you to use, so starting by reading this project description in full and then the provided code and other materials is a must.


Program and Coding Restrictions
You may not use classes or pointers or global variables. You may use structs. You may not use any containers except the standard C++ library set and map containers. Violating these restrictions will result in a zero on your project.

Data Files
The load & export commands deal with the data files. See the help commands for more information. The file format is the same across all data files. Album names are unique across the library, song and artist names are unique within an album. There may be zero artists but there will always be at least one song.


General Format
Example Data File
Example Data File
Album Title
Artist Name
Artist Name
01 Song Title
02 Song Title
Album Title



Milestone 0 - Starter Program
Completely read this entire project description and all the provided starter files. Get the starter code compiling and executing on your IDE. The program should compile and execute and both "exit" and "help" commands should work.


Use the help command to read more about all the commands that you will be implementing throughout the project. Within the help command output there are descriptions of all the commands and examples of use. Note that items in square brackets are optional e.g. the filename for the load command.


Milestone 1 - load Command
With the project code restrictions in mind, implement the load command. Load in the data files so that you may have access to the information later to compute stats and or search the music library for albums. Run the help command for more information. Note that loading additional files adds to the music library, it does not replace the library. Only one file at a time.


Milestone 2 - stats Command
Implement the stats command. See the project execution example and the help command for more information. This step is useful to demonstrate that you are correctly loading in all the data from one or more files.


Milestone 3 - clear Command
Implement the clear command. Run the help command for more information. 


Milestone 4 - export Command
Implement the export command. Send the data out following the same format as the provided files so that they may be easily read in by yours and other Music Library project implementations. Run the help command for more information. 


Milestone 5 - search Command
Implement the search command. The search command is utilized to discover album sets within the music library that match the search criteria. The search command can search album titles, artist names, or song titles. Examples of search are provided in the help command. We strongly suggest breaking this milestone into chunks and testing as you implement the pieces. Common chunks would be the field of search (album, artist, or song) and another chunk may be the behaviors when multiple search terms exist. While the data information is stored in the format that it comes in as, searching is not case sensitive and therefore searching for "Taylor", "TAYLOR", and "taylor" will all result in the same thing. Run the help command for more information.


Requirements Reminders
You cannot change the provided code (in any of the files).  
You are allowed to use and add other libraries (make sure to include them at the top of your file).  However, you do not need many.  Any standard C++ library is allowed for this project barring those with project code restrictions.  You either must find them and figure out how to use them, or write your own functionality.  
Each input file may be opened and read exactly once.
Your code file must have a header comment with your name and a program overview.  Each function must have a header comment above the function, explaining the function’s purpose, parameters, and return value (if any). Inline comments should be supplied as appropriate; comments like “declares variable” or “increments counter” are useless. Comments that explain non-obvious assumptions or behavior are appropriate.
No global variables; use parameter passing and function return. No classes. No pointers. No heap allocation. No use of containers except for standard library sets and maps.
The cyclomatic complexity (CCN) of any function should be minimized.  In short, cyclomatic complexity is a representation of code complexity --- e.g. nesting of loops, nesting of if-statements, etc. You should strive to keep code as simple as possible, which generally means encapsulating complexity within functions (and calling those functions) instead of explicitly nesting code. 
As a general principle, if we see code that has more than 2 to 3 levels of explicit looping that score will receive grade penalties. The solution is to move one or more loops into a function, and call the function.



Execute the Solution For More Examples
Create / Fork the Replit with the solution executable in it. 
Open the shell or console. Type ./project2.out to execute the project.
Replit: https://replit.com/@atkoehler/Professors-Project-Executables


Example Execution
Input
load music01_todiff.txt
search album fearless
search album fearless love
search artist taylor -swift
search song you
stats
stats -d
export music01_fromprogram.txt
exit






The above input can be typed or inserted into a file. It produces the output to the right when using input redirection with an input file.


./a.out < input.txt
Output
Welcome to the Music Library App
--------------------------------


Enter a command (help for help): 




Enter a command (help for help): 


Your search results exist in the following albums: 
Fearless




Enter a command (help for help): 


Your search results exist in the following albums: 
Fearless
FutureSex/LoveSounds




Enter a command (help for help): 


No results found.




Enter a command (help for help): 


Your search results exist in the following albums: 
Fearless
Midnights




Enter a command (help for help): 


Overall Music Library Stats
===========================
Total Records: 3
Total Unique Artists: 2
Total Songs: 17




Enter a command (help for help): 


Overall Music Library Stats
===========================
Total Records: 3
Total Unique Artists: 2
Total Songs: 17


Your Current Music Library Includes
===================================
Fearless
 Taylor Swift
   01 Breathe
   02 Change
   03 Love Story
   04 Hey Stephen
   05 You're Not Sorry
   06 Forever & Always
FutureSex/LoveSounds
 Justin Timberlake
   01 SexyBack
Midnights
 Taylor Swift
   01 Snow on the Beach
   02 You're on Your Own Kid
   03 Question...?
   04 Sweet Nothing
   05 Maroon
   06 Anti-Hero
   07 Midnight Rain
   08 Paris
   09 Glitch
   10 Karma




Enter a command (help for help): 




Enter a command (help for help): 


Thank you for using the Music Library App

