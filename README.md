# Literal-SIMD-Shuffle-Masks
C++11 User defined literals for intuitive SIMD shuffle masks.

# Example

```C++
    // Basic test
    printf("0x%X\n", _MM_SHUFFLE(0,0,0,0));
    printf("0x%X\n", 0000_Shuffle);
    printf("0x%X\n", "XXXX"_Shuffle);

    printf("0x%X\n", _MM_SHUFFLE(1,1,1,1));
    printf("0x%X\n", 1111_Shuffle);
    printf("0x%X\n", "YYYY"_Shuffle);

    printf("0x%X\n", _MM_SHUFFLE(2,2,2,2));
    printf("0x%X\n", 2222_Shuffle);
    printf("0x%X\n", "ZZZZ"_Shuffle);

    printf("0x%X\n", _MM_SHUFFLE(3,3,3,3));
    printf("0x%X\n", 3333_Shuffle);
    printf("0x%X\n", "WWWW"_Shuffle);

    // String literals can be combined in any way
    printf("0x%X\n", _MM_SHUFFLE(1,1,1,1));
    printf("0x%X\n", "Yy1y"_Shuffle);
```

Output:
```
0x0
0x0
0x0
0x55
0x55
0x55
0xAA
0xAA
0xAA
0xFF
0xFF
0xFF
0x55
0x55
```
