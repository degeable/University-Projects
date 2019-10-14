% 7.2

a(X, Y) :- b(X, Y).
a(1, 1).
b(X, X) :- c(X).
b(X, Y) :- c(X), !, c(Y).
b(X, Y) :- c(X), c(Y).
c(2).
c(3).

%7.3

fib(1,1).
fib(2,1).
fib(N,F):-
	N2 is N-2,
	fib(N2,F2),
	N1 is N-1,
	fib(N1,F1),
	F is F2 + F1.
	
%7.4

not_member(X,[]).

not_member(X,[Head|Tail]):-
    (X=:=Head
    -> !,fail
    ;not_member(X,Tail)
    ).

%7.5

%ausgelassen...

%7.6

%ausgelassen...

%7.7

%ausgelassen...

