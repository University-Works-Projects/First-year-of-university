data F = X | Plus F F | Mult F F deriving Show

size X = 1
size (Plus f1 f2) = size f1 + size f2
size (Mult f1 f2) = size f1 + size f2
