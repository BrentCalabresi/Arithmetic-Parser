Brent Calabresi - bcalabre@u.rochester.edu
Collaborator: Clay Emmel - cemmel@u.rochester.edu

Program will prompt for input to test parsers

To run, type "make" while in the project directory, then "./expr"



# Arithmetic-Parser
Creates a parse tree based on user input, then evaluates it, returning an answer

Grammars derived from https://www.cs.rochester.edu/~nelson/courses/csc_173/grammars/parsing.html

-----

Recursive Decent Grammar:

    <E>→<T><A>

    <A>→+<T><A>|-<T><A>|e

    <T>→<F><B>

    <B>→*<F><B>|/<F><B>|e

    <F>→<E>|<N>

    <N>→<D><C>

    <C>→<N>|e

    <D>→0|1|2|3|4|5|6|7|8|9

-----

Table Based Grammar:

    <E>→<T><A>

    <A>→+<T><A>|-<T><A>|e

    <T>→<F><B>

    <B>→*<F><B>|/<F><B>|e

    <F>→<E>|<Number>
