# Notes - A Field Manual For Ceedling

Notes on the pdf:

A Field Manual For Ceedling, How to Unit Test Embedded Software (in C), Revision 3  
Matt Chernosky  
ElectronVector, 2017  

## Introduction

### This is Ceedling

*Ceedling* is a unit test tool for C code. It has two main sub components:

1. *Unity* - a unit test framework
2. *CMock* - a mocking framework

Unity and CMock can be run without Ceedling, but Ceedling will automate some steps making the testing smoother.

### The Approach of This Book

The book discusses unit testing with Ceedling as well as how to *mock* modules. Mocking enables running the tests on the *host* computer as opposed to running them on the *target* board. This approach which will generally speed up the test phase. For this to work well the software need to be designed to make it easy to mock the hardware. A typical design will be made modular by division into layers, where one layer will be *hardware abstraction layer* (HAL).

### Your IDE

Fastest way to get started with Ceedling is to just run Ceedling from the command line.

A basic IDE integration can be to configure a shortcut key to run `ceedling test:all`, to enable running from within the IDE.

### Versions

The examples in the book were tested with Ceedling 0.28.1 and Ruby 2.3.1, can try to back to these versions if having some issue with running examples.

### Definitions
  
| Term                | Definition |
| ---                 | ---        |
| binary              | Software application that have been built, can be executed either on the host or the target. |
| Ceedling            | A build and test system for C language applications. |
| CMock               | Mocking framework used by Ceedling, used to create mocks for for functions to be called during tests. |
| collaborator        | A software module required to do something, i.e. a dependency. |
| cross compilation   | Compilation on one system with the intention of running the binary on another system. |
| dependency          | When a software unit does not do all the work and instead relies on another software unit. |
| dependency chain    | Multi level dependency, software unit 1 depends on unit 2 which in turn depends on unit 3 and so on. |
| function prototype  | The declaration of a functions signature, provides interface information only. |
| "functional" test   | Test category that do not require mocking any functions. |
| function under test | The function that is called in a test to be verified to work as expected. |
| GCC                 | GNU Compile Collection - A set of free compilers provided by the GNU project. |
| HAL                 | Hardware Abstraction Layer - A set of functions that forms an interface to lower level hardware resources |
| host                | Personal computer of the developer, used to develop code, can also be used to run tests without involving the target. |
| integration test    | Test category typically involving multiple modules working together to solve the task to be tested. |
| mock                | A "stand-in" for an actual real module, can be used to simulate behaviour of the system for testing purposes. |
| module              | In the context of the book a module is defined as a C source file (.c) accompanied by a corresponding header file (.h). |
| module under test   | The module that a particular unit test is testing. |
| native compilation  | Compiling for the same system that the code is developed on, i.e. not a cross compilation. |
| stub                | An empty function declaration used in place of a real one. |
| target              | The actual embedded system, this is where the cross compiled application will run in the end. |
| test assertion      | A statement in a unit test that validates som expected outcome. |
| TDD                 | Test Driven Development - A development technique where unit tests and project source code are developed in tandem. |
| unit                | The smallest independently testable component of a software application. |
| unit test           | A single function that tests some behaviour of a software module. |
| Unity               | Unit test framework used by Ceedling. |
| VSC                 | Visual Studio Code - An IDE that can be used for embedded development |

## Installing Ceedling

This chapter explains how to setup Ceedling for an embedded project.

Ceedling setup involves:

1. Installing tools that Ceedling requires
2. Installing Ceedling itself on the development machine
3. Some reorganization of the code base to enable testability
4. Introducing Ceedling into your project

A actual embedded project is required to gets hands on with the material in this chapter, this can be an example project for a development board.

### Install the Tools

Ceedling itself have some tools requirements, it is written and runs under Ruby, and it uses GCC to compile the tests. Hence both Ruby and a native GCC version needs to be installed on the development machine.

Ceedling also need to be setup to be aware of the path to where it can find bot Ruby and GCC.

