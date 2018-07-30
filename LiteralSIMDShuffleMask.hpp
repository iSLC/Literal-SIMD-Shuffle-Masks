// Flexible structure that can be specialized to assign a character to a certain element in a vector.
template < char C > struct CharToShuffleIndex;

// Specialization for characters that point to the first element in the vector.
template < > struct CharToShuffleIndex< '0' > { static constexpr char value = 0; };
template < > struct CharToShuffleIndex< 'X' > { static constexpr char value = 0; };
template < > struct CharToShuffleIndex< 'x' > { static constexpr char value = 0; };
// Specialization for characters that point to the second element in the vector.
template < > struct CharToShuffleIndex< '1' > { static constexpr char value = 1; };
template < > struct CharToShuffleIndex< 'Y' > { static constexpr char value = 1; };
template < > struct CharToShuffleIndex< 'y' > { static constexpr char value = 1; };
// Specialization for characters that point to the third element in the vector.
template < > struct CharToShuffleIndex< '2' > { static constexpr char value = 2; };
template < > struct CharToShuffleIndex< 'Z' > { static constexpr char value = 2; };
template < > struct CharToShuffleIndex< 'z' > { static constexpr char value = 2; };
// Specialization for characters that point to the fourth element in the vector.
template < > struct CharToShuffleIndex< '3' > { static constexpr char value = 3; };
template < > struct CharToShuffleIndex< 'W' > { static constexpr char value = 3; };
template < > struct CharToShuffleIndex< 'w' > { static constexpr char value = 3; };

// Terminator of the character to shuffle mask recursion.
template < char C > constexpr unsigned PackShuffleCharMask(unsigned m)
{
    return m | CharToShuffleIndex< C >::value;
}
// Packs a series of characters into a SIMD shuffle mask.
template < char C, char Cn, char... Cs > constexpr unsigned PackShuffleCharMask(unsigned m)
{
    return PackShuffleCharMask< Cn, Cs... >((m | CharToShuffleIndex< C >::value) << 2);
}

// Takes a series of numbers and treats them as a series of characters to generate a shuffle mask.
template < char... Cs > constexpr int operator"" _Shuffle()
{
    return static_cast< int >(PackShuffleCharMask< Cs... >(0));
}
// Takes a literal string and treats it as a series of characters to generate a shuffle mask.
template < typename CharT, CharT... Cs > constexpr int operator"" _Shuffle()
{
    return static_cast< int >(PackShuffleCharMask< Cs... >(0));
}
