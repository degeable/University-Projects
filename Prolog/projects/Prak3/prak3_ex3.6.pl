increase( [] , [] ).
increase( [X|Xs] , [Y|Ys] ) :-
    (number(X) -> Y is X+1 ; Y=X ), % if -> then ; else
    increase(Xs,Ys).

delete(List1, X, List2) :- 
    List1 = [], 
    List2 = [],
    !.

delete(List1, X, List2) :- 
    [Elem | Tail1] = List1,
    [Elem2 | Tail2] = List2,
    (Elem = X ->
        delete(Tail1, X, List2);
    Elem = Elem2 ->
        delete(Tail1, X, Tail2)
    ).

swap([],[]).
swap([X],[X]).
swap(List1,List2):-
    [X, Y| Tail1] = List1,
    [Y, X| Tail2] = List2,
    swap(Tail1, Tail2).

list_length(List,Length):- length(List,Length).

replace_element([],X,Y,[]):-
    !.

replace_element(List1, X, Y, List2) :-
    [N | Tail1] = List1,
    (N = X ->
      [Y | Tail2] = List2;
    [N | Tail2] = List2
    ),
    replace_element(Tail1, X , Y, Tail2).

listsum([],0).

listsum([N|Liste],Sum):-
    listsum(Liste,PartSum),
    Sum is PartSum + N.

last_n(1,[1]).

last_n(N,List):-
    List=[N | Tail],
    Prev is N-1,
    last_n(Prev,Tail).
    
first_n(N,List):-
    last_n(N,PartList),
    reverse(PartList,List).
