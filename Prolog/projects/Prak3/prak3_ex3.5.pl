last([E],E):-
    atomic(E).

last([],[]).

last([_|T],E):-
    last(T,E).

second(X,[Y,X|List]).
