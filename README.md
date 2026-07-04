#  Ludo Game Engine (C++)

A console-based Ludo Game Engine developed in **C++** using **Object-Oriented Programming (OOP)** principles. This project is being built step by step with a focus on clean architecture, modular design, and professional software development practices.

##  Project Goal

The objective of this project is to design and implement a complete Ludo game engine from scratch while applying core software engineering concepts such as:

- Object-Oriented Programming (OOP)
- Encapsulation
- Composition
- Constructors & Initializer Lists
- References
- Modular Class Design
- Git & GitHub Version Control

---

## Completed Components

### Token Class
- Stores token position, color, and unique ID.
- Implements token movement according to Ludo rules.
- Supports:
  - Moving out of base on rolling a six.
  - Preventing moves beyond the home position.
  - Position, color, and ID getters.

### Player Class
- Stores player name and color.
- Owns four Token objects.
- Initializes all tokens using constructor initializer lists.
- Supports:
  - Accessing individual tokens safely.
  - Checking whether all tokens have reached home.

---

##  Current Progress

- ✅ Token Class
- ✅ Player Class
- ⏳ Dice Class
- ⏳ Board Class
- ⏳ Game Class
- ⏳ Complete Ludo Gameplay

---

## 🛠 Technologies

- C++
- Microsoft Visual Studio 2022
- Git
- GitHub

---

##  Development Log

### Version 0.1
- Project initialized.
- Implemented Token class.
- Implemented Player class.
- Verified interaction between Player and Token classes.

---

*This repository is part of my journey to strengthen my C++ and software engineering skills by building real-world projects from scratch.*
