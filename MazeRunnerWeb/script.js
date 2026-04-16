let maze = [
    ['S', '.', '.', '#', '.', '.'],
    ['#', '#', '.', '#', '.', '#'],
    ['.', '.', '.', '.', '.', '.'],
    ['.', '#', '#', '#', '.', '.'],
    ['.', '.', '.', '#', '.', 'E']
];

let playerX = 0, playerY = 0;
let moves = 0;

function draw() {
    const mazeDiv = document.getElementById("maze");
    mazeDiv.innerHTML = "";

    for (let i = 0; i < maze.length; i++) {
        for (let j = 0; j < maze[0].length; j++) {
            let cell = document.createElement("div");
            cell.classList.add("cell");

            if (i === playerX && j === playerY) {
                cell.classList.add("player");
            } else if (maze[i][j] === '#') {
                cell.classList.add("wall");
            } else if (maze[i][j] === 'E') {
                cell.classList.add("exit");
            } else {
                cell.classList.add("path");
            }

            mazeDiv.appendChild(cell);
        }
    }

    document.getElementById("moves").innerText = "Moves: " + moves;
}

function isValid(x, y) {
    return x >= 0 && x < maze.length &&
           y >= 0 && y < maze[0].length &&
           maze[x][y] !== '#';
}

document.addEventListener("keydown", (e) => {
    let newX = playerX;
    let newY = playerY;

    if (e.key === 'w') newX--;
    if (e.key === 's') newX++;
    if (e.key === 'a') newY--;
    if (e.key === 'd') newY++;

    if (isValid(newX, newY)) {
        playerX = newX;
        playerY = newY;
        moves++;
    }

    if (maze[playerX][playerY] === 'E') {
        alert("🎉 You Win!");
    }

    draw();
});

draw();