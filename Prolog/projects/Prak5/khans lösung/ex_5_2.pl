
count_leafs(Term,N) :-
    functor(Term,_,Arity),
    %NewN is 0, 
    proc_args(Term,Arity,N).
    %N is NewN.

proc_args(Term,0,0).

proc_args(Term,ValuePos,N) :-
    %functor(Term,_,ValuePos),
    arg(ValuePos,Term,Value),
    ( not(atom(Value))
    -> count_leafs(Value,N3);
    N3 is 1), % 1 nur addieren wenn atom gezählt wird
    
    
    NValuePos is ValuePos - 1,
    proc_args(Term,NValuePos,N2),
    %N2 = N + N1,
    N is  N2 + N3.


