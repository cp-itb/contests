# contests

Solutions to various CP contests (especially Indonesian local contests), written by teams from Institut Teknologi Bandung.

## Contributing guide

All ITB students are very welcomed to contribute to this repository. To make everything neat and structured well, it is recommended to follow these guide before adding your solutions.

1. Project structure. Each contest should have their own folder named `<ContestName><Year>`. If the contest has several phases (qualification, final, etc), each of them should have their own subfolders.
2. If the problem statement is available, put it in file named `README.md` in each contest folders (or subfolders).
3. File Naming. It is recommended to name each file by `<ProblemCode>-<TeamName>.<extension>`.
4. Each file is recommended to have the following header.

        /**
         * Contest : <Name of Contest>
         * Team    : <Your Team>
         * Author  : <Author>
         * Problem : <Problem Code> - <Problem Name>
         */

For example, solution to problem A solved by team *juara* in ITBPC 2000 final should be saved as:

    ITBPC2000/final/A-juara.cpp
