father(anton,john).
father(paul,mary).
father(john,peter).
father(john,elisabeth).
father(peter,agneta).
mother(mary,peter).
mother(mary,elisabeth).
mother(elisabeth,agneta).
mother(elisabeth,sarah).
parent(X,Y):-father(X,Y).
parent(X,Y):-mother(X,Y).
ancestor(X,Y):- parent(X,Y).
ancestor(X,Y):- parent(X,Z),ancestor(Z,Y).
