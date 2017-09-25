# contests

[![CircleCI](https://circleci.com/gh/competitive-programming-itb/contests/tree/master.svg?style=svg)](https://circleci.com/gh/competitive-programming-itb/contests/tree/master)

Solutions to various CP contests (especially Indonesian local contests), written by teams from Institut Teknologi Bandung.

## Contributing guide

All ITB students are very welcomed to contribute to this repository. To make everything neat and structured well, it is recommended to follow these guide before adding your solutions.

1. Project structure. This should be self-explanatory.

        ├── INC2016                 // <ContestName><Year>
        │   ├── A-Ainge WF.cpp      // Solutions goes here
        │   ├── A-GituKanYa.cpp     // <ProblemCode>-<TeamName>.<extension>
        │   ├── B-Ainge WF.cpp
        │   ├── C-nagazaky.cpp
        │   ├── ...
        │   ├── editorials          // Where to put editorials. This is optional
        │   │   ├── A.md            // <ProblemCode>.md
        │   │   ├── B.md            // Currently only markdown is supported
        │   │   ├── E.md            // Missing editorials are fine (C & D in this case)
        │   │   └── ...
        │   └── problems            // Where to put problem statements.
        │       │                   // This is optional, too, but very recommended
        │       ├── A.md            // <ProblemCode>.md
        │       ├── B.md
        │       └── ...
        │   ...
        ├── VOCOMFEST2017
        │   ├── qualification       // If contest has several phases/rounds,
        │   │   │                   // each should have their own subfolders.
        │   │   ├── A-Ainge WF.cpp
        │   │   ├── B-Ainge WF.cpp
        │   │   ├── ...
        │   │   └── problems
        │   │       ├── A.md
        │   │       ├── B.md
        │   │       └── ...
        │   └── final
        │       ├── A-Ainge WF.cpp
        │       ├── B-Ainge WF.cpp
        │       └── ...

2. Each solution file is recommended to have the following header.

        /**
         * Contest : <Name of Contest>
         * Team    : <Your Team>
         * Author  : <Author>
         * Problem : <Problem Code> - <Problem Name>
         */

For example, solution to problem A solved by team *juara* in ITBPC 2000 round *final* should be saved as:

    ITBPC2000/final/A-juara.cpp
