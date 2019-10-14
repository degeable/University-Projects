?- g(X,Y) = Y.
Y = g(X, Y).

?-  X = f(X), Y = f(Y), X = Y.
X = Y, Y = f(Y).

\=/2........


?- a  \=  a 
|    .
false.

?- 'a'  \=  a.
false.

?- A  \=  a.
false.

?- f(a)  \=  a.
true.

?- f(a)  \=  A.
false.

?- f(A)  \=  f(a).
false.

?- f(A)  =  f(a).
A = a.

?- 
|    g(a,B,c)  \=  g(A,b,C) .
false.

?- g(a,b,c)  \=  g(A,C).
true.

?- f(X)

..........

trace. and notrace.
