# Week 1 reflection

Write concise answers in your own words.

## 1. Source and executable

What is the difference between `src/hello.cpp` and `build/manual/hello` after compilation?

Answer:
`src/hello.cpp` is the C++ source code, while `build/manual/hello` is the compiled executable program.
## 2. Compiler warnings

What is the purpose of `-Wall -Wextra -Wpedantic`?

Answer:
They enable extra compiler warnings that help find possible mistakes and suspicious code.
## 3. Value and reference parameters

What is the difference between these declarations?

```cpp
void f(std::vector<int> values);
void f(std::vector<int>& values);
```

Answer:
The first function gets a copy of the vector. The second function gets a reference to the original vector and can modify it.

## 4. Const reference

Why can this parameter form be useful?

```cpp
void print(const std::vector<int>& values);
```

Answer:
It avoids copying the vector and does not allow the function to modify it through this reference.

## 5. Linux navigation

Which command shows the current working directory?

Answer:
pwd
## 6. Git state

Which command shows modified files?

Answer:
git status
