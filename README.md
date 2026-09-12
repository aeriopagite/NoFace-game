# No-Face Terminal Game

A classic Snake-style game built from scratch in C, themed around No Face
from *Spirited Away*. Runs in the terminal. Currently in development.

## About

I built this to strengthen my C fundamentals as a Computer Engineering
student. Rather than use a tutorial, I built it up in stages and made sure
I understood every line — the game loop, keyboard input handling, and the
logic that drives movement.

## What it does (so far)

- Renders a bordered game board in the terminal
- No Face's head is steerable in real time with the WASD keys
- Runs on a continuous game loop with adjustable speed

## In progress

- Food to collect
- A growing body that trails behind the head
- Collision detection (game over on hitting a wall or itself)

## What I learned

- **The game loop**: the core cycle of clear → draw → update → pause that
  drives every frame
- **Non-blocking keyboard input**: using `kbhit()` and `getch()` from
  `conio.h` to read key presses without freezing the loop
- **The `switch` statement** for clean multi-way direction control
- **Terminal quirks**: OS-specific screen clearing and input handling
  (`conio.h` is Windows-specific; Unix uses `termios`)

## How to build and run

Requires GCC. From the project folder:

    gcc NoFace.c -o NoFace
    ./NoFace

Use **W / A / S / D** to steer. Press **Ctrl + C** to quit.

## Tech

Written in C. Compiled with GCC. Developed on Windows (MSYS2).
