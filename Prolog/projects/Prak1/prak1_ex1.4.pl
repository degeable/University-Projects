right_of(monika,manuel).
right_of(manuel,melanie).
right_of(melanie,markus).
right_of(markus,maren).
right_of(maren,martin).
right_of(martin,monika).

left_of(X,Y):- right_of(Y,X).

neighbour_of(X,Y):- right_of(X,Y), left_of(X,Y).

opposite(X,Y):-right_of(X,Y1),right_of(Y1,Y2),right_of(Y2,Y).
