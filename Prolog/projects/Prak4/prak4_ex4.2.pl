
color(red).
color(yellow).
color(green).

rectangles([A,B,C,D]):-
    color(A),
    color(B),
    A\=B,
    color(C),
    B\=C,
    color(D),
    B\=D,
    A\=D,
    C\=D,
    !.
  

