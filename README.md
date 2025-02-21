# Calculator

## Description

A simple C++ command-line calculator.

### Example:

```
4+5*2  → 14
X+2*9-8/3*(2-1) - 32.4 → Asks for X, then computes result.
```

## Setup

### 1. Clone and Build

```sh
git clone https://github.com/TaurasR/Calculator.git
cd Calculator
mkdir build && cd build
cmake .. && cmake --build .
```

### 2. Run the Calculator

```sh
./Debug/calculator.exe  # Windows
./calculator            # Linux/Mac
```

---

## Usage

```sh
Enter an expression: 4+5*2
Result: 14
```

With variables:

```sh
Enter an expression: x+3*4
Enter value for x: 5
Result: 17
```

---

## Run Tests

```sh
./Debug/calculator_tests.exe  # Windows
./calculator_tests            # Linux/Mac
```

---

