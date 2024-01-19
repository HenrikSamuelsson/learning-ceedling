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

The book discusses unit testing with Ceedling as well as how to *mock* modules. Mocking enables running the tests on the *host* computer as opposed to running them on the *target* board. This approach which will generally speed up the test phase. For this to work well the software need to be designed to make it easy to mock the hardware. A typical design will be made modular by introducing layer, where one layer will be *hardware abstraction layer* (HAL).
