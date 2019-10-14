stands_on(5,1).

stands_on(8,5).

stands_on(6,7).

stands_on(9,3).

stands_on(4,9).

stands_on(2,4).

stands_on(1,t).

stands_on(7,t).

stands_on(3,t).

above(X,Y):-
    stands_on(Y,X).
