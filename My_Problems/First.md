There's a Grid(G) of size N X M. Rows are numbered from 1 to N from top to bottom & Columns are numbered from 1 to M from Left to Right. Grid may have three types of things -> 
1) G{i, j} = '.' (Empty Cell)
2) G{i, j} = '#' (Wall)
3) G{i, j} = 'c' (Candy)
You will start your journey From Cell (1, 1). In one operation, you can move Left, Right, Up, Down. If you are out of the grid after performing a operation, you will stop. You are not allowed to visit the same cell you have earlier visited. And also you can't paas any wall. At some cells of the grid, there maybe a candy.
Now you need to tell the maximum number of candies you can get if you follow the above rules.

Constraints:
* 1 <= N, M <= 500
* G{i, j} = '.' or G{i, j} = '#' or G{i, j} = 'c' (1 <= i <= N, 1 <= j <= M)
* G{1, 1} = '.'

Input:
N  M
G{1, 1} ... G{1, M}
.
.
.
G{N, 1} ... G{N, M}

Output:
Print the answer.

