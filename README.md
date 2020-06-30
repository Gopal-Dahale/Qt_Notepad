# Qt_Notepad
Simple notepad made using QtCreator 

## Ubuntu and Qt version
Compiled and tested on Ubuntu 20.04 with Qt 5.14.2

## Installation
1. Install Qt 5
  - $ sudo apt-get install qt5-default
2. Open terminal in Qt_Notepad folder and run the following commands
  - $ qmake notepad.pro
  - $ make
 
## How to run the code?
To execute the file in Qt_Notepad folder  
  - $ ./notepad
  
## What has been done?
The notepad has basic tools needed a create any file. It has a toolbar with the following features
1. File
  - New file
  - Open existing file
  - Save file
  - Save file as (some name with extension)
2. Edit
  - Cut
  - Copy
  - Paste
  - Undo / Redo
  
Shortcuts are also present for the above operations.
The WindowTitle shows the name of the current file. If no file is selected it shows Untitled.

## Issues
No known issues

## Features
The following two features are added
  - Bold
    Selected text can be bolded using Ctrl+B
  - Font
    Font family and size of selected text can be controlled from the toolbar.














