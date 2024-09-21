# Harness
Permissive-license test harness for C binaries.


## Usage

Setup your C project by adding a `test` directory,
or substitute with a location of your choice.
```sh
mkdir ./test
mkdir ./test/bin
```

Put the `harness.c` and `harness.h` files from this repostiory
into your test directory.


Create test files within `./test/`, following the pattern `test_*.c`.
Update your `harness.c` file to import your unit test functions from the test file, and add the function name to the array within the function `RunTests`.

Your unit test functions should always return `0` if they succeed.
Using the `ASSERT` macro defined in `harness.h` will return 1 when the assertion is false.
This is used to print how many assertions failed after running all your tests.

```c
// ./tests/test_myadd.c
#include "harness.h"

int Test_MyAdd(void)
{
    int result = my_add(2, 2);
    ASSERT(result == 4, "Assertion failed, expected my_add(2, 2) to equal 4")
    return 0;
}

```
```c
// harness.c

int RunTests(void)
{
    const TestFunction tests[] = {
        // Add test functions here
        Test_MyAdd
    };

    // elided...
}
```


Update your Makefile to include a target named `test`.
```make
test:
    gcc ./*.c ./test/test_*.c -o ./test/bin/test
```

Finally, make and run your test binary.
```sh
make test
```

