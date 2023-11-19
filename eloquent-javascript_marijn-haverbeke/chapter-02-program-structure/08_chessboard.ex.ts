let chessboard = "";
const commonPart = "# # # #";

for (let i = 0; i < 8; i++) {
    if (i % 2 == 0) {
        chessboard += " " + commonPart + "\n";
    }
    else {
        chessboard += commonPart + " \n";
    }
}

console.log(chessboard);
