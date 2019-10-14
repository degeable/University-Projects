term_member(Term1,Term1).
term_member(Term1,Term2) :-
    Term2 =.. [_|AllArgs],
    member(Arg,AllArgs),
    term_member(Term1,Arg).                      
