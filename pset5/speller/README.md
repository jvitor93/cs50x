# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

    Longest word in the english dictionary

## According to its man page, what does `getrusage` do?

    get measures for resources usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

    16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

    because getrusage is a pointer to a struct, to access it, we need the adress reference

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

    The loop uses the function fgec to read character by character from the text file
    checks if the read char is alphabetical or apostrophe and append it to a word[index] char array
    when the char is not as desired, it terminates the word and prepares to begin a new one until it reaches the EOF.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

    fgetc will read a word in the text file char by char, allowing to identify
    possible end of word, while fscanf reads from a specified format and size wich can generate errors
    when reading non alphabetical char for this program

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

    so that the value passed to the function cannot be changed 
