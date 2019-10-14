accRev([H|T],A,R):-
    (nonvar(H)
    -> functor(H,_,Arity);
    Arity is 0),
    (Arity > 0
        -> reverse_left(H,HMod);
    HMod = H),
    accRev(T,[HMod|A],R).

accRev([],A,A).
rev(L,R):- accRev(L,[],R).

reverse_left(Term1,Term2) :-
Term1 =..[Func|Args],
rev(Args,RevArgs),
Term2 =..[Func|RevArgs].

