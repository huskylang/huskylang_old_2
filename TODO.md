# TODO:

* implement garbage collector by externing GarbageCollector object and completing objects all over the system

## Main

* input and output handlers should inherit std::istream and std::ostream

## Std

* implement arithmetic functions in module '-'

## Types

* implement integer data type

## Tests

* problem with outhandler_tests. The file is not closed so you can't write to it (the file is busy) [I have to implement a factory first or just stop using stream pointers] see http://stackoverflow.com/questions/10586127/ofstream-not-writing-to-file-c
