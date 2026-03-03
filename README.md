# 🧩 Sudoku Console Game (C Language)

## 📌 Project Overview

This project is a console-based Sudoku game implemented in pure C.

It allows the player to solve a 9×9 Sudoku puzzle using keyboard controls,
with full rule validation, mistake tracking, and win/lose conditions.

The project follows a modular design separating:

- Game Logic (validation, moves, rules)
- Rendering Layer (console UI)
- Application Layer (main loop & controls)

---

## 🎮 Gameplay Features

- Three difficulty levels (Easy / Medium / Hard)
- Arrow key navigation
- Number input (1–9)
- Protection of original puzzle cells
- Real-time rule validation
- Mistake tracking system
- Game Over after 3 mistakes
- Win detection when board is full
- Colored console rendering
- 3×3 block visual separation

---

## 🧠 Core Idea

The game enforces Sudoku rules through a validation system:

- A number cannot repeat in the same row.
- A number cannot repeat in the same column.
- A number cannot repeat inside a 3×3 subgrid.

Each move is validated before being applied to the board.

The application layer continuously runs a game loop that:
- Renders the board
- Handles user input
- Checks win/lose conditions
- Updates the game state

---

## 🏗 Architecture

The project is structured into:

- `sudoku.c` → Core game logic
- `sudoku.h` → Public interface
- `main.c` → Application layer

This separation ensures clean architecture, maintainability,
and clear responsibility for each module.

---

## 🎯 Project Purpose

This project was built to:

- Practice structured programming in C
- Apply modular design principles
- Implement real-time input handling
- Manage state and validation logic
- Build a fully interactive console application

---

## 👨‍💻 Author

Abdelrahman Elzayat  
C Developer | Embedded Systems Enthusiast
