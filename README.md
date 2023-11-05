This small C program demonstrates the danger of improper use of the
C preprocessor.

A macro that's intended to be used in an expression context generally
needs to be aggressively parenthesized.  You should have parentheses
around each reference to a macro parameter, and around the entire definition.

The reason is that macro expansion works on sequences of tokens.
The C preprocessor doesn't deal with high-level C syntax.

In the example, unless `ORIGINAL` is defined, the macro `SIX` expands to the token sequence `3 + 3`,
and the macro `NINE` expands to `15 - 6`.  If each of these expressions
were evaluated on its own, the results would be 6 and 9, respectively,
But when they're combined in the expression `SIX * NINE`, the expansion is:

    3+3*15-6

which is equivalent to:

    3+(3*15)-6

or 42.

The program is also a reference to [a joke](http://en.wikipedia.org/wiki/Phrases_from_The_Hitchhiker%27s_Guide_to_the_Galaxy#Answer_to_the_Ultimate_Question_of_Life.2C_the_Universe.2C_and_Everything_.2842.29) in The Hitchhiker's Guide to the Galaxy, by Douglas Adams.

-- Keith Thompson <Keith.S.Thompson@gmail.com> Tue 2011-11-01

Based on a program I posted to comp.lang.c on Mon 2003-09-29
with this comment:

> (Not original; I don't remember where I got it.)
