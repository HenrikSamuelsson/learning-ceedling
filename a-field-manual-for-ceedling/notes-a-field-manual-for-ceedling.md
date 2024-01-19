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

The book discusses unit testing with Ceedling as well as how to use mock modules. This enables running the tests on the *host* computer as opposed to running them on the *target* board which will generally speed up the test phase. For this approach to work well the software need to be designed so that it is easy to mock the hardware, typically this means having a modular design with a *hardware abstraction layer* (HAL).
