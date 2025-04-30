# CPP Module 04 — Peer-Evaluation Checklist

---

## 1. Introduction & Ground Rules
- **Tone & Spirit**
  - Stay **polite**, **courteous**, **respectful**, and **constructive** throughout the evaluation.
  - Treat peer-evaluation as a shared learning opportunity.
- **Scope of Review**
  - Only grade **what’s in the student’s Git repository**.
  - Clone into an **empty** folder and verify it’s the correct project.
  - Watch out for malicious aliases or scripts—if in doubt, ask the student to demonstrate. ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

---

## 2. General Guidelines
1. **Repository & Build**
   - Must compile with `c++ -Wall -Wextra -Werror` under **C++98**.
   - **Forbidden**:
     - Function implementations in headers (except templates),
     - C functions (`malloc`, `printf`, `free`, etc.),
     - `using namespace std;` or `friend` keyword,
     - External libraries or C++11+ features.
2. **Testing & Automation**
   - Look for provided test scripts or Makefile helpers.
   - If **no tests** or **insufficient coverage**, do **not** grade the exercise.
3. **Memory Safety**
   - Use `valgrind`, `leaks`, or `e_fence`.
   - **Zero** memory leaks at program exit—flag any leaks. ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

---

## 3. Preliminary Tests & Flags
- **Cheating**
  - If suspected, stop evaluation and flag **Cheat** (grade = –42).
- **Empty Repository** / **Non-functioning Program** / **Norm Error**
  - Use the corresponding flag; evaluation ends with grade = 0 (except Cheat). ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

---

## 4. Exercise-by-Exercise Details

### Ex00 — Polymorphism
- **Main & Tests**
  - Must include enough tests to prove expected behavior.
  - If any non-interface class isn’t in **orthodox canonical form**, do not grade.
- **Animal Base Class**
  - Attribute: `std::string type;`
  - Must instantiate and use `Animal`.
- **Derived Classes**
  - `Cat` and `Dog` inherit from `Animal`.
  - Constructors/destructors print clear, distinct messages—ask about order.
- **makeSound()**
  - Declared `virtual void makeSound() const;` in `Animal`.
  - Behavior must dispatch correctly at runtime.
- **WrongAnimal Demo**
  - Include `WrongAnimal` & `WrongCat` _without_ `virtual`.
  - Verify `WrongCat`’s `makeSound()` only prints when called on `WrongCat`. ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

### Ex01 — I Do Not Want to Set the World on Fire
- **New Class: `Brain`**
  - `Cat` and `Dog` each have a **private** `Brain` member.
  - `Brain` ctor/dtor print specific messages.
- **Deep Copy Semantics**
  - Copy constructor and assignment operator must perform a **deep copy** of `Brain`.
  - Test scenario:
    ```cpp
    Dog basic;
    {
      Dog tmp = basic;
    } // tmp’s Brain destroyed—basic still valid
    ```
- **Destruction Chaining**
  - Destructors in `Animal`, `Cat`, `Dog` must be `virtual`.
  - Ask what happens if `virtual` is omitted; verify correct chain. ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

### Ex02 — Abstract Class
- **Pure Virtual Base**
  - `Animal` as in Ex00 but with
    ```cpp
    virtual void makeSound() const = 0;
    ```
  - Cannot instantiate `Animal` (should be a compile-time error).
- **Concrete Animals**
  - `Cat` and `Dog` implement `makeSound()` exactly as in Ex01.

### Ex03 — Interface & Recap
- **Interfaces**
  - `ICharacter` and `IMateriaSource` defined per subject.
  - `MateriaSource` implements `IMateriaSource` correctly.
- **Materia Classes**
  - Abstract `AMateria` with
    ```cpp
    virtual AMateria* clone() const = 0;
    virtual ~AMateria();
    protected: std::string type;
    ```
  - Concrete `Ice` and `Cure` inherit `AMateria`, implement `clone()`, and print correct messages.
- **Character**
  - Implements `ICharacter` with an inventory of up to 4 `AMateria*`.
  - Member functions (`equip`, `unequip`, `use`, etc.) behave as specified.
  - Copy constructor and assignment operator perform **deep copy** of inventory. ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

---

## 5. Ratings & Flags
- **Outstanding project**
- **Empty work**
- **No author file**
- **Invalid compilation**
- **Norme**
- **Cheat**
- **Crash**
- **Leaks**
- **Forbidden function** ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)

---

## 6. Final Comments
- Select appropriate flag(s) and leave a **constructive comment**.
- If you flag **Cheat**, be ready to calmly justify with evidence.
- Highlight strengths even if overall grade is low.

---

*Source: ng_4_cpp_module_04.pdf* ng_4_cpp_module_04.pdf](file-service://file-PwTK42Wrf5NjBP2Qi1VwcH)
