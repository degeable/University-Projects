combine1([],[],X):-
    reverse(X,List3).
combine1([X|List1],[Y|List2],[Y,X|List3]):-
        combine1(List1,List2,List3).

combine2([],[],X):-
    reverse(X,List3).
combine2([X|List1],[Y|List2],[[Y,X]|List3]):-
        combine2(List1,List2,List3).

combine3([],[],X):-
    reverse(X,List3).
combine3([X|List1],[Y|List2],[j(Y,X)|List3]):-
        combine3(List1,List2,List3).