#### Linux

Installing on Linux should be straight forward.

Install Ruby with `> sudo apt-get install ruby`, or similar.

GCC is usually installed by default, if not it can be installed via some package manager, search online if unsure how to do this.

#### Windows

Setup on Ceedling on Windows is a bit more complicated than on Linux, but still doable.

First Ruby needs to be installed.

Ruby can be installed from [rubyinstaller.org](https://rubyinstaller.org/downloads/). The book uses version 2.3.1 but this is outdated.

I personally first chose to go with a Ruby version called `Ruby+Devkit 3.2.2-1 (x64)` but this would not work later on in combination with my Ceedling version. Second try was with `Ruby 3.0.6-1 (x64)`.

Before installing Ruby I also uninstalled a previous version of Ruby form my machine attempting to keep my environment clean.

The Ruby download is a windows installer:

1. Accepted the security warning issued by windows
2. Choose to `Install for me only (recommended)`.
3. Accepted the license agreement
4. Installed in `C:\Ruby30-x64`  
  `Add Ruby executables to your PATH`  
  `Associate .rb and .rbw files with the Ruby installation`  
5. Choose to install Ruby documentation
6. Choose to run `ridk install` on the last installation screen to setup the MSYS2 development toolchain
7. A command window popped up, accepted the by pressing enter  
  Multiple warnings and errors during install got a success message in the end
  Pressed `Enter` again this closed down the pop cmd window
8. Ran the command `ridk enable` in a command window, seemed to update my PATH
9. As a bonus step I now restarted my PC, maybe not required but better safe than sorry

Checked that the installation was successful in the VSC Terminal:

```txt
> ruby --version
ruby 3.0.6p216 (2023-03-30 revision 23a532679b) [x64-mingw32]
```

After having installed Ruby it is time to install GCC.

GCC is our native C compiler that Ceedling will use. The approach used here to have GCC on Windows is to get it via *MinGW*.

The link to get MinGW provided in the book is in my opinion outdated. If you want GCC get it via [MSYS2](https://www.msys2.org/).

I personally already have MSYS2 on my machine so skipped the installation.

Did check my GCC version in the VSC Terminal:

```txt
> gcc --version
gcc.exe (Rev6, Built by MSYS2 project) 11.2.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO 
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Install Ceedling

Ceedling can be installed with the Ruby package manager, `gem`:

```txt
> gem install ceedling
Fetching ceedling-0.31.1.gem
Fetching thor-0.20.3.gem
Fetching deep_merge-1.2.2.gem
Fetching constructor-2.0.0.gem
Successfully installed thor-0.20.3
Successfully installed deep_merge-1.2.2
Successfully installed constructor-2.0.0
Successfully installed ceedling-0.31.1
Parsing documentation for thor-0.20.3
Installing ri documentation for thor-0.20.3
Parsing documentation for deep_merge-1.2.2
Installing ri documentation for deep_merge-1.2.2
Parsing documentation for constructor-2.0.0
Installing ri documentation for constructor-2.0.0
Parsing documentation for ceedling-0.31.1
Installing ri documentation for ceedling-0.31.1
Done installing documentation for thor, deep_merge, constructor, ceedling after 4 seconds
4 gems installed
```

Can check the installed version of Ceedling, using `gem`:

```txt
> gem list ceedling

*** LOCAL GEMS ***

ceedling (0.31.1)
```

Can also confirm that ceedling can be run:

```txt
ceedling
Welcome to Ceedling!
Commands:
  ceedling example PROJ_NAME [DEST]  # new specified example project (in DEST...
  ceedling examples                  # list available example projects
  ceedling help [COMMAND]            # Describe available commands or one spe...
  ceedling new PROJECT_NAME          # create a new ceedling project
  ceedling upgrade PROJECT_NAME      # upgrade ceedling for a project (not re...
  ceedling version                   # return the version of the tools installed

```
