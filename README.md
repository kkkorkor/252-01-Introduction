# System Programming Lab: Functions Across Libraries (Legacy to Modern API)

## 1. Learning Objectives
By the end of this lab, you should be able to:
- call functions defined in different compilation units
- package code into a static library (`.a`) and a shared library (`.so`)
- migrate from older C-style parsing patterns to safer modern APIs
- produce deterministic CLI output that is easy to autograde

## 2. Story
You are modernizing a tiny profile parser used by an old system.

Input records look like this:
- `Name Here:Year`

You must implement two APIs:
- **legacy API**: tolerant behavior (older style)
- **modern API**: strict validation and safer function contracts

The main program will run both APIs side-by-side and print a migration report.

## 3. Repository Layout
- `src/`: starter source files
- `include/`: header definitions
- `samples/`: static test input used by grader
- `scripts/`: local checks and grading hooks
- `tests/`: visible test notes

## 4. What You Need To Implement
Complete all `TODO(student)` blocks in:
- `src/legacy_api.c`
- `src/modern_api.c`

Required behavior:
1. `legacy_parse_year()` uses old-style parsing behavior
2. `modern_parse_year()` uses strict parsing (`strtol`) and rejects malformed years
3. `legacy_make_slug()` creates lowercase name slugs with underscores for spaces
4. `modern_make_slug()` does the same with buffer-size safety checks

## 5. Build
```bash
make
```

## 6. Run
```bash
./bin/api_bridge_lab samples/records.txt
```

## 7. Expected Output (Exact)
```text
01 | Ada Lovelace | legacy=ada_lovelace:1815 | modern=ada_lovelace:1815 | status=OK
02 | Grace Hopper | legacy=grace_hopper:1906 | modern=grace_hopper:1906 | status=OK
03 | Dennis Ritchie | legacy=dennis_ritchie:1941 | modern=dennis_ritchie:1941 | status=OK
04 | Linus Torvalds | legacy=linus_torvalds:0 | modern=ERROR | status=MIGRATE
05 | Ken Thompson | legacy=ken_thompson:1943 | modern=ERROR | status=MIGRATE
06 | Margaret Hamilton | legacy=margaret_hamilton:1936 | modern=margaret_hamilton:1936 | status=OK
```

## 8. Test and Grade Hooks
```bash
make check
make grade
```

## 9. Rules
- do not change function signatures in `include/api_bridge_lab.h`
- do not change output format in `src/api_bridge_lab.c`
- keep visible output deterministic
- compile with warnings enabled and no errors

## 10. Academic Integrity
- write your own implementation
- discussing concepts is allowed
- sharing finished code is not allowed

## 11. Instructor Notes
- this exported template is student-facing and intentionally does not include `solutions/`
ั