digits(0).
digits(1).
digits(2).
digits(3).
digits(4).
digits(5).
digits(6).
digits(7).
digits(8).
digits(9).

f(A,B,C,D,E,F,G,H):-
    digits(A),
    digits(B),
    digits(C),
    digits(D),
    digits(E),
    digits(F),
    digits(G),
    digits(H),
    \= member(A,[B,C,D,E,F,G,H]),
    \= member(B,[C,D,E,F,G,H]),
    \= member(C,[D,E,F,G,H]),
    \= member(D,[E,F,G,H]),
    \= member(E,[F,G,H]),
    \= member(F,[G,H]),
    \= member(G,[H]),
    Z1 is 10*A+B+C, 
    Z1 is 10*D+E,
    Z2 is 10*A+B*2,
    Z2 is 100*D+10*F+B,
    Z3 is 10*A+B-C,
    Z3 is 10*A+D,
    Z4 is 100*D+10*F+B/G,       
    Z4 is 10*H+D,
    Z5 is C+C,
    Z5 is G,
    Z6 is 10*D+E+10*A+D,
    Z6 is 10*H+D.
