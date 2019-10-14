EXERCISE2.1

?- bread=bread.
true.

?- 'Bread' = bread
|    .
false.

?- 'bread' = bread.
true.

?- Bread = bread.
Bread = bread.

?- bread=sausage.
false.

?- food(bread)=bread.
false.

?- food(bread)=X.
X = food(bread).

?- food(X)=food(bread).
X = bread.

?- food(bread,X)=food(Y,sausage).
X = sausage,
Y = bread.

?- food(bread,X,beer)=food(Y,sausage,X).
false.

?- food(bread,X,beer)=food(Y,kahuna_burger).
false.

?- food(bread,X,beer)=food(Y,sausage,Z).
X = sausage,
Y = bread,
Z = beer.

?- food(X)=X.
X = food(X).

?- meal(food(bread),drink(beer))=meal(X,Y).
X = food(bread),
Y = drink(beer).

?- meal(food(bread),X)=meal(X,drink(beer)).
false.

EXERCISE2.2

Satisfied Queries:

none... wizard fehlt... 

toddo: searcgtree

EXCERCISE2.3:

36 sentences

A = D, D = a,
B = E, E = criminal,
C = eats ;
A = D, D = a,
B = criminal,
C = eats,
E = 'big kahuna burger' ;
A = a,
B = E, E = criminal,
C = eats,
D = every ;
A = a,
B = criminal,
C = eats,
D = every,
E = 'big kahuna burger' ;
A = D, D = a,
B = E, E = criminal,
C = likes ;
A = D, D = a,
B = criminal,
C = likes,
E = 'big kahuna burger' ;
A = a,
B = E, E = criminal,
C = likes,
D = every ;
A = a,
B = criminal,
C = likes,
D = every,
E = 'big kahuna burger' ;
A = D, D = a,
B = 'big kahuna burger',
C = eats,
E = criminal ;
A = D, D = a,
B = E, E = 'big kahuna burger',
C = eats ;
A = a,
B = 'big kahuna burger',
C = eats,
D = every,
E = criminal ;
A = a,
B = E, E = 'big kahuna burger',
C = eats,
D = every ;
A = D, D = a,
B = 'big kahuna burger',
C = likes,
E = criminal ;
A = D, D = a,
B = E, E = 'big kahuna burger',
C = likes ;
A = a,
B = 'big kahuna burger',
C = likes,
D = every,
E = criminal ;
A = a,
B = E, E = 'big kahuna burger',
C = likes,
D = every ;
A = every,
B = E, E = criminal,
C = eats,
D = a ;
A = every,
B = criminal,
C = eats,
D = a,
E = 'big kahuna burger' ;
A = D, D = every,
B = E, E = criminal,
C = eats ;
A = D, D = every,
B = criminal,
C = eats,
E = 'big kahuna burger' ;
A = every,
B = E, E = criminal,
C = likes,
D = a ;
A = every,
B = criminal,
C = likes,
D = a,
E = 'big kahuna burger' ;
A = D, D = every,
B = E, E = criminal,
C = likes ;
A = D, D = every,
B = criminal,
C = likes,
E = 'big kahuna burger' ;
A = every,
B = 'big kahuna burger',
C = eats,
D = a,
E = criminal ;
A = every,
B = E, E = 'big kahuna burger',
C = eats,
D = a ;
A = D, D = every,
B = 'big kahuna burger',
C = eats,
E = criminal ;
A = D, D = every,
B = E, E = 'big kahuna burger',
C = eats ;
A = every,
B = 'big kahuna burger',
C = likes,
D = a,
E = criminal ;
A = every,
B = E, E = 'big kahuna burger',
C = likes,
D = a ;
A = D, D = every,
B = 'big kahuna burger',
C = likes,
E = criminal ;
A = D, D = every,
B = E, E = 'big kahuna burger',
C = likes.

Todo: 

EXERCISE 2.4:


