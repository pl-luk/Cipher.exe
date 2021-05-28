# Cipher.exe
A fun little crypto black box to solve

## What is it?
This thing is based on a Caesar chiffre but with a twist. The alphabet shifts dependent on time so you'll end up with a different output every minute. The basic challange is to give somebody a previously encoded string and let him figure out what the input was.

## What its going to be
Right now I'm trying to make it a little bit more secure by adding some obfuscation features like they are using in malware. (As an excersice only ofc :))

## How to compile?
As this is a Windows project you can only really compile this on Windows. Just fire up Visual Studio and add it to a project, hit build and it should generate the .exe.
The second method is to open the developer command prompt and type ```cl /EHsc Cipher.cpp```
