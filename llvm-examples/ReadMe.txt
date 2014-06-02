Introduction
============

This Directory contains various examples for working with the LLVM tools.

All interesting files are from the LLVM project -
See http://llvm.org and in particular http://www.llvm.org/docs/
for more information.

This collection was prepared by Prof. R. C. Moore, fbi.h-da.de
in May 2013 for the Compiler-Bau course. No warranty implied or expressed.
See LICENSE.TXT for the original license.

All of the example files (fibonacci.cpp, ModuleMaker.cpp and toy3-toy7.cpp):

 - are available in the LLVM source tree, for example by running
    svn co http://llvm.org/svn/llvm-project/llvm/trunk  (latest version, or)
    svn co http://llvm.org/svn/llvm-project/llvm/tags/RELEASE_32/final/examples

 - have been modified to work under LLVM 3.2 or LLVM 3.3. These Modifications
   have only to do with the header files, and should be obvious and self-
   explanatory.


Manifest
========

You should have received the following files:
    fibonacci.cpp       - This is a compiler without a front-end, so to speak,
                        but with an interpreter built in - see ModuleMaker for
                        an even simpler example.

    LICENSE.TXT         The LLVM Release Open Source License
                        (taken verbatim from the University of Illinois/NCSA,
                        http://llvm.org/svn/llvm-project/llvm/trunk/LICENSE.TXT)

    Makefile            - A Makefile, not supplied by LLVM but written instead
                        by R. Moore - to make this collection work without the
                        rest of the LLVM source tree.  You will (of course)
                        need the LLVM tool set installed (clang, clang++ &
                        llvm-config at the very least).

    ModuleMaker.cpp     - Another example provided in the LLVM source tree.
                        This file produces binary LLVM bit code for a program
                        which does nothing but return a status of 5. LLVM
                        bit code can bit run using the LLVM "lli" tool.
                        Thus, you should be able to do the following:
                            make ModuleMaker
                            ./ModuleMaker >status5.bc
                            lli status5.bc
                            echo $? # should print "5"
                        "Hello World" doesn't get much simpler than this!
                        (Running"make testModuleMaker" works too, by the way).

    ReadMe.txt          This file.

    tests               - A directory containing files in the Kaleidoscope
                        language, taken from the LLVM Tutorial, see
                        http://www.llvm.org/docs/tutorial/index.html
                        Some, but not all, of these are used by "make tests".

    toy2.cpp            - The source code from the Tutorial, Chapter 2
    toy3.cpp            - The source code from the Tutorial, Chapter 3
    toy4.cpp            - The source code from the Tutorial, Chapter 4
    toy5.cpp            - The source code from the Tutorial, Chapter 5
    toy6.cpp            - The source code from the Tutorial, Chapter 6
    toy7.cpp            - The source code from the Tutorial, Chapter 7
                        All of the above Chapters are available at
                        http://www.llvm.org/docs/tutorial/index.html

Building
=========

(1) Install clang and the llvm tool kit.  You can either compile from source
    (see http://www.llvm.org/docs/GettingStarted.html - or perhaps better,
    http://clang.llvm.org/get_started.html - this will give you LLVM 3.3)
    or install binaries that you find elsewhere (you SHOULD get LLVM 3.2
    - No guarantees are made for older versions!).

(2) Run "make" (or perhaps "make clean" and then "make").

(3) If you wish, run "make tests" to run (almost) all the programs delivered
    in this colleciton.  The output from "make tests" is very long.
    Each program can also be tested individually, for example with
    "make testFibonacci" or "make testModuleMaker" or "make test5" (read the
    Makefile to see all alternatives).

Further Reading
===============

These files are only provided to illustrate how LLVM can be used.  The code from
the tutorial should be read together with the tutorial.

More information is availabl:

Overview of the LLVM Documentation:
    http://www.llvm.org/docs/

The LLVM ("Kaledeiscope") Tutorial:
    http://www.llvm.org/docs/tutorial/index.html

Guide for Programmers:
    http://www.llvm.org/docs/ProgrammersManual.html

Guide to the LLVM IR (LLVM Intermediate Representation):
    http://www.llvm.org/docs/LangRef.html#high-level-structure







