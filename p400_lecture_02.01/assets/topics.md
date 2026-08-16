---
# Topics — p400_lecture_02.01
---

| Topic | Emphasis | Time Budget | Optional | Prerequisites | Tone Flag | Note |
|-------|----------|-------------|----------|---------------|-----------|------|
| How the Compiler Works | standard | 12 | no | 01.02 | | preprocessing/compilation/linking pipeline; plantuml stage diagram |
| The Symbol Table | standard | 10 | no | How the Compiler Works | | compiler's identifier record; type checking; scope resolution |
| Data Type Conversion and Casting | standard | 10 | no | 01.02 Data Types | | implicit promotion vs narrowing; static_cast; PDF content from 3-7x.cpp |
| Overflow and Underflow | standard | 15 | no | Data Type Conversion | | signed undefined behavior; unsigned wraps; numeric_limits; detection |
| Signed vs Unsigned Variables | standard | 8 | no | 01.02 Data Types | | two's complement sign bit; mixing signed/unsigned silently converts |
| Fixed-Width Integers and size_t | standard | 8 | no | Signed vs Unsigned | | <cstdint> exact-width types; size_t for indices |
| Determining Variable Size | standard | 6 | no | Fixed-Width Integers | | sizeof operator; typical sizes table; compile-time evaluation |
