diff(x,1).

diff(C, 0):-
    atomic(C),C \= x.

diff(F + G, DF + DG) :-
    diff(F, DF),
    diff(G, DG).

diff(F - G, DF - DG) :-
    diff(F, DF),
    diff(G, DG).

diff(F * G, DF * G + F * DG) :-
    diff(F, DF),
    diff(G, DG).

diff(F / G, (DF * G - F * DG) / (G * G)) :-
    diff(F, DF),
    diff(G, DG).

diff(sin(F),cos(F) * DF):-diff(F, DF).
    
diff(cos(F),-sin(F) * DF):-diff(F, DF).
    
diff(-sin(F), -cos(F) * DF):-diff(F, DF).
    
diff(-cos(F), sin(F) * DF):-diff(F, DF).
    
diff(F ^ N, N * F ^ NX) :-NX is N - 1.

