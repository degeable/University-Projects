is_ground_term(Term) :-
    functor(Term,_,Arity),
    %NewN is 0, 
    proc_args(Term,Arity).
    %N is NewN.

proc_args(Term,0).

proc_args(Term,ValuePos) :-
    %functor(Term,_,ValuePos),
    arg(ValuePos,Term,Value),
    nonvar(Value),
    ( not(atomic(Value))
    -> is_ground_term(Value);
    true),
    
    NValuePos is ValuePos - 1,
    proc_args(Term,NValuePos).
    