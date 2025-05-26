# SampleGame

This folder contains the sample application built on top of DreamEngine.  
It is designed to test, validate, and demonstrate the core systems of the engine in a real project context.

- `src/` – Application source code (entry point, gameplay logic, system tests).
- `CMakeLists.txt` – Build configuration for the sample game.
- `README.md` – This documentation file.

_This project serves as a sandbox for development, integration testing, and quick prototyping using DreamEngine._

---

## Purpose

- Showcase the usage of DreamEngine as a library.
- Test logging, timing, memory allocation, and other subsystems in practice.
- Provide a starting point and reference structure for future game projects built on the engine.

---

## How to Build & Run

1. Ensure DreamEngine is built and available as a library.
2. Build SampleGame:
   ```sh
   cd SampleGame
   mkdir build && cd build
   cmake ..
   cmake --build .
