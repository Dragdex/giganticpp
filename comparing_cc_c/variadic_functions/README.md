This compares C++ vs C performance for variadic funcions

First compile de code with:

    make clean
    make all

This will create executables with input based on compilation time

Then execute the code with

    make
    make ram

Notice the C++ is much faster
    
    C++ 21200000000 in  0 ms    
    C 21200000000 in  3193 ms

Actually C++ cheats and calculates the final result at compilation time.

If you look at generated assembly, it assigns the value without looping.

    movabsq $21200000000, %rdx      #,

Notice C++ and C uses almost much same memory

    C++ RAM
        Maximum resident set size (kbytes): 1484
    C RAM
        Maximum resident set size (kbytes): 1472

############################################

Now let's try to make C++ life harder by using a value from user input

First compile de code with:
    
    make clean
    make DEFS=-DUSE _INPUT all

Now the program asks the user to enter a value that will be used in the sum

    make

    Enter an integer 0
    C++ 21000000000 in  0 ms
    Enter an integer 0
    C 21000000000 in  3148 ms

C++ cheats again and does not loop in external 'for', it just multiplies the result by 100000000

So, the C++ compiler is smarter.

The problem with C compiler is because it doesn't know what is coming in VA_ARGS. And don't know if is safe to use the same strategy as C++ and just multiple the result coming from add()

C++ still did magic setting the varible as volatile.

    make clean
    make DEFS="-DUSE_VOLATILE -DUSE_INPUT" all

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/volatile.png)

############################################

Again, let's make C++ life even harder.

To not let C++ calculate the value, or multiply it after fisrt calculation, now it gives almost 900 rand() calls as parameter to add().

C++ has a default limit for template depth of 900 but you can change it with "-ftemplate-depth="

First compile de code with:

    make clean
    make DEFS="-DUSE_RAND" all

(the compilation takes a while)

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/rand_complilation.png)

And now we execute.

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/rand_run.png)

Now C++ is just a bit faster. as we see the output from "make"

Both use RAM of 1.4 MB and (output from "make ram"), and have the same executable size ("ls -la compare_c*")

C++ has a bit smaller object size ("ls -la *.o")

    ls -la compare_c*
    ls -la test*.o
    ls -la main*.o

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/rand_objsize.png)

As you can see from C++ assembly, it make inline adds()

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/cpp_add_inline_s.png)

 while C pushs it into stack and call add().

![alt text](https://github.com/Dragdex/giganticpp/blob/master/comparing_cc_c/variadic_functions/pics/c_rand_s_call_add.png)

It gives C++ better performance.

############################################

Conclusion:

C++ variadic funcion templates vs C variadics function

- Both use same RAM
- C++ generates a bit smaller object size
- C++ is epically faster using constants (known at compilation time)
- C++ was epically faster using non-volatile variables
- C++ was still epically faster using volatile variables
- C++ is faster even if the value changes in each 'for' loop

C++ Wins !!!

############################################

Todo:

Use different compilers (GCC, VC++, clang)

Use different architecutures (i386, x64, arm)

Add some statistics (repeat the test and collect avg, stddev, ...)
