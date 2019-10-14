printList(List):-
    writeln("["),
    printElement(List,1).

printElement([], Depth):-
    NewDepth is Depth -1,
    intend(NewDepth),
    writeln("]").

printElement([X | Sublist], Depth):-
    is_list(X),
    intend(Depth),
    writeln("["),
    NewDepth is Depth + 1,
    printElement(X, NewDepth),
    printElement(Sublist,Depth).
    
printElement([X | Sublist], Depth):-
    intend(Depth),
    writeln(X),
    printElement(Sublist, Depth).

printElement([X | Sublist], Depth):-
    intend(Depth),
    writeln(X),
    printElement(Sublist, Depth).

intend(0).
intend(Depth):-
    write("   "),
    Rest is Depth -1 ,
    intend(Rest).
