const printPattern = (len: number): void => {
    for (let i = 1; i <= len; i++) {
        let pa: string = "";
        for (let j = 1; j <= i; j++) {
            pa += "#";
        }
        console.log(pa);
    }
}

printPattern(7);
