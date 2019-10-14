pElem(X):-
        write("   "),
        writeln(X). 


printSublist([]).

printSublist([X|T]):-
        pElem(X),
        printSublist(T).


subprint([]).


subprint([X|List]):-
        is_list(X),
        writeln('['),
        printSublist(X),
        writeln(']').


subprint([X|List]):-
        pElem(X),
        subprint(List).


pprint(List):-
    writeln('['),
    subprint(List),
    writeln(']').




