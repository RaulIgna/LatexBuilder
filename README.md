# LatexBuilder 📄

**LatexBuilder** is a simple and easy to use CLI tool that allows you to generate .tex files from user defined templates. 🛠
You can create your own templates using JSON. 


LatexBuilder will then parse your template and generate a .tex file that you can compile with your preferred LaTeX engine. LatexBuilder is ideal for creating reports, presentations, papers, and other documents that follow a similar structure and style. 📚

## Usage 🖥
On **Windows**:

- Download the source code and compile it using make or download the binaries 
- From a terminal of your choice launch the program using the following arguments: 

`./LatexBuilder.exe <template> <name> <path>` where
- _\<template\>_ is the name of the template 
- _\<name\>_ is the name of the file to be created 
- _\<path\>_ is the directory where the program will be saved 

On **Linux**:

The linux version will come out soon! Sit tight! ⏳

## Templates 📐

The templates are stored in `C:\Users\Public\Documents\LatexBuilder` for now.

**JSON** is used to store templates that have multiple objects. 