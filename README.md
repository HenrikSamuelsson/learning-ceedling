# Learning Ceedling

Experiments with using Ceedling for unit testing.

## Resources

First tests are based on material from a pdf called "How to Use Ceedling for Embedded Test-Driven Development" written by Matt Chernosky.

This pdf can be downloaded from [electronvector.com](http://www.electronvector.com/how-to-use-ceedling-for-embedded-test-driven-development), assuming you are alright with sharing your contact information.

Resource to go through in a near future is [ThrowTheSwitch/Ceedling](https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md)

## Installation Notes

Ruby is required to run Ceedling. I currently use Ruby 2.7.3-1-x64 on my Windows 10 PC. Installer can be found at [rubyinstaller.org](https://rubyinstaller.org/downloads/)

Ceedling needs a compiler to build the C-code to be tested. I opeted to use [mingw-w64](http://mingw-w64.org/doku.php) to have GCC on my Windows machine, otherwise Cygwin should be another viable option. The path GCC need to be added to the windows enviorment variables for Ceedling to be able to find GCC.
