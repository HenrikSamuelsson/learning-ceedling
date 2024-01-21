# Notes - A Field Manual For Ceedling

Notes on the pdf:

A Field Manual For Ceedling, How to Unit Test Embedded Software (in C), Revision 3  
Matt Chernosky  
ElectronVector, 2017  

## Introduction

## This is Ceedling

*Ceedling* is a unit test tool for C code. It has two main sub components:

1. *Unity* - a unit test framework
2. *CMock* - a mocking framework

Unity and CMock can be run without Ceedling, but Ceedling will automate some steps making the testing smoother.

## The Approach of This Book

The book discusses unit testing with Ceedling as well as how to *mock* modules. Mocking enables running the tests on the *host* computer as opposed to running them on the *target* board. This approach which will generally speed up the test phase. For this to work well the software need to be designed to make it easy to mock the hardware. A typical design will be made modular by division into layers, where one layer will be *hardware abstraction layer* (HAL).

## Your IDE

Fastest way to get started with Ceedling is to just run Ceedling from the command line.

A basic IDE integration can be to configure a shortcut key to run `ceedling test:all`, to enable running from within the IDE.

## Versions

The examples in the book were tested with Ceedling 0.28.1 and Ruby 2.3.1, can try to back to these versions if having some issue with running examples.

## Definitions

| Term | Definition |
| --- | --- |
| binary | Software application that have been built, can be executed either on the host or the target. |
| Ceedling | A build and test system for C language applications. |
| CMock | Mocking framework used by Ceedling, used to create mocks for for functions to be called during tests. |
| collaborator | A software module required to do something, i.e. a dependency. |
| cross compilation | Compilation on one system with the intention of running the binary on another system. |
| dependency | When a software unit does not do all the work and instead relies on another software unit. |
| dependency chain | Multi level dependency, software unit 1 depends on unit 2 which in turn depends on unit 3 and so on. |
| function prototype | The declaration of a functions signature, provides interface information only. |
| "functional" test | Test category that do not require mocking any functions. |
| function under test | The function that is called in a test to be verified to work as expected. |
| GCC | GNU Compile Collection - A set of free compilers provided by the GNU project. |
| HAL | Hardware Abstraction Layer |
| host | Personal computer of the developer, primary used to develop code, can also be used to run tests without involving the target. |
| integration test | Test category typically involving multiple modules working together to solve the task to be tested. |
| mock | A "stand-in" for an actual real module, can be used to simulate behaviour of the system for testing purposes. |
| module | In the context of the book a module is defined as a C source file (.c) accompanied by a corresponding header file (.h). |
| module under test | The module that a particular unit test is testing. |
| native compilation | Compiling for the same system that the code is developed on, i.e. not a cross compilation. |
| stub | An empty function declaration used in place of a real one. |
| target | The actual embedded system, this is where the cross compiled application is loaded and running. |
| test assertion | A statement in a unit test that validates som expected outcome. |
| TDD | Test Driven Development - A development technique where unit tests and project source code are developed in tandem. |
| unit | The smallest independently testable component of a software application. |
| unit test | A single function that tests some behaviour of a software module. |
| Unity | Unit test framework used by Ceedling. |
